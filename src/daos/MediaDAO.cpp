#include "daos/MediaDAO.hpp"
#include "models/Enums.hpp"
#include <SQLiteCpp/SQLiteCpp.h>
#include <stdexcept>
#include <vector>
#include <glaze/glaze.hpp> // Replaced nlohmann with glaze

MediaDAO::MediaDAO(DatabaseManager& dbManager)
    : m_dbManager(dbManager) {}

int MediaDAO::insertMedia(const Media& media) {
    SQLite::Statement query(m_dbManager.getDb(), 
        "INSERT INTO media (mid, rating, status, type, tags) VALUES (?, ?, ?, ?, ?)");

    query.bind(1, media.mid);
    query.bind(3, EnumHelpers::watchStatusToString(media.status));
    query.bind(4, EnumHelpers::mediaTypeToString(media.type));
    
    std::string tags_json;
    (void)glz::write_json(media.tags, tags_json);
    query.bind(5, tags_json);

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
    
    std::string tags_json;
    (void)glz::write_json(tags, tags_json);
    query.bind(1, tags_json);
    
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

        std::vector<std::string> tags;
        [[maybe_unused]] auto err = glz::read_json(tags, query.getColumn(5).getString());

        return Media{.id = mediaId, .mid = mid, .rating = rating, .status = status, .type = media_type, .tags = tags};
    }

    return std::nullopt;
}

std::vector<Media> MediaDAO::getAllMedia() {
    std::vector<Media> results;
    SQLite::Statement query(m_dbManager.getDb(), "SELECT * FROM media");

    while (query.executeStep()) {
        int mediaId = query.getColumn(0).getInt();
        int mid = query.getColumn(1).getInt();
        std::optional<bool> rating = query.getColumn(2).getInt();
        WatchStatus status = EnumHelpers::stringToWatchStatus(query.getColumn(3).getString()).value();
        MediaType media_type = EnumHelpers::stringToMediaType(query.getColumn(4).getString()).value();
        
        std::vector<std::string> tags;
        [[maybe_unused]] auto err = glz::read_json(tags, query.getColumn(5).getString());
        
        results.push_back(Media{.id = mediaId, .mid = mid, .rating = rating, .status = status, .type = media_type, .tags = tags});
    }

    return results;
}