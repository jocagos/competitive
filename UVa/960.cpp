#include <bits/stdc++.h>
#define FOR(i,j,k) for(int (i) =(j);(i)<(k);++(i))
#define pb push_back
#define pair<int,int> pii
#define F first
#define S second
#define EPS 1e-9
#define MAXN 11000
#define cl(x) memset((x),0,sizeof(x))
#define ll long long

using namespace std;

bool crivo[MAXN+100];

int main(){
	
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int i,j,k,n,m,a,b,c,t;
  cin >>t;
  cl(crivo);
  for( int i=2;i<MAXN;i++){
    if( !crivo[i]){
      for(int j=i+i;j<MAXN;j+=i) crivo[j] = true;
    }
  }
  while(t--){
    scanf("%d%d", &a,&b);
    if( a !=0 && b != 0){
      bool prime = true;
      ll A =a; ll B = b;
      ll aux = A * A + B * B;
      for( ll i=2;i*i<=aux;i++){
	if( aux % i == 0) {	
	  prime = false;
	  break;
	}
      }
      if( prime ) puts("P");
      else puts("C");
    } else if( a==0){
      if( !crivo[abs(b)] && abs(b) % 4 == 3) puts("P");
      else puts("C");
    } else {
      if( !crivo[abs(a)] && abs(a) % 4 == 3) puts("P");
      else puts("C");
    }
		
  }
  return 0;
}
