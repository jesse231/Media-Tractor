#include "database/DatabaseManager.hpp"
#include "daos/MediaDAO.hpp"
#include <iostream>

int main() {
    try {
        // DatabaseManager dbManager("./generated/media-tractor.db");

        // dbManager.initializeSchema();

        // MediaDAO dao(dbManager);

        Media media(1, 1, std::nullopt, WatchStatus::Completed, MediaType::Book, {"Too much romance", "Not enough action"});

        std::cout << media.toString() << std::endl;

        // dao.insertMedia(media);

        //dao.getMediaById();
        
        // dao.updateMedia(1, true);

    } catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}