#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 200200;
int n {}, m {};
vector<int> a( MAXN );
vector<int> buckets( MAXN, 0 );

void bucket_sort(){
  for( int i = 0; i < n; ++ i )
    buckets[a[i]] ++;
  int j = 0;
  for( int i = 0; i < MAXN; ++ i )
    while( buckets[i] -- )
      a[j ++] = i;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for( int i = 0; i < n; ++ i )
    cin >> a[i];
  bucket_sort();
  // for( int i = 0; i < n; ++ i )
  //   cerr << a[i] << " ";
  // cerr << endl;
  vector<long long> ans( a.begin(), a.begin() + n );
  long long su {};
  for( int i = 0; i < n; ++ i ){
    su += a[i];
    ans[i] = su;
    if( i >= m )
      ans[i] += ans[i - m];
    cout << ans[i] << ( i + 1 == n ? "\n" : " ");
  }
  return 0;
}
