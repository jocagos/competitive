#include <cstdio>
#include <cstring>
#include <iostream>
#include <cfloat>
#include <limits>

using namespace std;

int main(){
  int n, p, reqmet, maxreq, ii = 1;
  double cost, mincost;
  string s, cur;
  while( cin >> n >> p, n || p ){
    mincost = DBL_MAX; // INF
    maxreq = -1;
    for( int i = 0; i < n; ++i ){cin.ignore(); getline(cin, s);} // skip requirements
    while(p--){
      getline(cin, s);
      scanf("%lf %d", &cost, &reqmet);
      if( reqmet > maxreq ){
        mincost = cost;
        maxreq = reqmet;
        cur = s;
      }
      else if( cost < mincost && reqmet >= maxreq ){
        mincost = cost;
        maxreq = reqmet;
        cur = s;
      }
      for( int j = 0; j < reqmet; ++j ) getline(cin, s); // skip requirements
    }
    if( ii > 1 ) cout << endl;
    cout << "RFP #" << ii++ << endl << cur << endl;
  }
  return 0;
}
