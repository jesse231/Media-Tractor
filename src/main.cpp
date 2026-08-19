#include "database/DatabaseManager.hpp"
#include "daos/MediaDAO.hpp"
#include "services/MediaService.hpp"
#include "api/MediaController.hpp"
#include <thread>
#include <crow.h>
#include <iostream>

int main() {
    try {
        DatabaseManager dbManager("./generated/media-tractor.db");
        dbManager.initializeSchema();
        
        MediaDAO mediaDao(dbManager);
        MediaService mediaService(mediaDao);
        
        crow::SimpleApp app;
        MediaController mediaController(mediaService);

        mediaController.registerRoutes(app);

        std::cout << "Starting optimized Crow server on port 8080..." << std::endl;
        app.port(8080).multithreaded().run();
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}