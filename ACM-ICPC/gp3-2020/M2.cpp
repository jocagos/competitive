#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string n {};
  cin >> n;
  int digits[10] {};
  for( int i = 1; i <= 9; ++ i )
    cin >> digits[i];
  set<int> indexes;
  // cerr << "n: >" << n << "<" << endl;
  for( int d = 1; d <= 9; ++ d ){
    if( digits[d] == 0 ) continue;
    for( int i = 0; i <= n.length(); ++ i ){
      if( n[i] == '0' + d ){
	n[i] = '*';
	digits[d] --;
	indexes.emplace( i );
      }
    }
  }
  for( int i = 0; i < n.length(); ++ i ){
    if( indexes.find( i ) == indexes.end() )
      cout << n[i];	
  }
  cout << '\n';
  return 0;
}
