#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string line {};
  getline( cin, line );
  n = stoi( line );
  unordered_map<char, char> c24{ {'V', '0'}, {'U', '1'}, {'C', '2'}, {'D', 3} };
  cout << "COWCULATIONS OUTPUT\n";
  while( n -- ){
    long long A {}, B {};
    getline( cin, line );
    string::size_type sz = 0;
    for( auto& c : line ) c = c24[c];
    string t( line.rbegin(), line.rend() );
    A = stoll( t, &sz, 4 );
    getline( cin, line );
    for( auto& c : line ) c = c24[c];
    string t2( line.rbegin(), line.rend() );
    B = stoll( t2, &sz, 4 );
    for( int i = 0; i < 3; ++ i ){
      getline( cin, line );
      if( line == "A" ) B = A + B;
      else if( line == "L" ) B /= 4;
      else if( line == "R" ) B *= 4;
    }
    getline( cin, line );
    for( auto& c : line ) c = c24[c];
    string t3( line.rbegin(), line.rend() );
    long long C = stoll( t3, &sz, 4 );
    if( B == C ) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << "END OF OUTPUT\n";
  return 0;
}
