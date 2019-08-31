#include <iostream>
#include <cstdio>
#include <map>
#include <utility>

using namespace std;

int main(){
  int t;
  scanf("%d", &t); // leer casos
  string line;
  getline( cin, line ); // Lee el espacio sobrante de los casos
  getline( cin, line ); // Lee la siguiente línea blanca
  while( t -- ){
    map<string, int> species;
    int total = 0;
    while( getline( cin, line ) ){
      if( line[line.length()-1] == '\r' ) line = line.substr(0, line.length()-1);
      if( line == "" or line == "\r" ) break;
      species[line]++;
      total++;
    }
    for( auto& TREE : species ){ // TREE = pair<string, int> => TREE.first = string, TREE.second = int;
      cout << TREE.first << " ";
      printf("%.4f\n", 1.0 * TREE.second / total * 100 );
    }
    if( t ) printf("\n");
  }
  return 0;
}
