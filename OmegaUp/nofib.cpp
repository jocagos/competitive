#include <iostream>

using namespace std;
constexpr int MAXN = 30030;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int vals[MAXN] {}, fibo[MAXN] {};
  cin >> n;
  fibo[1] = 1;
  vals[0] = vals[1] = 1;
  for( int i = 2; i <= n; ++ i ){
    fibo[i] = fibo[i - 1] + fibo[i - 2];
    if( fibo[i] > MAXN )
      break;
    vals[fibo[i]] ++;
  }
  for( int i = 1; i < n; ++ i ){
    if( not vals[i] )
      cout << i << " ";
  }
  cout << '\n';
  return 0;
}
