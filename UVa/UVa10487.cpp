#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, cases = 1;
  while( scanf("%d", &n), n ){
    printf("Case %d:\n", cases++);
    vector<int> v(n);
    for( int i = 0; i < n; ++i ) scanf("%d", &v[i]);
    sort( begin(v), end(v));
    int q, tmp;
    scanf("%d", &q);
    while( q-- ){
      scanf("%d", &tmp);
      int error = 0xffffff, ans = 0;
      for( int i = 0; i < n; ++ i ){
	for( int j = 0; j < n; ++ j ){
	  if( v[j] == v[i] ) continue;
	  int sum = v[i] + v[j];
	  if( abs(sum - tmp) < error ) ans = sum, error = abs(sum - tmp);
	}
      }
      printf("Closest sum to %d is %d\n", tmp, ans);
    }
  }
  return 0;
}

/*
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ll n,l=1;
    vector<ll>arr;
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
        {
            int p;
            cin>>p;
            arr.push_back(p);
        }
        ll m;
        cin>>m;
        printf("Case %lld:\n",l++);
        for(int i=0; i<m; i++)
        {
            ll a,mn=1e18,ans=0;
            cin>>a;
            for(int i=0; i<arr.size(); i++)
            {

                for(int j=i+1; j<arr.size(); j++)
                {
                    int sum=arr[i]+arr[j];
                    if(abs(sum-a)<mn)
                    {
                        ans=sum;
                        mn=abs(sum-a);
                    }

                }
            }
            printf("Closest sum to %lld is %lld.\n",a,ans);

        }
        arr.clear();
    }
    return 0;
}
*/
