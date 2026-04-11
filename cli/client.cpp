#include <iostream>
#include "argh.h"

using namespace std;
using namespace argh;

int main(int argc, char* argv[]){
  
  parser cmdl(argv);
  
  if (not (argc-1) ){
    cout << "print help" << endl;
    return 1;
  }
  
  string term;
  
  if (cmdl[{"r", "redefine"}]){
    
    try {
      term = argv[2];
    }
    
    catch (exception e){
      cout << "error";
      return 1;
    }
  }
  
  if (not cmdl[2].empty()) {
    cout << "print help" << endl;
    return 1;
  }
  
  term = cmdl[1];
  cout << "send request: " << term << endl;
  return 0;
}
