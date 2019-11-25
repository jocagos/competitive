#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, c {}, s {};
  cin >> n >> c >> s;
  s --;
  vector<int> cnt( n, 0 );
  cnt[0] = 1;
  int idx = 0;
  for( int i = 0; i < c; ++ i ){
    int tmp;
    cin >> tmp;
    idx = (idx + n + tmp) % n;
    cnt[idx] ++;
  }
  cout << cnt[s] << endl;
  return 0;
}
