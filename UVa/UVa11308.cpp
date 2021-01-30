#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>

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
    string binder {};
    getline( cin, binder );
    for( int i = 0; i < (int)binder.length(); ++ i )
      if( 'a' <= binder[i] and binder[i] <= 'z' )
	binder[i] += 'A' - 'a';
    getline( cin, line );
    int m {}, n {}, b {}, cost {}, units {};
    string ing {}, recipe {};
    istringstream first( line );
    first >> m >> n >> b;
    // ingredients
    unordered_map<string, int> ingredient_cost;
    unordered_map<string, int> recipe_cost;
    for( int i = 0; i < m; ++ i ){
      getline( cin, line );
      istringstream iss( line );
      iss >> ing >> cost;
      ingredient_cost[ing] = cost;
    }
    // recipes
    for( int i = 0; i < n; ++ i ){
      getline( cin, recipe );
      recipe_cost[recipe] = 0;
      getline( cin, line ); // k
      int k = stoi( line );
      // get ingredients from a recipe
      for( int j = 0; j < k; ++ j ){
	getline( cin, line );
	istringstream iss( line );
	iss >> ing >> units;
	recipe_cost[recipe] += units * ingredient_cost[ing];
      }
    } // end for recipes
    // sort the data lexicographically
    vector<pair<string, int>>
      sorted_recipes( recipe_cost.begin(), recipe_cost.end() );
    sort( sorted_recipes.begin(),
	  sorted_recipes.end(),
	  []( pair<string, int>& lhs, pair<string, int>& rhs ) -> bool {
	    if( lhs.second != rhs.second )
	      return lhs.second < rhs.second;
	    else
	      return lexicographical_compare( lhs.first.begin(), lhs.first.end(), rhs.first.begin(), rhs.first.end() );
	  });
    // print the valid recipes
    int printed {};
    cout << binder << '\n';
    for( auto& it : sorted_recipes ){
      if( it.second <= b ){
	++ printed;
	cout << it.first << '\n';
      }
    }
    if( printed == 0 )
      cout << "Too expensive!\n";
    cout << '\n';
  }
  return 0;
}
