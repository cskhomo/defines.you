#pragma once
#include <string>
#include <utility>
#include "../libs/sqlite3.h"

using namespace std;

pair<string, string> db_lookup(sqlite3* db, sqlite3_stmt* stmt, const string& term);