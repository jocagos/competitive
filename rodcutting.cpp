#include <cstdio>
#include <climits>
#include <algorithm>
/*
CLRS Solution 1 - Backtracking the answer (Complete search)
CLRS Solution 2 - Adding a memo table to the backtracking (Top-Down DP)
CLRS Solution 3 - Obtaining the optimal cuts (Bottom-Up DP)
 */
int count = 0;
int mcount = 0;
int bucount = 0;
int cutRod( int * p, int n );
int memoCutRod( int * p, int n, int * memo );
int memoCutRodAux( int * p, int n, int * memo );
int buCutRod( int * p, int n, int * memobu );

int main(){
  int prices[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
  int * memobu = new int[100];
  int * memo = new int[100];
  int ans = cutRod(prices, 11);
  int ans2 = memoCutRod( prices, 11, memo);
  int ans3 = buCutRod( prices, 11, memobu);
  printf("Solution for %d is %d, with %d calls to cutRod( p, n )(Complete Search)\n", 11, ans, count);
  printf("Solution for %d is %d, with %d calls to memoCutRod( p, n, memo )(Top-Down DP)\n", 11, ans2, mcount);
  printf("Solution for %d is %d, with %d calls to buCutRod( p, n, memo )(Bottom-Up DP)\n", 11, ans3, bucount);
  printf("Differences:\n\tcutRod(p, n) does about %lf%% the time of memoCutRod(p, n, memo)\n\tmemoCutRod(p, n, memo) does about %lf%% the time of cutRod(p, n)\n\tCannot measure buCutRoad( p, n, bu ) through mere function calls, left to the reader to compute the complexity as exercise\n", 100.0 * count / mcount, 100.0 * mcount / count );
  free(memo);
  free(memobu);
  return 0;
}

int cutRod( int * p, int n ){
  count++;
  if( n == 0 ) return 0;
  int q = INT_MIN;
  for( int i = 1; i <= n; ++i ){ 
    q = std::max( q, p[i] + cutRod( p, n - i) );
  }
  return q;
}

int memoCutRod( int * p, int n, int * memo ){
  mcount++;
  if( n == 0 ) return 0;
  for( int i = 0; i <= n; ++i ) memo[i] = INT_MIN;
  return memoCutRodAux( p, n, memo );
}

int memoCutRodAux( int * p, int n, int * memo ){
  mcount++;
  if( memo[n] >= 0 ) return memo[n]; // Paso "no voy a calcular de nuevo"
  int q;
  if( n == 0 ) q = 0;
  else{
    q = INT_MIN;
    for( int i = 1; i <= n; ++i ) q = std::max( q, p[i] + memoCutRodAux( p, n - i, memo ));
  }
  return memo[n] = q;
}

int buCutRod( int * p, int n, int * memobu ){
  bucount++;
  memobu[0] = 0;
  int q;
  for( int j = 1; j <= n; ++j ){
    q = INT_MIN;
    for( int i = 1; i <= j; ++i ) q = std::max(q, p[i] + memobu[j-i]);
    memobu[j] = q;
  }
  return memobu[n];
}
