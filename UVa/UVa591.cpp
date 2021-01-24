#include <iostream>

using namespace std;
constexpr int MAXN = 55;
int heights[MAXN] {};

inline int abs( int x ){
  return (x >= 0 ? x : -x);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, CASE {1};
  while( cin >> n, n ){
    int total {}, movs {};
    for( int i = 0; i < n; ++ i ){
      cin >> heights[i];
      total += heights[i];
    }
    total /= n;
    for( int i = 0; i < n; ++ i )
      movs += abs(heights[i] - total);
    movs /= 2;
    cout << "Set #" << CASE ++ << '\n';
    cout << "The minimum number of moves is " << movs << ".\n\n";
  }
  return 0;
}
