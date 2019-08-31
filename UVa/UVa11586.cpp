#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
  int t;
  scanf("%d ", &t);
  while( 1 ){
    int m = 0, f = 0;
    string line;
    getline(cin, line);
    if(line.empty())break;
    istringstream iss(line);
    line.clear();
    while( iss >> line ){
      for( int i = 0; i < line.length(); ++i ){
	if( line[i] == 'M' ) m++;
	else if(line[i] == 'F' ) f++;
      }
    }
    if( m == f && m != 1 ) cout << "LOOP" << endl;
    else cout << "NO LOOP" << endl;
  }
  return 0;
}
