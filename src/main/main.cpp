#include <iostream>
#include "libs/argh.h"
#include "libs/sqlite3.h"

using namespace std;
using namespace argh;

string parse_args(parser& cmdl);
pair<string, string> db_lookup(sqlite3* db, sqlite3_stmt* stmt, const string& term);
void render_output(const string& term, const string& definition, const string& example);

int main(int argc, char* argv[]) {

  parser cmdl(argv);
  string term = parse_args(cmdl);

  sqlite3* db = nullptr;  
  sqlite3_stmt* stmt = nullptr;
  auto [definition, example] = db_lookup(db, stmt, term);

  render_output(term, definition, example);
  return 0;
}

string parse_args(parser& cmdl) {

  bool help = cmdl[{"h", "help"}];
  bool redefine = cmdl[{"r", "redefine"}];

  if (help) {
    cout << "USAGE: define <term>\n\n"
         << "EXAMPLES:\n"
         << "\u3000define 'recursion'\n"
         << "\u3000define 'call stack'\n\n"
         << "OPTIONS:\n"
         << "\u3000-h, --help\tShow this help message\n";
    exit(1);
  }

  if (cmdl[1].empty()) {
    cout << "ERROR:\tmissing argument\n"
         << "USAGE:\tdefine <term>\n"
         << "HINT:\ttry define --help\n";
    exit(1);
  }

  if (not cmdl[2].empty()) {
    cout << "ERROR:\ttoo many arguments\n"
         << "USAGE:\tdefine <term>\n"
         << "HINT:\tadd quotation marks\n";
    exit(1);
  }

  string term = cmdl[1];

  if (redefine) {
    term = cmdl[1] + " -r";
  }

  return term;
}

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

void render_output(const string& term, const string& definition, const string& example) {

  cout << term << endl;

  for (int i = 0; i < term.size(); i++) {
    cout << "-";
  }

  cout << "\n" << definition << endl;
  cout << "\nExample:\n\u3000" << example << endl;
}