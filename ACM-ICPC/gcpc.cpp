#include <iostream>
#include <utility>
#include <set>
#include <vector>

using namespace std;

typedef pair<pair<int, int>, int> iii;

int main(){
  int n, m, a, b;
  scanf("%d %d", &n, &m );
  auto f = []( const iii& l, const iii& r ){
    if( l.first.first != r.first.first ) return l.first.first < r.first.first;
    else if( l.first.second != r.first.second ) return l.first.second > r.first.second;
    else return l.second < r.second;
  };
  set<iii, decltype(f)> contest(f);
  vector<pair<int, int>> contestants(n+1);
  pair<int, int> myTeam (0, 0);
  while( m-- ){
    scanf("%d %d", &a, &b);
    if( a == 1 ) myTeam.first++, myTeam.second += b;
    contestants[a].first++;
    contestants[a].second += b;
    if( a != 1 and (myTeam.first != contestants[a].first ? myTeam.first < contestants[a].first : (myTeam.second != contestants[a].second ? myTeam.second > contestants[a].second : a < 1)) ) contest.insert( make_pair( contestants[a], a ) );
    if( a == 1 ){
      for( auto it = contest.begin(); it != contest.end(); it++ ){
	if( f( *it, make_pair( myTeam, 1 ) ) ){
	  contest.erase( it );
	}
      }
    }
    cout << contest.size()+1 << endl;
  }
  return 0;
}
