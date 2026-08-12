#pragma once

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

namespace database {

class DatabaseManager {
public:
    explicit DatabaseManager(const std::string& dbPath);

    // Delete copy constructor and assignment operator to prevent copies of the DB connection
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    // Provides access to the underlying SQLite database connection.
    SQLite::Database& getDb();

    void initializeSchema();

private:
    SQLite::Database m_db;
};

}