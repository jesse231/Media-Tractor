#pragma once

#include "services/MediaService.hpp"
#include <thread>
#include <crow.h>
#include <glaze/glaze.hpp>

class MediaController {
public:
    MediaController(MediaService& mediaService);

    void registerRoutes(crow::SimpleApp& app);

private:
    MediaService& m_mediaService;
};