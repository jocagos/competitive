#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100005;

vector<string> vals( 2 * MAXN );
int sets;

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
  
  int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
  bool is_same_set(int i, int j) { return find_set(i) == find_set(j); }
  bool union_set(int i, int j) { 
    if (!is_same_set(i, j)) {
      num_sets--; 
      int x = find_set(i), y = find_set(j);
      if( vals[x].length() > vals[y].length() )
	swap( x, y );
      if( lexicographical_compare( begin( vals[x] ), end( vals[x] ), begin( vals[y] ), end( vals[y] ) ) )
	swap( x, y );
      // guaranteed x < y
      set_size[x] += set_size[y];
      p[y] = x;
      // if (rank[x] > rank[y]) {
      // 	p[y] = x;
      // 	set_size[x] += set_size[y];
      // }
      // else{
      // 	p[x] = y;
      // 	set_size[y] += set_size[x];
      // 	if (rank[x] == rank[y]) rank[y]++;
      // }
      return true;
    }
    return false;
  }
  int how_many() { return num_sets; }
  int size_of_set(int i) { return set_size[find_set(i)]; }
};


int main(){
  int n {};
  cin >> n;
  map<string, int> keys;
  int key_val = 0;
  vector<pair<string, string>> input( 2 * n );
  for( int i = 0; i < n; ++ i )
    cin >> input[i].first >> input[i].second;
  set<string> uni;

  for( int i = 0; i < n; ++ i ){
    string& lhs = input[i].first;
    string& rhs = input[i].second;
    uni.emplace( lhs );
    uni.emplace( rhs );
    auto it = keys.find( lhs );
    if( it == keys.end() ){
      keys[lhs] = key_val;
      vals[key_val ++] = lhs;
    }
    it = keys.find( rhs );
    if( it == keys.end() ){
      keys[rhs] = key_val;
      vals[key_val ++] = rhs;
    }
  }
  sets = uni.size();
  UFDS ufds = UFDS( sets );
  for( int i = 0; i < n; ++ i ){
    string& lhs = input[i].first;
    string& rhs = input[i].second;
    if( lhs.length() <= rhs.length() )
      ufds.union_set( keys[lhs], keys[rhs] ); // build graph
    else
      ufds.union_set( keys[rhs], keys[lhs] ); // build graph
  }
  string str {};
  while( cin >> str ){
    int idx = keys[str];
    cerr << "keys[" << str << "] = " << idx << endl;
    int u = ufds.find_set( idx );
    cerr << "vals[" << u << "] = " << vals[u] << endl;
    cerr << endl;
    cout << vals[ufds.find_set( keys[str] )] << " ";
  }
  cout << '\n';
  return 0;
}
