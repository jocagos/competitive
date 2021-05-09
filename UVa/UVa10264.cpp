#include <cstdio>

using namespace std;
constexpr int MAXN = 1 << 16;
int vals[MAXN] {};
int potency[MAXN] {};

int main(){
  int n {};
  while( scanf("%d", &n) == 1 ){
    for( int i = 0; i < (1 << n); ++ i )
      potency[i] = 0;
    for( int i = 0; i < (1 << n); ++ i )
      scanf("%d", &(vals[i]));
    for( int i = 0; i < (1 << n); ++ i ){ // compute potency
      for( int j = 0; j < n; ++ j ){ // bit j is going to be toggled
	int tmp = i;
	tmp ^= (1 << j); // toggle jth bit
	potency[i] += vals[tmp];
      }
    }
    int max_val {};
    for( int i = 0; i < (1 << n); ++ i ){
      for( int j = 0; j < n; ++ j ){
	int neighbor = i;
	neighbor ^= (1 << j);
	if( max_val < potency[i] + potency[neighbor] )
	  max_val = potency[i] + potency[neighbor];
      }
    }
    printf("%d\n", max_val);
  }
  return 0;
}
  
