// wtf this is faster than the other one
#include <bits/stdc++.h>
using namespace std;
int read( vector<int> * bit, int idx )
{
  int sum = 0;
  while( idx > 0 ){
    sum += bit->at(idx);
    idx -= (idx & -idx);
  }
  return sum;
}
void update( vector<int> * bit, int idx, int val )
{
  while( idx < bit->size() ){
    bit->at(idx) += val;
    idx += (idx & -idx);
  }
}

int main(){
  long long int n, total = 0, size = 0;
  scanf("%lld", &n);
  auto start = chrono::steady_clock::now();
  while(n){
    vector<long long> arr( n, 0 );
    if( n == 0 ) break;
    total = 0;
    size = 0;
    for( long long i = 0; i < n; ++i ){
      scanf("%lld", &arr[i]);
      size = max(size, arr[i]);
      // arr.push_back(num);
    }
    vector<int> tree(size+1, 0);
    for( int i = arr.size()-1; size > 0 && i >= 0; --i ){
      total += read( &tree, arr[i]-1);
      update(&tree, arr[i], 1);
    }
    printf("%s\n", (total % 2 == 0) ? "Carlos" : "Marcelo" );
    scanf("%lld", &n);
  }
  auto end = chrono::steady_clock::now();
  fprintf( stderr, "Took %llu nanoseconds\n", (unsigned long long)(chrono::duration_cast<chrono::nanoseconds>( end - start ).count() ) );
  return 0;
}
