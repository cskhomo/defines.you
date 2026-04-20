#include <iostream>
#include "cli.h"

using namespace std;
using namespace argh;

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

void render_output(const string& term, const string& definition, const string& example) {

  cout << term << endl;

  for (int i = 0; i < term.size(); i++) {
    cout << "-";
  }

  cout << "\n" << definition << endl;
  cout << "\nExample:\n\u3000" << example << endl;
}