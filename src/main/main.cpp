#include <iostream>
#include "libs/argh.h"
#include "libs/sqlite3.h"

#include "cli/cli.h"
#include "sql/sql.h"

using namespace std;
using namespace argh;

int main(int argc, char* argv[]) {

  parser cmdl(argv);
  string term = parse_args(cmdl);

  sqlite3* db = nullptr;  
  sqlite3_stmt* stmt = nullptr;
  auto [definition, example] = db_lookup(db, stmt, term);

  render_output(term, definition, example);
  return 0;
}