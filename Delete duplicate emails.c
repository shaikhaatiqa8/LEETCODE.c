#include <stdio.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **colName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = 0;

    // Open a temporary in-memory database
    if (sqlite3_open(":memory:", &db)) {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create table
    char *sql =
        "CREATE TABLE Person (id INT, email TEXT);"
        "INSERT INTO Person VALUES (1, 'john@example.com');"
        "INSERT INTO Person VALUES (2, 'bob@example.com');"
        "INSERT INTO Person VALUES (3, 'john@example.com');";

    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    // Delete duplicate emails keeping smallest ID
    char *delete*
