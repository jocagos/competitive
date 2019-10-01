#include <bits/stdc++.h>

using namespace std;

int main(){
  int mod {}, tmp {};
  string s;
  cin >> s;
  if( s.length() > 2 )
    tmp = stoi( s.substr( s.length() - 2 ) );
  else
    tmp = stoi( s );
  if( tmp % 4 ) cout << 0 << endl;
  else cout << 4 << endl;
  return 0;
}
