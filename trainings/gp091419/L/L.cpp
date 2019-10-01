#include <iostream>

using namespace std;

inline long long f( long long n ){
  long long k = __builtin_popcountll( n );
  long long ans = 1LL << k;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n{};
  cin >> n;
  cout << f( n ) << endl;
  return 0;
}
