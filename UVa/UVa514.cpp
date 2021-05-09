#include <cstdio>
#include <stack>

using namespace std;
constexpr int MAXN = 1010;

int main(){
  int n {};
  int arr[MAXN] {};
  while( scanf("%d", &n), n ){
    int tmp {}, idx {};
    while( scanf("%d", &tmp), tmp ){ // look for the 0 to finish input
      stack<int> st {};
      arr[0] = tmp;
      for( int i = 1; i < n; ++ i )
	scanf("%d", &(arr[i]));
      idx = 0;
      tmp = 1;
      while( tmp <= n ){
	if( not st.empty() ){
	  if( st.top() == arr[idx] ){
	    st.pop();
	    ++ idx;
	    continue;
	  }
	}
	st.push( tmp );
	++ tmp;
      }
      while( not st.empty() ){
	if( idx >= n ) break;
	if( st.top() == arr[idx] ){
	  st.pop();
	  idx ++;
	}
	else
	  break;
      }
      if( st.empty() )
	printf("Yes\n");
      else
	printf("No\n");
    }
    printf("\n");
  }
  return 0;
}
