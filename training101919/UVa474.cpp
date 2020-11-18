#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000100;

long double EXP[MAXN] {}, COEFF[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  EXP[0] = 0;
  COEFF[0] = 1;
  for( int i = 1; i < MAXN; ++ i ){
    COEFF[i] = COEFF[i - 1] / 2;
    EXP[i] = EXP[i - 1];
    if( COEFF[i] < 1.0 ){
      COEFF[i] *= 10;
      EXP[i] ++;
    }
  }
  int n {};
  while( cin >> n )
    cout << "2^" << -n << " = " << setprecision(3) << fixed << COEFF[n] << "e" << setprecision(0) << fixed << -EXP[n] << '\n';
  return 0;
}
