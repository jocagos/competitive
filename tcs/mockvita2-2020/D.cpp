#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

long double LX, LY, WX, WY, F;

inline long double calculate( long double i ){
  return sqrt((LX - i) * (LX - i) + LY * LY) / F + sqrt((WX - i) * (WX - i) + WY * WY);
}

long double search( long double S, long double E ){
  long double M, curr, prev, next;
  long double ans = -1;
  while( true ){
    M = (S + E) / 2;
    prev = calculate( M - 0.000001L );
    curr = calculate( M );
    next = calculate( M + 0.000001L );
    if( prev > curr and next > curr ){
      ans = M;
      break;
    }
    else if( prev > curr ){
      S = M + 0.000001L;
    }
    else{
      E = M - 0.000001L;
    }
  }
  return ans;
}

int main(){  
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  // cin >> LX >> LY >> WX >> WY >> F;
  scanf("%Lf %Lf %Lf %Lf %Lf", &LX, &LY, &WX, &WY, &F );
  long double count;
  if( LX > WX ){
    count = search( WX, LX );
  }
  else{
    count = search( LX, WX );
  }
  printf("%.6Lf\n", count);
  // cout << setprecision( 6 ) << fixed << R << '\n';
  return 0;
}
