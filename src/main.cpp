#include <iostream>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

int main() {
    try {
        // 1. Open the database
        // RAII means the database is automatically closed when 'db' goes out of scope!
        SQLite::Database db("mediatractor.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        std::cout << "Opened database successfully.\n";

        // 2. Create the table using .exec()
        db.exec("CREATE TABLE IF NOT EXISTS Shows ("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                "Title TEXT NOT NULL, "
                "Status BOOLEAN NOT NULL);");

        // 3. Prepare an INSERT statement
        std::string title = "Severance";
        bool status = true;
        
        SQLite::Statement query(db, "INSERT INTO Shows (Title, Status) VALUES (?, ?)");
        
        // 4. Bind variables
        query.bind(1, title);
        query.bind(2, status);
        
        // 5. Execute the query
        query.exec();
        
        std::cout << "Show added successfully!\n";
        
        // No sqlite3_finalize() needed! The 'query' object cleans itself up.

    } catch (const std::exception& e) {
        // SQLiteCpp throws standard C++ exceptions on errors
        std::cerr << "Database Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}