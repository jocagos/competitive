#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll gauss( ll n ){
  return (n + 1LL) * n / 2;
}

ll sum_to( ll n, int need ){
  ll pw{1}, sum{}, add{};
  for( int len = 1; ; ++ len ){
    if( pw * 10 - 1 < n ){
      ll cnt = pw * 10 - pw;
      if( need ){
	sum += add * cnt + gauss( cnt ) * len;
	add += cnt * len;
      }
      else sum += cnt * len;
    }
    else{
      ll cnt = n - pw + 1;
      if( need ) sum += add * cnt + gauss( cnt ) * len;
      else sum += cnt * len;
      break;
    }
    pw *= 10;
  }
  return sum;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q {};
  cin >> q;
  while( q -- ){
    ll k {};
    cin >> k;
    -- k;
    ll L = 1, R = 1e9, res = -1;
    while( R - L >= 0 ){
      ll mid = (R + L) >> 1;
      if( sum_to( mid, 1 ) > k ){
	res = mid;
	R = mid - 1;
      }
      else L = mid + 1;
    }
    k -= sum_to( res - 1, 1 );
    L = 1, R = res;
    ll num = -1;
    while( R - L >= 0 ){
      int mid = (R + L) >> 1;
      if( sum_to( mid, 0 ) > k ){
	num = mid;
	R = mid - 1;
      }
      else L = mid + 1;
    }
    cout << to_string( num )[k - sum_to( num - 1, 0 )] << endl;
  }
  return 0;
}
