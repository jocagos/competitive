#include <iostream>
#include <string>

using namespace std;

bool is_theorem( string& s ){
  int q[4] {}, ms {}, es {}, mi {}, ei {}, len = s.length();
  for( int i = 0; i < (int)s.length(); ++ i ){
    char c = s[i];
    if( c == '?' ) ++ q[0];
    if( c == 'M' ){
      mi = i;
      ++ ms;
    }
    if( c == 'E' ){
      ei = i;
      ++ es;
    }
  }
  if( q[0] + ms + es != len or ms != 1 or es != 1 or q[0] < 4 )
    return false;
  if( mi <= 0 or ei <= mi + 1 or ei >= len - 2 )
    return false;
  for( int i = 0; i < mi; ++ i )
    if( s[i] == '?' )
      ++ q[1];
  for( int i = mi; i < ei; ++ i )
    if( s[i] == '?' )
      ++ q[2];
  for( int i = ei; i < len; ++ i )
    if( s[i] == '?' )
      ++ q[3];
  if( q[1] > 0 and q[2] > 0 and q[3] > 1 and q[3] - q[1] == q[2] )
    return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string str {};
  cin >> n;
  for( int i = 0; i < n; ++ i ){
    cin >> str;
    cout << ( is_theorem( str ) ? "" : "no-" ) << "theorem\n";
  }
  return 0;
}
