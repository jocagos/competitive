#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long TC = 400 * 100 * 100 * 100;
  cout << TC << '\n';
  for( int C = 0; C < 400; ++ C )
    for( int X = 0; X < 100; ++ X )
      for( int Y = 0; Y < 100; ++ Y )
	for( int Z = 0; Z < 100; ++ Z )
	  cout << C << ' ' << X << ' ' << Y << ' ' << Z << '\n';
  return 0;
}
