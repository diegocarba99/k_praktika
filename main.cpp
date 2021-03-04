#include <stdio.h>
#include <iostream>
extern int yyparse();
using namespace std;

int main(int argc, char **argv)
{
  cout << "INFO: Analisi lexiko hasieratzen..." << endl ;
  if (yyparse() == 0) { 
    cout << "Emaitza: ONDO" << endl << endl ;
  }
  else {
    cout << "Emaitza: GAIZKI" << endl << endl ;
  }
  return 0;
}
