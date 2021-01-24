#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
constexpr int MAX_CARD = 60;
string card {}, word {};
bool used[MAX_CARD] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    for( int i = 0; i < MAX_CARD; ++ i )
      used[i] = false;
    vector<string> pos( n );
    int curr_pos {-1};
    for( int i = 0; i < n; ++ i ){
      cin >> card >> word;
      int len = word.length();
      while( len ){
	curr_pos = (curr_pos + 1) % n;
	if( not used[curr_pos] )
	  -- len;
      }
      pos[curr_pos] = card;
      used[curr_pos] = true;
    }
    for( int i = 0; i < n; ++ i )
      cout << pos[i] << ( i + 1 == n ? '\n' : ' ' );
  }
  return 0;
}
