#include <iostream>
#include "libs/argh.h"

using namespace std;
using namespace argh;

int main(int argc, char* argv[]){
  
  parser cmdl(argv);
  
  bool help = cmdl[{"h", "help"}];
  bool redefine = cmdl[{"r", "redefine"}];
  
  if (help){
    cout << "USAGE: define <term>\n\n"
    
         << "EXAMPLES:\n"
         << "\u3000define 'recursion'\n"
         << "\u3000define 'call stack'\n\n"
         
         << "OPTIONS:\n"
         << "\u3000-h, --help\tShow this help message\n";
    return 1;
  }
  
  if (cmdl[1].empty()){
    cout << "ERROR:\tmissing argument\n"
         << "USAGE:\tdefine <term>\n"
         << "HINT:\ttry define --help\n";
  return 1;
}
  
  string term;
  
  if (redefine){
    term = cmdl[1] + " -r";
  }
  
  if (not cmdl[2].empty()) {
    cout << "ERROR:\ttoo many arguments\n"
         << "USAGE:\tdefine <term>\n"
         << "HINT:\tadd quotation marks\n";
  return 1;
}
  
  if (term.empty()) {
    term = cmdl[1];
  }
  
  cout << term << endl;
  for (int i =0; i < term.size(); i++){
    cout << "-";
  }
  
  cout << "\nThe definition of the term: " << term << endl;
  cout << "\nExample:\n\u3000a usage example of the term: " << term << endl;
  
  return 0;
}
