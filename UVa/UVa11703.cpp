#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> memo(1000002, -1e6);

int f( int idx ){
  if( memo[idx] != -1e6 )return memo[idx];
  return (memo[idx] = (f( floor( idx - sqrt(idx) ) ) + f( floor( log( idx ) ) ) + f( floor( idx * sin( idx ) * sin( idx ) ) )) % 1000000);
  
}

int main(){
  memo[0] = 1;
  int n;
  while( scanf("%d", &n), n != -1 ){
    printf("%d\n", f( n ));
  }
  return 0;
}
