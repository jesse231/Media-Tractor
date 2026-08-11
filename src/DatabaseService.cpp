#include "DatabaseService.hpp"
#include <iostream>

DatabaseService::DatabaseService(const std::string& dbPath) 
    : db(dbPath, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) 
{
    // Apply backend-specific pragmas
    db.exec("PRAGMA journal_mode=WAL;");
    db.exec("PRAGMA foreign_keys=ON;");
    db.setBusyTimeout(5000); 

    // Initialize schema
    db.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT UNIQUE, isWatching BOOLEAN)");
}

void DatabaseService::addUser(const std::string& username, const bool isWatching) {
    // Compile statement and execute
    SQLite::Statement query(db, "INSERT INTO users (username) VALUES (?)");
    query.bind(1, username);
    query.bind(2, isWatching);
    query.exec();
}