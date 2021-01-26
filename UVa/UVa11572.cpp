#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000010;
 
int main(int argc, char** argv) {
  int testCase;
  scanf ("%d", &testCase);
 
  while ( testCase-- ) {
    int n, ar [MAXN], previous_position [MAXN];
    scanf ("%d", &n);
 
    unordered_map <int, int> m;
    int cnt = 0;
    int maxi = 0;
 
    for ( int i = 1; i <= n; i++ ) {
      scanf ("%d", &ar [i]);
      previous_position [i] = m [ar [i]];
      m [ar [i]] = i;
    }
 
    int curr = 1;
    int previous = 1;
 
    for ( curr = 1; curr <= n; curr++ ) {
      if ( previous_position [curr] >= previous ) {
	maxi = max (maxi, curr - previous);
	previous = previous_position [curr] + 1;
      }
    }
 
    maxi = max (maxi, curr - previous);
 
    printf ("%d\n", maxi);
  }
 
  return 0;
}
