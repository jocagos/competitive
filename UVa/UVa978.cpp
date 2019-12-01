#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int _ {}; _ < tc; ++ _ ){
    if( _ ) cout << '\n';
    priority_queue<int> blue, green;
    int bf {}, sb {}, sg {};
    cin >> bf >> sg >> sb;
    for( int i {}; i < sg; ++ i ){
      int tmp {};
      cin >> tmp;
      green.emplace( tmp );
    }
    for( int i {}; i < sb; ++ i ){
      int tmp {};
      cin >> tmp;
      blue.emplace( tmp );
    }
    while( not blue.empty() and not green.empty() ){
      vector<int> wg, wb;
      int tmp{bf};
      while( not blue.empty() and tmp -- ){
	wb.emplace_back( blue.top() );
	blue.pop();
      }
      tmp = bf;
      while( not green.empty() and tmp -- ){
	wg.emplace_back( green.top() );
	green.pop();
      }
      for( auto i {wb.size()-wb.size()}; i < min( wb.size(), wg.size() ); ++ i ){
	if( wb[i] > wg[i] )
	  blue.emplace( wb[i] - wg[i] );
	else if( wg[i] > wb[i] )
	  green.emplace( wg[i] - wb[i] );
      }
      if( wb.size() > wg.size() ){
	for( auto i {wg.size()}; i < wb.size(); ++ i )
	  blue.emplace( wb[i] );
      }
      else if( wg.size() > wb.size() ){
	for( auto i {wb.size()}; i < wg.size(); ++ i )
	  green.emplace( wg[i] );
      }
    }
    if( blue.size() > green.size() ){
      cout << "blue wins\n";
      while( not blue.empty() ){
	cout << blue.top() << '\n';
	blue.pop();
      }
    }
    else if( blue.size() < green.size() ){
      cout << "green wins\n";
      while( not green.empty() ){
	cout << green.top() << '\n';
	green.pop();
      }
    }
    else
      cout << "green and blue died\n";
  }
  return 0;
}
