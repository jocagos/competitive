#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  while( getline( cin, line ) ){
    int cnt[256] {}, mx {};
    for( int i = 0; i < (int)line.length(); ++ i )
      if( ('A' <= line[i] and line[i] <= 'Z') or
	  ('a' <= line[i] and line[i] <= 'z') ){
	++ cnt[line[i]];
	if( cnt[line[i]] > mx )
	  mx = cnt[line[i]];
      }
    for( char i = 'A'; i <= 'Z'; ++ i )
      if( cnt[i] == mx )
	cout << (char)(i);
    for( char i = 'a'; i <= 'z'; ++ i )
      if( cnt[i] == mx )
	cout << (char)(i);
    cout << ' ' << mx << '\n';
  }
  return 0;
}
