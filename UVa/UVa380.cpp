/*
 * @author: Jose Luis Gallegos Cardenas
 * @id: UVa 00380 - Call Forwarding
 * @subject: Backtracking techniques
 * @strategy: store the queries then for every query at a given time store source => destination in a hash list then:
   * if hash list is empty, extension = source thus ring extension
   * if hash list degenerates in a circle, check source vs extension and if at any moment they're equal then ring 9999
   * else just ring the right extension
 * Fuck backtracking, let's simulate it.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  cout << "CALL FORWARDING OUTPUT" << endl;
  for( int _i = 1; _i <= t; ++ _i ){
    string source, time, duration, target;
    vector<vector<pair<string, string>>> times(10001);
    while( true ){
      cin >> source;
      if( source == "0000" or source == "0000\r" ) break;
      cin >> time >> duration >> target;
      for( int i = stoi(time); i <= stoi(time) + stoi(duration); ++ i ){
	times[i].emplace_back(source, target);
      }
    }
    string extension;
    unordered_map<string, string> hashes;
    cout << "SYSTEM " << _i << endl;
    while( true ){
      cin >> time;
      if( time == "9000" or time == "9000\r" ) break;
      cin >> extension;
      if( !times[stoi(time)].empty() ){
	for( auto x : times[stoi(time)] ) hashes[x.first] = x.second;
	source = extension;
	while( hashes.find(source) != hashes.end() ){
	  source = hashes[source];
	  if( source == extension ){ source = "9999"; break; } 
	}
	hashes.clear();
      }
      else source = extension;
      cout << "AT " << time << " CALL TO " << extension << " RINGS " << source << endl;
    }
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
