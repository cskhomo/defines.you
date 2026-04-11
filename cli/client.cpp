#include <iostream>
#include "argh.h"

using namespace std;
using namespace argh;

int main(int argc, char* argv[]){
  
  parser cmdl(argv);
  
  bool help = cmdl[{"h", "help"}];
  bool redefine = cmdl[{"r", "redefine"}];
  
  if (help){
    cout << "print help (general)" << endl;
    return 1;
  }
  
  if (cmdl[1].empty()){
    cout << "print help (less)" << endl;
    return 1;
  }
  
  string term;
  
  if (redefine){
    term = cmdl[1] + " -r";
  }
  
  if (not cmdl[2].empty()) {
    cout << "print help (more)" << endl;
    return 1;
  }
  
  if (term.empty()) {
    term = cmdl[1];
  }
  
  cout << "send request: " << term << endl;
  
  return 0;
}
