#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,n) for(int i=1;i<=n;i++)
int n;
int a[1000005],b[1000005];
int c[5000005];
long long r[5000005];
int main(){
  cin >> n; rep2(i,n) scanf("%d%d",&a[i],&b[i]);
  for(int i=2;i<=5000000;i++){
    if(c[i]) continue;
    c[i] = 1;
    for(int j=2;i*j<=5000000;j++){
      int x = j*i;
      while(x%i==0){
	x/=i;
	c[i*j]++;
      }
    }
  }
  for(int i=2;i<=5000000;i++) r[i] = r[i-1]+c[i];
  rep2(i,n) printf("%lld\n",r[a[i]]-r[b[i]]);
}
