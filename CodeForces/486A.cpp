#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  if( n & 1 ){
    n ++;
    n *= -1;
  }
  cout << (n >> 1) << '\n';
  return 0;
}
