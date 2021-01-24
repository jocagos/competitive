#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;
constexpr int MAXN = 13;
constexpr int MAXT = 110;
int team_problem[MAXT][MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, t {}, m {};
  string verdict {}, problem {};
  cin >> n >> t >> m;
  int TIME {}, TEAM {};
  vector<int> sols_time( n, -1 );
  vector<int> sols_team( n, -1 );
  for( int i = 0; i < m; ++ i ){
    cin >> TIME >> TEAM >> problem >> verdict;
    int tmp = problem[0] - 'A';
    if( ( verdict[0] == 'Y' or verdict[0] == 'y' ) and
       team_problem[TEAM][tmp] == 0 ){
      ++ team_problem[TEAM][tmp];
      sols_time[tmp] = TIME;
      sols_team[tmp] = TEAM;
    }
  }
  for( int i = 0; i < n; ++ i ){
    cout << (char)('A' + i) << " ";
    if( sols_time[i] != -1 and sols_team[i] != -1 )
      cout << sols_time[i] << " " << sols_team[i] << '\n';
    else
      cout << "- -\n";
  }
  return 0;
}
