#include <bits/stdc++.h>

using namespace std;
map<long long, vector<long long>> memo;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n;
  cin >> t;
  while( t -- ){
    cin >> n;
    if( memo[n].size() )
      for( int i = 0; i < (int)memo[n].size(); ++ i )
	cout << memo[n][i] << ( i + 1 == (int)memo[n].size() ? "\n" : " ");
    else{
      stack<long long> st;
      for( long long i = 1; i * i <= n; ++ i ){
	if( n % i == 0 ){
	  cout << i << " ";
	  memo[n].push_back( i );
	  st.push( n / i );
	}
      }
      while( not st.empty() ){
	cout << st.top();
	memo[n].push_back( st.top() );
	st.pop();
	if( not st.empty() ) cout << " ";
	else cout << "\n";
      }
    }
  }
  return 0;
}
