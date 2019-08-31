#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n;
  cin >> n;
  cout << max( n, max( n / 10, n % 10 + n / 100 * 10 ) ) << endl;
  return 0;
}
