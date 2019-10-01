#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000;
int n {}, m {};
string words[MAXN] {}, rule {};
void solve( string builder, int idx = 0 ){
  if( idx < rule.length() ){
    if( rule[idx] == '0' ){
      for( char c = '0'; c <= '9'; ++ c )
	solve( builder + c, idx + 1 );
    }
    else if( rule[idx] == '#' ){
      for( int i = 0; i < n; ++ i )
	solve( builder + words[i], idx + 1 );
    }
  }
  else{
    // cerr << "BUILDER IS >" << builder << "<\nINDEX IS >" << idx << "<\n";
    cout << builder << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  while( getline( cin, line ) ){
    cout << "--\n";
    n = stoi( line );
    for( int i = 0; i < n; ++ i )
      getline( cin, words[i] );
    getline( cin, line );
    m = stoi( line );
    for( int i = 0; i < m; ++ i ){
      getline( cin, rule );
      // cout << "USING RULE >" << rule << "<:" << endl;
      string tmp;
      solve( tmp );
    }
  }
  return 0;
}
