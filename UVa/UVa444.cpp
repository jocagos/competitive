#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100;

char keys[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
	       78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
	       97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
	       108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
	       119, 120, 121, 122, 33, 32, 44, 46, 58, 59, 63};
unordered_map<string, string> rev;

inline bool is_sign( char c ){
  return c == '?' or c == '!' or c == ',' or c == '.' or c == ':' or c == ';' or c == ' ';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // fill keys
  for( auto key : keys ){
    string k {key};
    if( rev.find( k ) == rev.end() ){
      string tmp = to_string( (int)(key) );
      string v( tmp.rbegin(), tmp.rend() );
      rev[k] = v;
      rev[v] = k;
    }
  }
  // cerr << "Keyrring:\n";
  // for( auto p : rev ) cerr << "( " << p.first << ", " << p.second << " )\t";
  // cerr << endl;
  string s, line;
  vector<string> vs( MAXN );
  while( getline( cin, line ) ){
    // ios_base::fmtflags f( cout.flags() );
    if( isalpha( line[0] ) or is_sign( line[0] ) ){ // to_num
      int idx = 0;
      for( auto c : line ){
	string cc {c};
	vs[idx] = rev[cc];
	idx ++;
      }
      while( --idx >= 0 ){
	cout << vs[idx];
      }
    }
    else{ // to_str
      unsigned int idx = 0, i, j;
      string rline( line.rbegin(), line.rend() );
      for( i = 0, j = 1; i < rline.length() and i + j <= rline.length(); ++ j ){
	string tmp = rline.substr( i, j );
	string key( tmp.rbegin(), tmp.rend() );
	if( rev.find( key ) != rev.end() ){
	  vs[idx ++] = rev[key];
	  i += j;
	  j = 1;
	}
      }
      for( unsigned i = 0; i < idx; ++ i )
	cout << vs[i];
    }
    cout << endl;
  }
  return 0;
}
