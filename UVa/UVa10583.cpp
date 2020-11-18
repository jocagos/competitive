#include <bits/stdc++.h>

using namespace std;
/*
 * A -> reg_i
 * B -> reg(A)
 * C -> reg_j
 *****************
 * si A y B tienen misma religion -> unimos
 * si no, buscamos la religion de B
 */

class UFDS {
private:
  vector<int> p, rank, set_size;
  long long num_sets, offset;
public:
  UFDS( int N ){
    set_size.assign(N, 1);
    num_sets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    offset = 0;
    for (int i = 0; i < N; i++) p[i] = i;
  }

  UFDS( int N, int max_size ){ // to reuse it
    set_size.assign( max_size, 1 );
    num_sets = N;
    rank.assign( max_size, 0 );
    p.assign( max_size, 0 );
    offset = 0;
    for(int i = 0; i < N; i++) p[i] = i;
  }
  
  UFDS( int N, int max_size, int idx ){ // when you need offsets, or 1-based idx
    set_size.assign( max_size, 1 );
    num_sets = N, offset = idx;
    rank.assign( max_size, 0 );
    p.assign( max_size, 0 );
    for( int i = idx; i < N + idx; ++ i ) p[i] = i;
  }

  void init( int N, int idx = 0 ){
    offset = idx;
    for( int i = offset; i < N + offset; ++ i ){
      rank[i] = set_size[i] = 1;
      p[i] = i;
    }
  }
  
  int find_set(int i) {
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
  }
  bool is_same_set(int i, int j) {
    return find_set(i) == find_set(j);
  }
  bool union_set(int i, int j) { 
    if (!is_same_set(i, j)) {
      num_sets--; 
      int x = find_set(i), y = find_set(j);
      if (rank[x] > rank[y]) {
	p[y] = x;
	set_size[x] += set_size[y];
      }
      else{
	p[x] = y;
	set_size[y] += set_size[x];
	if (rank[x] == rank[y]) rank[y]++;
      }
      return true;
    }
    return false;
  }
  int how_many() {
    return num_sets;
  }
  int size_of_set(int i) {
    return set_size[find_set(i)];
  }
};

int main(){
  int m {}, n {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // a & b = and BINARIO
  // a | b = or BINARIO
  int CASE = 1;
  while( cin >> n >> m, n | m ){
    int lhs {}, rhs {};
    UFDS ufds = UFDS( n );
    // cerr << "N: " << n << "\nM: " << m << '\n';
    for( int i = 0; i < m; ++ i ){
      cin >> lhs >> rhs;
      ufds.union_set( lhs - 1, rhs - 1 );
    }
    cout << "Case " << CASE << ": " << ufds.how_many() << '\n';
    CASE ++;
  }
  return 0;
}
