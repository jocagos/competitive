#include <iostream>

using namespace std;

constexpr int MAXN = 1000100; // 1e6 + 100
int arr[MAXN] {}, brr[MAXN] {};

long long merge( int left, int mid, int right ){
  int i {}, j {}, k {};
  long long inv {};

  i = left; // left subarray
  j = mid; // right subarray
  k = left; // merged subarray
  while( (i <= mid - 1) and (j <= right) ){
    if( arr[i] <= arr[j] )
      brr[k++] = arr[i++];
    else{
      brr[k++] = arr[j++];
      inv = inv + (mid - i);
    }
  }
  while( i <= mid - 1 )
    brr[k++] = arr[i++];
  while( j <= right )
    brr[k++] = arr[j++];
  for( i = left; i <= right; ++ i )
    arr[i] = brr[i];
  return inv;
}

inline long long merge_sort( int l, int r ){
  int mid {};
  long long inv {};
  if( r > l ){
    mid = (r + l)/2;
    inv += merge_sort( l, mid );
    inv += merge_sort( mid + 1, r );
    inv += merge( l, mid + 1, r );
  }
  return inv;
}

inline long long inv_count( int n ){
  return merge_sort( 0, n - 1 );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i )
      cin >> arr[i];
    cout << inv_count( n ) << '\n';
  }
  return 0;
}
