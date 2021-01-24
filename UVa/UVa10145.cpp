// This problem is a PITA
// But it teaches a lot about VERY specific details
// and some insight into how to organize data effectively
// because I did it as I thought about it and got rank 11
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {}, trid {}, item {};
  string mode {};
  cin >> tc;
  while( tc -- ){
    unordered_map<int, unordered_set<int>> shared;
    unordered_map<int, int> locked;
    unordered_set<int> ignored;
    while( cin >> mode ){
      if( mode == "#" )
	break;
      if( mode == "S" or mode == "X" ){
	cin >> trid >> item;
	if( ignored.find( trid ) != ignored.end() ){
	  cout << "IGNORED\n";
	  continue;
	}
	if( locked.find( item ) != locked.end()
	    and locked[item] != trid ){
	  ignored.emplace( trid );
	  cout << "DENIED\n";
	  continue;
	}
	if( mode == "S" ){
	  auto it_lock = locked.find( item );
	  auto it_shared = shared.find( item );
	  if( it_lock == locked.end() and it_shared != shared.end() ){ // not locked, but shared
	    cout << "GRANTED\n";
	    shared[item].emplace( trid );
	    continue;
	  }
	  else if( it_lock == locked.end() and it_shared == shared.end() ){
	    cout << "GRANTED\n";
	    shared[item].emplace( trid );
	    continue;
	  }
	  else if( it_lock != locked.end() and locked[item] == trid ){
	    cout << "GRANTED\n";
	    shared[item].emplace( trid );
	    continue;
	  }
	  else{
	    cout << "DENIED\n";
	    ignored.emplace( trid );
	    continue;
	  }
	}
	if( mode == "X" ){
	  auto it = shared.find( item );
	  if( it != shared.end() ){ // found it in shared
	    if( (shared[item].find( trid ) != shared[item].end() and shared[item].size() == 1U)
		or shared[item].empty() ){
	      cout << "GRANTED\n";
	      locked[item] = trid;
	      continue;
	    }
	    else{
	      cout << "DENIED\n";
	      ignored.emplace( trid );
	      continue;
	    }
	  }
	  else if( it == shared.end() )
	    locked[item] = trid;
	  else{
	    cout << "DENIED\n";
	    ignored.emplace( trid );
	    continue;
	  }	  
	}
	cout << "GRANTED\n";
      }
    }
    if( tc ) cout << '\n';
  }
  return 0;
}
