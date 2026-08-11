#pragma once

#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

class DatabaseService {
private:
    SQLite::Database db;

public:
    // Constructor declaration
    explicit DatabaseService(const std::string& dbPath);

    // API Add show to database
    void addUser(const std::string& showName, const bool isWatching);
};