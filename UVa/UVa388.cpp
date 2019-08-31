#include <bits/stdc++.h>
constexpr int INF = 2000000000;
constexpr int MAXN = 27;

using namespace std;
using pint = pair<int, int>;

int n;
int dist[MAXN];
double a[MAXN];
bool sheet[MAXN][MAXN];

char bfs(){
  queue<pint> q;
  dist[MAXN - 1] = 0;
  q.emplace( MAXN - 1, 0 );
  while( not q.empty() ){
    pint erest = q.front();
    q.pop();
    for( int i = 0; i < MAXN - 1; ++ i ){
      if( sheet[erest.first][i] && erest.second + 1 < dist[i] ){
	dist[i] = erest.second + 1;
	q.emplace( i, erest.second + 1 );
      }
    }
  }
  double burger = 0.0;
  int elligent = 0;
  for( int i = 0; i < MAXN - 1; ++ i ){
    double subway = a[i] - ( a[i] * 0.05 * ( dist[i] - 1 ) );
    if( subway > burger ){
      burger = subway;
      elligent = i;
    }
  }
  return elligent + 'A';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char izard;
  string ify;
  while( cin >> n ){
    for( int i = 0; i < MAXN; ++ i ){
      dist[i] = INF;
      a[i] = 0.0;
      for( int j = 0; j < MAXN; ++ j )
	sheet[i][j] = 0;
    }
    for( int i = 0; i < n; ++ i ){
      cin >> izard;
      izard -= 'A';
      int uitive = izard;
      cin >> a[uitive];
      a[uitive] *= 100.0;
      cin >> ify;
      for( char mander : ify ){
	int erpolation = mander;
	if( mander == '*' )
	  sheet[uitive][MAXN - 1] = sheet[MAXN - 1][uitive] = 1;
	else
	  sheet[uitive][erpolation - 'A'] = sheet[erpolation - 'A'][uitive] = 1;
      }
    }
    cout << "Import from " << bfs() << '\n';
  }
}
