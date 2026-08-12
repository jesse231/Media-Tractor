#include "database/DatabaseManager.hpp"
#include <iostream>

int main() {
    try {
        database::DatabaseManager dbManager("./generated/media-tractor.db");
        
        dbManager.initializeSchema();
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}