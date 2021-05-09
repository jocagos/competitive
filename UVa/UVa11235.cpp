#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
constexpr int MAXN = 100010, UNSET = 200020;
int L[MAXN * 2] {}, R[MAXN * 2] {}, st[MAXN * 4] {}, vals[MAXN] {}, freq[MAXN] {};

void build( int left_point, int right_point, int p ){
  if( left_point == right_point ){
    st[p] = left_point;
    return;
  }
  int mid_idx = (left_point + right_point) / 2;
  int left_idx = p * 2, right_idx = p * 2 + 1;
  build( left_point, mid_idx, left_idx );
  build( mid_idx + 1, right_point, right_idx );
  int left_val = freq[st[left_idx]], right_val = freq[st[right_idx]];
  st[p] = (left_val > right_val ? st[left_idx] : st[right_idx]);
}

int rmq( int left_range, int right_range, int left_lookup, int right_lookup, int p ){
  if( right_lookup < left_range or left_lookup > right_range )
    return -1; // invalid query
  if( left_range <= left_lookup and right_lookup <= right_range )
    return st[p]; // if current range covers the lookup range

  int mid_idx = (left_lookup + right_lookup) / 2;
  int left_idx = p * 2, right_idx = p * 2 + 1;
  int best_left = rmq( left_range, right_range, left_lookup, mid_idx, left_idx ),
    best_right = rmq( left_range, right_range, mid_idx + 1, right_lookup, right_idx );

  if( best_left == -1 )
    return best_right;
  if( best_right == -1 )
    return best_left;

  int left_val = freq[best_left], right_val = freq[best_right];
  return (left_val > right_val ? best_left : best_right);
}

int main(){
  int n {}, q {}, prev {}, curr {}, fr {};
  while( scanf("%d %d", &n, &q), n ){
    L[0] = 0;
    curr = UNSET;
    for( int i = 0; i < n; ++ i ){
      scanf("%d", &vals[i]);
      curr = vals[i];
      if( prev != curr and prev != UNSET ){
	for( int j = L[i - 1]; j <= i - 1; ++ j ){
	  freq[j] = fr;
	  R[j] = i - 1;
	}
	fr = 0;
	L[i] = i;
      }
      else
	L[i] = L[i - 1];
      ++ fr;
      prev = curr;
      if( i + 1 == n )
	for( int j = L[i]; j <= i; ++ j ){
	  freq[j] = fr;
	  R[j] = i;
	}
    }
    build( 0, n - 1, 1 );
    int a {}, b {};
    for( int i = 0; i < q; ++ i ){
      scanf("%d %d", &a, &b);
      -- a;
      -- b;
      if( vals[a] == vals[b] )
	printf("%d\n", b - a + 1);
      else{
	int left_seg = R[a] - a + 1, right_seg = b - L[b] + 1;
	if( L[b] - R[a] > 1 )
	  printf("%d\n",
		 max( freq[rmq( R[a] + 1, L[b] - 1, 0, n - 1, 1 )], max( left_seg, right_seg ) ) );
	else
	  printf("%d\n", (right_seg > left_seg ? right_seg : left_seg));
      }
    }
  }
  return 0;
}
