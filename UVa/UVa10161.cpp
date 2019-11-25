#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long n;
  while( cin >> n, n ){
    int top = ceil( sqrt( n ) ), bot = sqrt( n );
    int a {1}, b{bot};
    if( top != bot ){
      int steps = n - bot * bot;
      if( steps ){
	b ++;
	steps --;
      }
      a += min( steps, bot );
      steps = (steps > bot ? steps - bot : 0);
      b -= steps;
      if( bot % 2 == 0 and top % 2 ) swap( a, b );
    }
    else{
      if( bot % 2 == 0 ) a = bot, b = 1;
      else a = 1, b = bot;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
