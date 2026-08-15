#include "daos/MediaDAO.hpp"
#include "models/Enums.hpp"
#include <SQLiteCpp/SQLiteCpp.h>
#include <stdexcept>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

MediaDAO::MediaDAO(DatabaseManager& dbManager)
    : m_dbManager(dbManager) {}

int MediaDAO::insertMedia(const Media& media) {
    SQLite::Statement query(m_dbManager.getDb(), 
        "INSERT INTO media (mid, rating, status, type, tags) VALUES (?, ?, ?, ?, ?)");

    query.bind(1, media.mid);
    query.bind(3, EnumHelpers::watchStatusToString(media.status));
    query.bind(4, EnumHelpers::mediaTypeToString(media.type));
    query.bind(5, ((json) media.tags).dump());
    
    // Handle optional fields
    if (media.rating.has_value()) {
        query.bind(2, media.rating.value());
    } else {
        query.bind(2);
    }

    query.exec();

    return static_cast<int>(m_dbManager.getDb().getLastInsertRowid());
}

int MediaDAO::updateMedia(int id, std::optional<bool> rating) {
    SQLite::Statement query(m_dbManager.getDb(), "UPDATE media SET rating = ? WHERE id = ?");
    if (rating.has_value()) {
        query.bind(1, rating.value());
    } else {
        query.bind(1);
    }
    query.bind(2, id);
    return 0;
}

int MediaDAO::updateMedia(int id, WatchStatus status) {
    SQLite::Statement query(m_dbManager.getDb(), "UPDATE media SET status = ? WHERE id = ?");
    query.bind(1, EnumHelpers::watchStatusToString(status));
    query.bind(2, id);
    return 0;
}

int MediaDAO::updateMedia(int id, std::vector<std::string> tags) {
    SQLite::Statement query(m_dbManager.getDb(), "UPDATE media SET tags = ? WHERE id = ?");
    query.bind(1, ((json) tags).dump());
    query.bind(2, id);
    return 0;
}

std::optional<Media> MediaDAO::getMediaById(int id) {
    SQLite::Statement query(m_dbManager.getDb(), "SELECT * FROM media WHERE id = ?");
    query.bind(1, id);

    if (query.executeStep()) {
        int mediaId = query.getColumn(0).getInt();
        int mid = query.getColumn(1).getInt();
        std::optional<bool> rating = query.getColumn(2).getInt();
        WatchStatus status = EnumHelpers::stringToWatchStatus(query.getColumn(3).getString()).value();
        MediaType media_type = EnumHelpers::stringToMediaType(query.getColumn(4).getString()).value();
        std::vector tags = ((json) query.getColumn(5).getString()).get<std::vector<std::string>>();

        return Media(mediaId, mid, rating, status, media_type, tags);
    }

    return std::nullopt;
}

std::vector<Media> MediaDAO::getAllMedia() {
    std::vector<Media> results;
    SQLite::Statement query(m_dbManager.getDb(), "SELECT * FROM media");

    if (query.executeStep()) {
        int mediaId = query.getColumn(0).getInt();
        int mid = query.getColumn(1).getInt();
        std::optional<bool> rating = query.getColumn(2).getInt();
        WatchStatus status = EnumHelpers::stringToWatchStatus(query.getColumn(3).getString()).value();
        MediaType media_type = EnumHelpers::stringToMediaType(query.getColumn(4).getString()).value();
        std::vector tags = ((json) query.getColumn(5).getString()).get<std::vector<std::string>>();
        
        results.push_back(Media(mediaId, mid, rating, status, media_type, tags));
    }

    return results;
}