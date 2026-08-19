#pragma once

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

class DatabaseManager {
public:
    explicit DatabaseManager(const std::string& dbPath);

    // Delete copy constructor and assignment operator to prevent copies of the DB connection
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    SQLite::Database& getDb();

    void initializeSchema();

private:
    SQLite::Database m_db;
};