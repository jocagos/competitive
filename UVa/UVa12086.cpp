#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {                                     // returns RSQ(1, b)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int main(){
  int n, cases = 1;
  while( scanf("%d", &n), n ){
    if( cases != 1 ) printf("\n");
    printf("Case %d:\n", cases++);
    FenwickTree vals(n);
    char buf[110];
    memset( buf, 0, sizeof buf );
    for( int i = 1, tmp; i <= n; ++ i ){
      scanf("%d ", &tmp);
      vals.adjust(i, tmp);
    }
    while( strncmp( buf, "END", 3 ) != 0 ){
      scanf("%[^\n]\n", buf ); // fgets( buf, 110, stdin );
      int x, r, y;
      if( buf[0] == 'S' ){
	sscanf( buf, "%*s %d %d", &x, &r );
	int v = vals.rsq( x, x );
	vals.adjust( x, r - v );
      }
      if( buf[0] == 'M' ){
	sscanf( buf, "%*s %d %d", &x, &y );
	printf("%d\n", vals.rsq(x, y));
      }
    }
  }
  return 0;
}
