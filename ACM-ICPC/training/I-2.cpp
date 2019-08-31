#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MAXSIZE;
bitset<2010> bs;
vector<int> primes;

void sieve( ll ub ){
  MAXSIZE = ub + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for( ll i = 2; i <= MAXSIZE; ++ i ){
    if( bs[i] ){
      for( ll j = i * i; j <= MAXSIZE; j += i ) bs[j] = 0;
      primes.emplace_back( (int) i );
    }
  }
}

bool llt( ll p ){
  ll s = 4;
  ll m = 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  while( cin >> a ){
    cin >> b;
    if( bs[a + b] ){ // probable prime, let's do the test
      // Lucas-lehmer test
      bool mprime = true;
      
    }
    else{
    }
  }
  return 0;
}
