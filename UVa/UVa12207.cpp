#include <iostream>
#include <deque>

using namespace std;

inline int min( int a, int b ){
  return (a < b ? a : b);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int CASE {}, p {}, q {};
  while( cin >> p >> q, p | q ){
    deque<int> deck;
    for( int i = 1; i <= min(p, q); ++ i )
      deck.emplace_back( i );
    cout << "Case " << ++CASE << ":\n";
    while( q -- ){
      string s {};
      cin >> s;
      if( s[0] == 'N' ){
	deck.emplace_back( deck.front() );
	cout << deck.front() << '\n';
	deck.pop_front();
      }
      else{
	int n {};
	cin >> n;
	for( auto it = deck.begin(); it != deck.end(); ++ it )
	  if( *it == n ){
	    deck.erase( it );
	    break;
	  }
	deck.emplace_front( n );
      }
    }
  }
  return 0;
}
