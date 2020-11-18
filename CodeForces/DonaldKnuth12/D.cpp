#include <iostream>
#include <cmath>

constexpr long long MOD = 10e9 + 7;

using namespace std;

int main(){
  long long n {};
  cin >> n;
  long long sum {};
  long long curr_val = 1;
  long long curr_mult = 2;
  while( n > 0 ){
    if( n >= curr_mult )
      sum += curr_mult * curr_val;
    else
      sum += n * curr_val;
    n -= curr_mult;
    curr_val ++;
    curr_mult += 2;
    sum %= MOD;
  }
  cout << sum << endl;
  return 0;
}
