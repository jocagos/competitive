// UVa 11679 - Sub Prime
#include <iostream>

using namespace std;

int res[20];

int main(){
    bool sn;
    int d, c, b = -1, n = -1, v;
    while( b != 0 ){
        sn = true;
        cin >> b >> n;
        if( !b ) break;
        for( int i = 0; i < b; ++i ) cin >> res[i];
        for( int i = 0; i < n; ++i ){
            cin >> d >> c >> v;
            res[d-1] -= v;
            res[c-1] += v;
        }
        for( int i = 0; i < b; ++i ){
            if( res[i] < 0 ){
                sn = false;
                break;
            }
        }
        if( sn ) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}