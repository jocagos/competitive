// somehow this horrible code made top 177 in UVa for this problem

#include <iostream>
#include <string>

using namespace std;
constexpr int MAXN = 110;
string names[MAXN] {};
int LEFT[MAXN] {}, RIGHT[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  for( int i = 1; i <= n; ++ i ){
    cin >> names[i];
    if( names[i] == "?" )
      LEFT[i] = RIGHT[i] = -1;
    else
      LEFT[i] = RIGHT[i] = 0;
  }
  int q {};
  cin >> q;
  while( q -- ){
    int val {};
    cin >> val;
    if( LEFT[val] == -1 and RIGHT[val] == -1 ){ // not computed yet
      int L = val, R = val;
      // find left
      // maybe can be done by using LEFT and RIGHT instead of names
      while( L > 0 and names[L] == "?" )
	-- L;
      // find right
      while( R <= n and names[R] == "?" )
	++ R;
      if( L == 0 ) // first case
	for( int i = 1; i < R; ++ i )
	  RIGHT[i] = R - i;
      else if( R == n + 1 ) // second case
	for( int i = L + 1; i < R; ++ i )
	  LEFT[i] = i - L;
      else{
	for( int i = L + 1; i < R; ++ i ){
	  LEFT[i] = i - L;
	  RIGHT[i] = R - i;
	}
      }
    }
    if( names[val] == "?" ){
      if( LEFT[val] == -1 ){
	for( int i = 0; i < RIGHT[val]; ++ i )
	  cout << "left of ";
	cout << names[RIGHT[val] + val] << '\n';
      }
      else if( RIGHT[val] == -1 ){
	for( int i = 0; i < LEFT[val]; ++ i )
	  cout << "right of ";
	cout << names[val - LEFT[val]] << '\n';
      }
      else if( RIGHT[val] == LEFT[val] )
	cout << "middle of " << names[val - LEFT[val]] << " and " << names[val + RIGHT[val]] << '\n';
      else if( LEFT[val] < RIGHT[val] ){
	for( int i = 0; i < LEFT[val]; ++ i )
	  cout << "right of ";
	cout << names[val - LEFT[val]] << '\n';
      }
      else if( RIGHT[val] < LEFT[val] ){
	for( int i = 0; i < RIGHT[val]; ++ i )
	  cout << "left of ";
	cout << names[val + RIGHT[val]] << '\n';
      }
    }
    else
      cout << names[val] << '\n';
  }
  return 0;
}
