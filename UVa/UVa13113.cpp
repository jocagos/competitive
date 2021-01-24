#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

constexpr int MAXA = 510, MAXB = 1010;
constexpr long double EPS = 1e-10;
long double total_voters {};
long double max_vals[MAXB] {};
long double percentages[MAXB][MAXA] {};
pair<long double, int> totals[MAXA] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int a, b;
    cin >> a >> b;
    for( int i = 0; i < b; ++ i ){
      for( int j = 0; j < a; ++ j )
	cin >> percentages[i][j];
      cin >> max_vals[i];
      total_voters += max_vals[i];
      for( int j = 0; j < a; ++ j )
	totals[j].first += max_vals[i] * percentages[i][j];
    }
    for( int i = 0; i < a; ++ i ){
      totals[i].second = i + 1;
      totals[i].first /= 100;
    }
    sort( totals, totals + a );
    // for( int j = 0; j < a; ++ j )
    //   cout << "( " << totals[j].first << ", " << totals[j].second << " )\n";
    // no need for a second round
    if( fabsl( totals[a - 1].first - total_voters * 0.501 ) < EPS ){
      cout << totals[a - 1].second << " " << (long long)totals[a - 1].first << '\n';
    }
    else if( fabs( totals[a - 2].first - totals[a - 1].first ) < EPS ) {
      cout << totals[a - 1].second << " " << (long long)(totals[a - 1].first) << '\n'
	   << totals[a - 2].second << " " << (long long)(totals[a - 2].first) << '\n';
    }
    else{
      cout << totals[a - 1].second << " " << (long long)(totals[a - 1].first) << '\n'
	   << totals[a - 2].second << " " << (long long)(totals[a - 2].first) << '\n';
    }
    if( tc )
      cout << '\n';
  }
  return 0;
}
