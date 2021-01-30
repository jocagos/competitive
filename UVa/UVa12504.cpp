#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    unordered_map<string, string> old, recent;
    set<string> added, deleted, changed;
    getline( cin, line );
    line = line.substr( 1, line.length() - 2 );
    int L {}, R {};
    while( R < (int)line.length() ){
      if( line[R] == ':' ){ // key found
	string key = line.substr( L, R - L );
	++ R;
	L = R;
	while( R < (int)line.length() and line[R] != ',' )
	  ++ R;
	string val = line.substr( L, R - L );
	++ R;
	L = R;
	old[key] = val;
      }
      else
	++ R;
    }
    getline( cin, line );
    line = line.substr( 1, line.length() - 2 );
    L = R = 0;
    while( R < (int)line.length() ){
      if( line[R] == ':' ){ // key found
	string key = line.substr( L, R - L );
	++ R;
	L = R;
	while( R < (int)line.length() and line[R] != ',' )
	  ++ R;
	string val = line.substr( L, R - L );
	++ R;
	L = R;
	recent[key] = val;
      }
      else
	++ R;
    }
    for( auto& it : old ){
      // found
      if( recent.find( it.first ) != recent.end() ){
	if( it.second != recent[it.first] )
	  changed.emplace( it.first );
      }
      else
	deleted.emplace( it.first );
    }
    for( auto& it : recent )
      if( old.find( it.first ) == old.end() )
	added.emplace( it.first );
    if( added.size() == 0 and deleted.size() == 0 and changed.size() == 0 )
      cout << "No changes\n";
    else{
      if( added.size() ){
	bool first = true;
	for( auto& str : added ){
	  cout << (first ? '+' : ',') << str;
	  if( first ) first = false;
	}
	cout << '\n';
      }
      if( deleted.size() ){
	bool first = true;
	for( auto& str : deleted ){
	  cout << (first ? '-' : ',') << str;
	  if( first ) first = false;
	}
	cout << '\n';
      }
      if( changed.size() ){
	bool first = true;
	for( auto& str : changed ){
	  cout << (first ? '*' : ',') << str;
	  if( first ) first = false;
	}
	cout << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}
