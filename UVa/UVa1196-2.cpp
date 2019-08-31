#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

#define MAX_N 100000

void print_array(const char *s, int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i) printf(", ");
    else printf("%s: [", s);
    printf("(%d, %d)", a[i].fi, a[i].se);
  }
  printf("]\n");
}

void reconstruct_print(int end, ii a[], ii p[]) {
  int x = end;
  stack<ii> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[(%d, %d)", a[x].fi, a[x].se);
  for (; !s.empty(); s.pop()) printf(", (%d, %d)", s.top().fi, s.top().se);
  printf("]\n");
}

int main() {
  int n;
  ii L[MAX_N], L_id[MAX_N], P[MAX_N], A[MAX_N];
  while( scanf("%d", &n), n ){
    int lis = 0, lis_end = 0;
    for (int i = 0; i < n; ++i) {
      // To mutate it to Longest Monotonic Increasing (or Decreasing) Subsequence
      int pos = lower_bound(L, L + lis, A[i]) - L; // change this to `upper_bound'
      L[pos] = A[i];
      L_id[pos] = i;
      P[i] = pos ? L_id[pos - 1] : -1;
      if (pos + 1 > lis) { // and this one to `>='
	lis = pos + 1;
	lis_end = i;
      }
      // For decreasing, just store the values as negative them
      // This is because `upper_bound' is exclusively greater than, and with the "greater or equal" part
      // in `pos', we get what would be a "lesser or equal". Think a little about it.
      // NOTE: This added comment is NOT from CP3, it's entirely by me, jocagos.

      printf("Considering element A[%d] = %d\n", i, A[i]);
      printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
      reconstruct_print(i, A, P);
      print_array("L is now", L, lis);
      printf("\n");
    }

    printf("Final LIS is of length %d: ", lis);
    reconstruct_print(lis_end, A, P);
  }
  
  return 0;
}

