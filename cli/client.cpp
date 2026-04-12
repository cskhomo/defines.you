#include <iostream>
#include "libs/argh.h"

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
    cout << "print help (missing args)" << endl;
    return 1;
  }
  
  string term;
  
  if (redefine){
    term = cmdl[1] + " -r";
  }
  
  if (not cmdl[2].empty()) {
    cout << "print help (extra args)" << endl;
    return 1;
  }
  
  if (term.empty()) {
    term = cmdl[1];
  }
  
  cout << "\n" << term << endl;
  for (int i =0; i < term.size(); i++){
    cout << "-";
  }
  cout << "\nThe definition of the term: " << term << endl;
  cout << "\nExample:\n a usage example of the term: " << term << "\n" << endl;
  
  return 0;
}
