#include "database/DatabaseManager.hpp"
#include <iostream>

DatabaseManager::DatabaseManager(const std::string& dbPath)
    : m_db(dbPath, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) 
{
    try {
        m_db.exec("PRAGMA journal_mode = WAL;");
    } catch (const SQLite::Exception& e) {
        std::cerr << "SQLite initialization error: " << e.what() << std::endl;
        throw; 
    }
}

SQLite::Database& DatabaseManager::getDb() {
    return m_db;
}

void DatabaseManager::initializeSchema() {
    try {
        const char* createMediaTable = R"(
            CREATE TABLE IF NOT EXISTS media (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                mid INTEGER NOT NULL,
                rating INTEGER,
                status TEXT NOT NULL,
                type TEXT NOT NULL, 
                tags JSON NOT NULL
            );
        )";

        m_db.exec(createMediaTable);
        
        std::cout << "Database schema initialized successfully." << std::endl;
    } catch (const SQLite::Exception& e) {
        std::cerr << "Failed to initialize database schema: " << e.what() << std::endl;
        throw; 
    }
}