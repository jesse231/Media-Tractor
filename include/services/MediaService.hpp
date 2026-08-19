#pragma once

#include "models/Media.hpp"
#include "daos/MediaDAO.hpp"
#include <vector>
#include <optional>
#include <string>

class MediaService {
public:
    explicit MediaService(MediaDAO& mediaDao);

    int addMedia(const Media& media);

    std::optional<Media> getMedia(int id);

    std::vector<Media> getAllMedia();

private:
    MediaDAO& m_mediaDao;
    
    void validateMedia(const Media& media) const;
};