#include <bits/stdc++.h>

using namespace std;

string f( int n ){
  int l = (-1 + sqrt( 1 + 8 * n )) / 2; // get max val for the sequence
  int steps = n - l * l;
  int b = (l + 1) * (l + 1) - steps, a = 1 + steps;
  
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n {};
  while( cin >> n ){
    cout << "TERM " << n << " IS " << f( n ) << '\n';
  }
  return 0;
}
