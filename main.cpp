#include <stdio.h>
#include <iostream>
extern int yyparse();
using namespace std;

int main(int argc, char **argv)
{
  cout << "hasi da..." << endl << endl ;
  if (yyparse() == 0) { 
    cout << "ONDO bukatu da..." << endl << endl ;
  }
  else {
    cout << "GAIZKI bukatu da..." << endl << endl ;
  }
  return 0;
}
