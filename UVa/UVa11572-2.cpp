#include <bits/stdc++.h>

using namespace std;

int main(){
  int tc {};
  scanf("%d", &tc);
  while( tc -- ){
    unordered_map<int, bool> s;
    int n {};
    scanf("%d", &n);
    while( n -- ){
      int t {};
      scanf("%d", &t);
      s[t] = true;
    }
    printf("%lu\n", s.size());
  }
  return 0;
}
