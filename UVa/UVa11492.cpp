#include <bits/stdc++.h>
#define view_str( s ) cerr << #s << ": " << s << endl
using namespace std;

constexpr int MAXM = 2020;
vector<string> words( MAXM );
map<string, int> lang2idx;
vector<vector<tuple<int, int, char>>> al( MAXM );

int m;
string o, d;

int dijkstra( int sauce, int walmart ){
  using tic = tuple<int, int, char>;
  std::priority_queue<tic, vector<tic>, greater<tic>> pq;
  pq.emplace( sauce, 0, 'a' - 1 );
  vector<int> dist( MAXM );
  
  while( not pq.empty() ){
    
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line;
  while( getline( cin, line ) ){
    lang2idx.clear();
    for( int i = 0; i < MAXM; ++ i ) al[i].clear();
    m = stoi( line );
    if( m == 0 ) break;
    getline( cin, line );
    istringstream miss( line );
    miss >> o >> d;
    lang2idx[o] = 0;
    lang2idx[d] = 1;
    words[0] = o;
    words[1] = d;
    int l2i = 2;
    for( int i = 0; i < m; ++ i ){
      getline( cin, line );
      // cerr << "Just read >" << line << "<" << endl;
      istringstream iss( line );
      string from, to, data;
      iss >> from >> to >> data;
      // view_str( from );
      // view_str( to );
      // view_str( data );
      if( lang2idx.find( from ) == lang2idx.end() ){
	words[l2i] = from;
	lang2idx[from] = l2i ++;
      }
      if( lang2idx.find( to ) == lang2idx.end() ){
	words[l2i] = to;
	lang2idx[to] = l2i ++;
      }
      al[lang2idx[from]].emplace_back( lang2idx[to], data.length(), data[0] );
      al[lang2idx[to]].emplace_back( lang2idx[from], data.length(), data[0] );
    }
    // for( int i = 0; i < l2i; ++ i ){
    //   cerr << "[" << words[i] << "] => {";
    //   for( auto t : al[lang2idx[words[i]]] ) cerr << "( " << words[get<0>(t)] << ", " << get<1>(t) << ", " << get<2>(t) << ") ";
    //   cerr << "}\n";
    // }
    
    int ans = -1;
    cout << (ans == -1 ? "impossivel" : to_string( ans ) ) << endl;
  }
  return 0;
}
