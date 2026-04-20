#include <iostream>
#include "sql.h"

using namespace std;

pair<string, string> db_lookup(sqlite3* db, sqlite3_stmt* stmt, const string& term) {
  
  const unsigned char* definition = nullptr;
  const unsigned char* example = nullptr;

  if (sqlite3_open("../data/dictionary.db", &db) != SQLITE_OK) {
    cerr << "Failed to open DB\n";
    return {"Definition not found.", "Example not found."};
  }

  const char* sql = "SELECT definition, example FROM terms WHERE term = ?;";

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
    cerr << "Failed to prepare query\n";
    sqlite3_close(db);
    return {"Definition not found.", "Example not found."};
  }

  sqlite3_bind_text(stmt, 1, term.c_str(), -1, SQLITE_STATIC);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    definition = sqlite3_column_text(stmt, 0);
    example = sqlite3_column_text(stmt, 1);
  }

  string def_str = definition ? reinterpret_cast<const char*>(definition) : "Definition not found.";
  string ex_str = example ? reinterpret_cast<const char*>(example) : "Example not found.";

  return {def_str, ex_str};
}