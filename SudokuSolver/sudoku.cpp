// calebsSudokuThing
#include <iostream>
#include <string>
#include "SudokuSolver.h"
using namespace std;

int main(){
  string s;
  while(cin >> s){
    SudokuSolver g(s, cout);
    g.solve();
    g.print();
    //cout << flush;
  }
}