#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  pair<string, string> tmp;
  set<pair<string, string>> ordered;
  unordered_map<string, int> idxs;
  vector<pair<string, string>> names;
  while( getline( cin, line ), line != "END" ){
    int second_ticks = line.find( '\"', 1 );
    string book = line.substr( 0, second_ticks + 1 );
    string author = line.substr( second_ticks + 5 );
    names.emplace_back( author, book );
  }
  sort( names.begin(), names.end() );
  for( int i = 0; i < (int)names.size(); ++ i ){
    idxs[names[i].second] = i;
    ordered.emplace( names[i] );
  }
  // get the queries
  priority_queue<pair<string, string>, vector<pair<string, string>>, std::greater<pair<string, string>>> pq;
  while( getline( cin, line ), line != "END" ){
    if( line[0] == 'B' ){ // Borrow
      string book = line.substr( 7 ); 
      int IDX = idxs[book];
      ordered.erase( names[IDX] );
    }
    else if( line[0] == 'R' ){ // Return
      string book = line.substr( 7 );
      int IDX = idxs[book];
      // cerr << "Emplaced " << book << " into the pq\n";
      pq.emplace( names[IDX] );
    }
    else if( line[0] == 'S' ){ // Shelve
      while( not pq.empty() ){
	auto tmp = pq.top();
	pq.pop();
	auto it = ordered.emplace( tmp );
	auto curr = it.first;
	if( it.second ){ // emplace took place
	  if( curr == ordered.begin() ) // first
	    cout << "Put " << curr->second << " first\n";
	  else{
	    auto PREV = it.first;
	    PREV --;
	    cout << "Put " << curr->second << " after " << PREV->second << "\n";
	  }
	}
      } // end pq;
      cout << "END\n";
    }
  }
  return 0;
}
