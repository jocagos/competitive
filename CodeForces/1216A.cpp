#include <bits/stdc++.h>

using namespace std;

int main(){
  string s {};
  int n {};
  getline( cin, s );
  n = stoi( s );
  cin >> s;
  int c {};
  for( int i = 0; i < s.length(); i += 2 ){
    if( s[i] == s[i + 1] ){
      ++ c;
      if( s[i] == 'a' ) s[i] ++;
      else s[i] --;
    }
  }
  cout << c << endl << s << endl;
  return 0;
}
