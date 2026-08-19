#include "services/MediaService.hpp"
#include <stdexcept>

MediaService::MediaService(MediaDAO& mediaDao)
    : m_mediaDao(mediaDao) {}

int MediaService::addMedia(const Media& media) {
    validateMedia(media); // does nothing right now

    return m_mediaDao.insertMedia(media);
}

std::optional<Media> MediaService::getMedia(int id) {
    return m_mediaDao.getMediaById(id);
}

std::vector<Media> MediaService::getAllMedia() {
    return m_mediaDao.getAllMedia();
}

// TODO: figure out contraints on our Media objects
void MediaService::validateMedia(const Media& media) const {
    return;
}