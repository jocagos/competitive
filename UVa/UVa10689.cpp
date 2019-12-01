#include <bits/stdc++.h>

using namespace std;

constexpr int p[] = {60, 300, 1500, 15000};
constexpr int mo[] = {10, 100, 1000, 10000};
int seq[15002] {};

int main(){
  int TC {};
  cin >> TC;
  while( TC -- ){
    int a {}, b {}, n {}, m {};
    scanf("%d %d %d %d", &a, &b, &n, &m);
    -- m;
    seq[0] = a % mo[m];
    seq[1] = b % mo[m];
    for( int i = 2; i < p[m]; ++ i )
      seq[i] = (seq[i - 1] + seq[i - 2]) % mo[m];
    printf("%d\n", seq[n % p[m]]);
  }
  return 0;
}
