#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, k, a, b;
    cin >> n >> k;
    for( int i = 0; i < k; ++i ){
        cin >> a;
        if( !a ){ cout << i << endl; return 0;}
    }
    for( int i = k; i < n; ++i ){
        cin >> b;
        if( a != b ){ cout << i << endl; return 0; }
    }
    cout << n << endl;
    return 0;
}