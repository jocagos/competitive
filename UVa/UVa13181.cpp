#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
constexpr int MAXN = 500500;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string in {};
  int my_max {};
  int tc {};
  while( cin >> in ){
    my_max = 0;
    int F {}, L = {};
    for( F = 0; F < (int)in.length(); ++ F )
      if( in[F] == 'X' )
	break;
    for( L = (int)in.length() - 1; L >= 0; -- L )
      if( in[L] == 'X' )
	break;
    
    my_max = max( my_max, F - 1 );
    my_max = max( my_max, (int)(in.length()) - (L + 1) - 1 );
    // cerr << "CASE " << ++ tc << ":\n";
    for( int curr_pos = F + 1; curr_pos <= L; ++ curr_pos ){
      if( in[curr_pos] == 'X' ){ // reset distance
	// cerr << "curr_pos: " << curr_pos << endl;
	// cerr << "F: " << F << endl;
	// cerr << "my_max: " << my_max << endl;
	my_max = max( my_max, (curr_pos - (F + 1) - 1) / 2 );
	  
	F = curr_pos;
      }
    }
    cout << my_max << '\n';
  }
  return 0;
}
