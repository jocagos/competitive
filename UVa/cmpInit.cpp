#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;
constexpr int MAXN = 1000002;
int n;

vector<int> memo( MAXN, -1e6 );
vector<int> sq( MAXN, 0 ), sn( MAXN, 0 ), lg( MAXN, 0 );
vector<int> sq2( MAXN, 0 ), sn2( MAXN, 0 ), lg2( MAXN, 0 );

void init2( void ){
  double lg_e = exp(1), lg_it = exp(1);
  int sq_lim = -1, sq_v = 0, sq_it = 0, lg_v = 0;
  for( int i = 0; i < MAXN; ++ i ){
    sq2[i] = i - sq_v;
    sq_it ++;
    if( sq_it >= sq_lim ){
      sq_lim += 2;
      sq_v ++;
      sq_it = 0;
    }
    sn2[i] = i * ( ( 1 - cos( i << 1 ) ) / 2 );
    if( i > 0 ){
      if( i <= lg_it ) lg2[i] = lg_v;
      else{
	lg_it *= lg_e;
	lg2[i] = ++ lg_v;
      }
    }
  }
}

void init( void ){
  for( int i = 0; i < MAXN; ++ i ){
    sq[i] = i - sqrt( i );
    sn[i] = i * sin( i ) * sin( i );
    if( i > 0 ) lg[i] = log( i );
    else lg[i] = 0;
  }
}

int f( int idx ){
  if( memo[idx] != -1e6 ) return memo[idx];
  // return (memo[idx] = (sq[idx] + lg[idx] + sn[idx]) % 1000000);
  return (memo[idx] = ( f( sq[idx] ) + f( lg[idx] ) + f( sn[idx] ) ) % 1000000);
  // return (memo[idx] = (f( floor( idx - sqrt(idx) ) ) + f( floor( log( idx ) ) ) + f( floor( idx * sin( idx ) * sin( idx ) ) )) % 1000000);
  
}

int main(){
  init();
  init2();
  memo[0] = 1;
  // while( scanf("%d", &n), n != -1 ){
  //   printf("%d\n", f( n ));
  // }
  for( int i = 0; i < MAXN; ++ i ){
    if( sq[i] != sq2[i] ) cout << "i: sq[" << i << "] = " << sq[i] << " =/= sq2[" << i << "] = " << sq2[i] << endl;
    if( sn[i] != sn2[i] ) cout << "i: sn[" << i << "] = " << sn[i] << " =/= sn2[" << i << "] = " << sn2[i] << endl;
    if( lg[i] != lg2[i] ) cout << "i: lg[" << i << "] = " << lg[i] << " =/= lg2[" << i << "] = " << lg2[i] << endl;
  }
  return 0;
}
