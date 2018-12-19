#include <iostream>

using namespace std;

int main(){
    int n, minnp = 1000000001, m, np = 0;
    long long sum = 0LL;
    cin >> n;
    for( int i = 0; i < n; ++i ){
        cin >> m;
        if( m % 2 ){
            np++;
            if( m < minnp ) minnp = m;
        }
        sum += m;
    }
    if( np % 2 ) sum -= minnp;
    cout << sum << endl;
    return 0;
}