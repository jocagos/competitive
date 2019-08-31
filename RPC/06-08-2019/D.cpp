#include <bits/stdc++.h>

using namespace std;
using nword = unsigned long long;


inline nword magic( nword x, nword y ){
  nword block = x + y - 1;
  nword ub = block * (block + 1) / 2;
  nword mahx = 1ULL * (block % 2 == 0 ? block : 1), mahy = 1ULL * (block % 2 ? block : 1);
  nword sneakyboi = max( abs( x - mahx ), abs( y - mahy ) );
  return ub - sneakyboi;
}

int main(){
  nword x, y;
  while( scanf("%llu %llu\n", &x, &y), x | y )
    printf("%llu\n", magic( x, y ) );
  return 0;
}
