// UVa 11661 - Burger Time?
#include <iostream>

using namespace std;

int main(){
    int l = -1, d, min;
    char c;
    string s;
    while( l ){
        cin >> l;
        min = l;
        d = 0;
        c = '.';
        if( !l ) break;
        cin >> s;
        for( auto it = s.begin(); it != s.end(); it++ ){
            if( *it == 'Z' ){
                min = 0;
                break;
            }
            if( *it == 'R'){
                if( c == 'D' )
                    if( d < min )
                        min = d;
                d = 1;
                c = 'R';
                continue;
            }
            if( *it == 'D'){
                if( c == 'R' )
                    if( d < min )
                        min = d;
                d = 1;
                c = 'D';
                continue;
            }
            d++;
        }
        cout << min << endl;
    }
    return 0;
}