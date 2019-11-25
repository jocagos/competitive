#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
constexpr int MAXN = 1010;
vector<ii> points( MAXN );
int mat[MAXN][MAXN] {};

void ffill( int x, int y, int d ){
  if( d == 0 ) return;
  mat[x][y] += 1;
  d --;
  
}

int main(){
  int col, row, k, d;
  scanf("%d %dn", &col, &row);
  scanf("%d\n", &k);
  for( int i = 0; i < k; ++ i )
    scanf("%d %d\n", &points[i].first, &points[i].second );
  scanf("%d\n", &d);
  for( int i = 0; i < k; ++ i )
    ffill( points[i].first, points[i].second, d );
  
  return 0;
}
