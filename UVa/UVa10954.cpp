#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using minHeapP = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag, std::allocator<T>>;
template <class T> using minHeapF = __gnu_pbds::priority_queue<T, greater<T>, thin_heap_tag, std::allocator<T>>;
template <class T> using minHeapBinomial = __gnu_pbds::priority_queue<T, greater<T>, binomial_heap_tag, std::allocator<T>>;
template <class T> using minHeapBinomial2 = __gnu_pbds::priority_queue<T, greater<T>, rc_binomial_heap_tag, std::allocator<T>>;
template <class T> using minHeapBinary = __gnu_pbds::priority_queue<T, greater<T>, binary_heap_tag, std::allocator<T>>;
using namespace chrono;

int main(){
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n/*scanf("%d", &n)*/, n ){
    long cost = 0;
    vector<int> values( n );
    // fill values, test times later
    for( int i = 0; i < n; ++i ) cin >> values[i];
    auto first = system_clock::now();
    minHeapP<int> addPairing( values.begin(), values.end() );
    auto second = system_clock::now();
    auto elapsedPairing = duration_cast<nanoseconds>( second - first );
    minHeapF<int> addFibonacci( values.begin(), values.end() );
    first = system_clock::now();
    auto elapsedFibonacci = duration_cast<nanoseconds>( first - second );
    minHeapBinomial<int> addBinomial( values.begin(), values.end() );
    second = system_clock::now();
    auto elapsedBinomial = duration_cast<nanoseconds>( second - first );
    minHeapBinomial2<int> addBinomial2( values.begin(), values.end() );
    first = system_clock::now();
    auto elapsedBinomial2 = duration_cast<nanoseconds>( first - second );
    minHeapBinary<int> addBinary( values.begin(), values.end() );
    second = system_clock::now();
    auto elapsedBinary = duration_cast<nanoseconds>( second - first );
    std::priority_queue<int, vector<int>, greater<int>> add( values.begin(), values.end() );
    first = system_clock::now();
    auto elapsedStd = duration_cast<nanoseconds>( first - second );
    cout << "Measuring times for " << n << " elements (construction):\n\n";
    cout << "PAIRING HEAP:\t" << elapsedPairing.count() << "\tnanoseconds\n";
    cout << "THIN HEAP:\t" << elapsedFibonacci.count() << "\tnanoseconds\n";
    cout << "BINOMIAL HEAP:\t" << elapsedBinomial.count() << "\tnanoseconds\n";
    cout << "RC_BINOMIAL HEAP:\t" << elapsedBinomial2.count() << "\tnanoseconds\n";
    cout << "BINARY HEAP:\t" << elapsedBinary.count() << "\tnanoseconds\n";
    cout << "STD HEAP:\t" << elapsedStd.count() << "\tnanoseconds\n";
    cout << "---\nNow timing the use of it:\n";
    first = system_clock::now();
    while( add.size() >= 2 ){
      int p = add.top(), q;
      add.pop();
      q = add.top();
      add.pop();
      cost += p+q;
      add.push(p+q);
    }
    second = system_clock::now();
    elapsedStd = duration_cast<nanoseconds>( second - first );
    while( addPairing.size() >= 2 ){
      int p = addPairing.top(), q;
      addPairing.pop();
      q = addPairing.top();
      addPairing.pop();
      cost += p+q;
      addPairing.push(p+q);
    }
    first = system_clock::now();
    elapsedPairing = duration_cast<nanoseconds>( first - second );
    while( addBinomial.size() >= 2 ){
      int p = addBinomial.top(), q;
      addBinomial.pop();
      q = addBinomial.top();
      addBinomial.pop();
      cost += p+q;
      addBinomial.push(p+q);
    }
    second = system_clock::now();
    elapsedBinomial = duration_cast<nanoseconds>( second - first );
    while( addBinomial2.size() >= 2 ){
      int p = addBinomial2.top(), q;
      addBinomial2.pop();
      q = addBinomial2.top();
      addBinomial2.pop();
      cost += p+q;
      addBinomial2.push(p+q);
    }
    first = system_clock::now();
    elapsedBinomial2 = duration_cast<nanoseconds>( first - second );
    while( addBinary.size() >= 2 ){
      int p = addBinary.top(), q;
      addBinary.pop();
      q = addBinary.top();
      addBinary.pop();
      cost += p+q;
      addBinary.push(p+q);
    }
    second = system_clock::now();
    elapsedBinary = duration_cast<nanoseconds>( second - first );
    while( addFibonacci.size() >= 2 ){
      int p = addFibonacci.top(), q;
      addFibonacci.pop();
      q = addFibonacci.top();
      addFibonacci.pop();
      cost += p+q;
      addFibonacci.push(p+q);
    }
    first = system_clock::now();
    elapsedFibonacci = duration_cast<nanoseconds>( first - second );
    cout << "RESULTS FOR CONSTANT USE OF POP AND PUSH:\n";
    cout << "PAIRING HEAP:\t" << elapsedPairing.count() << "\tnanoseconds\n";
    cout << "THIN HEAP:\t" << elapsedFibonacci.count() << "\tnanoseconds\n";
    cout << "BINOMIAL HEAP:\t" << elapsedBinomial.count() << "\tnanoseconds\n";
    cout << "RC_BINOMIAL HEAP:\t" << elapsedBinomial2.count() << "\tnanoseconds\n";
    cout << "BINARY HEAP:\t" << elapsedBinary.count() << "\tnanoseconds\n";
    cout << "STD HEAP:\t" << elapsedStd.count() << "\tnanoseconds\n";
    cout << "---\n";
    // printf("%ld\n", cost);
  }
  return 0;
}
