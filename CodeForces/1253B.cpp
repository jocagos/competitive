#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000100, A = 0, B = 1, C = 2;
vector<int> a( MAXN ), ans;
set<int> found;
int employees[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  long long su {};
  for( int i = 0; i < n; ++ i ){
    int tmp {};
    cin >> tmp;
    int emp = abs( tmp );
    found.emplace( emp );
    if( tmp > 0 ){
      if( employees[emp] != A ){
	cout << "-1\n";
	exit(0);
      }
      employees[emp] = B;
      ++ su;
    }
    else{
      if( employees[emp] != B ){
	cout << "-1\n";
	exit(0);
      }
      employees[emp] = C;
      -- su;
    }
    if( not su ){
      ans.emplace_back( found.size() );
      for( int x : found ) employees[x] = A;
      found.clear();
    }
  }
  if( not found.empty() ){
    cout << "-1\n";
    exit(0);
  }
  cout << ans.size() << '\n';
  for( unsigned i = 0; i < ans.size(); ++ i )
    cout << 2 * ans[i] << ( i + 1 == ans.size() ? "\n" : " " );
  return 0;
}
