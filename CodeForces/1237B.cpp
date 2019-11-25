#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  vector<int> a( n ), b( n ), c( n ), pos( n );
  for( int i = 0; i < n; ++ i ) cin >> a[i];
  for( int i = 0; i < n; ++ i ) cin >> b[i];
  for( int i = 0; i < n; ++ i ) pos[b[i] - 1] = i;
  for( int i = 0; i < n; ++ i ) c[i] = pos[a[i] - 1];
  int mx {-1}, ans {};
  for( int i = 0; i < n; ++ i ){
    if( c[i] > mx ) mx = c[i];
    else ans++;
  }
  cout << ans << endl;
  return 0;
}
