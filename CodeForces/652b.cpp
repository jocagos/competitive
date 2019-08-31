#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v;
  int num;
  for( int i = 0; i < n; ++i ){
    cin >> num;
    v.push_back(num);
  }
  sort(begin(v), end(v));
  int i = 0, j = n-1;
  bool side = true;
  while(n--){
    if( side ) cout << v[i++];
    else cout << v[j--];
    side = !side;
    cout << (n ? " " : "\n");
  }
  cout.flush();
  return 0;
}
