#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

typedef pair<pair<int, int>, int> iii;

int main(){
  int n;
  set<int> scores { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
  for( int i = 0; i <= 20; ++ i ) scores.insert( i * 2 ), scores.insert( i * 3 );
  scores.insert(50);
  while( scanf("%d", &n), n > 0 ){
    set<iii> combinations;
    set<iii> permutations;
    int comb = 0, perm = 0;
    int sum = 0;
    for( auto i = scores.begin(); i != scores.end(); i ++ ){
      for( auto j = scores.begin(); j != scores.end(); j ++ ){
	for( auto k = scores.begin(); k != scores.end(); k ++ ){
	  sum = *i + *j + *k;
	  if( sum == n ){
	    iii s = make_pair( make_pair(*i, *j), *k );
	    vector<int> vals { *i, *j, *k };
	    sort(vals.begin(), vals.end());
	    iii p = make_pair( make_pair(vals[0], vals[1]), vals[2]);
	    permutations.insert(s);
	    combinations.insert(p);
	  }
	}
      }
    }
    if( permutations.size() > 0 ){
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combinations.size() << "." << endl;
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutations.size() << "." << endl;
    }
    else cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
    for( int i = 0; i < 70; ++i ) printf("*");
    printf("\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
