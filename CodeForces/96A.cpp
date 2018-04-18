#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    bool danger = false;
    int bit = s[0], c = 1;
    for( int i = 0; i < s.size(); ++i ){
        if( c >= 7 ){ danger = true; break; }
        if( s[i] == bit ) c++;
        else c = 1, bit = s[i];
    }
    if( c >= 7 ) danger = true;
    if( danger ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}