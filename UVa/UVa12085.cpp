#include <iostream>
#include <cmath>

using namespace std;

int lcs( string l, string r ){
  int i = 0;
  while( l[i] == r[i] ) i++;
  return i;
}

int main(){
  int n, c = 1;
  string snums[100000], tmp;
  scanf("%d ", &n);
  while(n){
    cout << "Case " << c++ << ":" << endl; 
    for( int i = 0; i < n; ++i ) cin >> snums[i];
    int consecutive = 0;
    bool last = false;
    for( int i = 1; i < n; ++i ){
      if( stoll(snums[i]) - stoll(snums[i-1]) == 1 ) consecutive++;
      else if( consecutive == 0 ) cout << snums[i-1] << endl;
      else{
	string l = snums[i-1-consecutive],
	  r = snums[i-1];
	consecutive = 0;
	int idx = lcs(l, r);
	cout << l + "-" + r.substr(idx) << endl;
      }
    }
    if( consecutive == n - 1 ){
      	consecutive = 0;
	string l = snums[0],
	  r = snums[n-1];
	int idx = lcs(l, r);
	cout << l + "-" + r.substr(idx) << endl;
    }
    if( stoll(snums[n-1]) - stoll(snums[n-2]) != 1 ) cout << snums[n-1] << endl;
    scanf("%d ", &n);
    if( n ) cout << endl;
  }
  return 0;
}
