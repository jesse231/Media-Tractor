#pragma once

#include "models/Media.hpp"
#include "database/DatabaseManager.hpp"
#include <vector>
#include <optional>

class MediaDAO {
public:
    explicit MediaDAO(DatabaseManager& dbManager);

    int insertMedia(const Media& media);

    int updateMedia(int id, std::optional<bool> rating);

    int updateMedia(int id, WatchStatus status);

    int updateMedia(int id, std::vector<std::string> tags);

    std::optional<Media> getMediaById(int id);

    std::vector<Media> getAllMedia();

private:
    DatabaseManager& m_dbManager;
};