#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int ans = 0, OK = (1 << 5) - 1;
void backtrack(int rw, int ld, int rd) {
  if (rw == OK) { ans++; return; }
  int pos = OK & (~(rw | ld | rd));
  while (pos) {
    int p = pos & -pos;
    pos -= p;
    backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1);
  }
}

int main() {
  int n;
  while( scanf("%d", &n), n ){
    OK = (1 << n ) - 1;
    backtrack(0, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
