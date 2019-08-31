#include <iostream>

using namespace std;

int main(){
    int n, c = 0;
    char _c;
    cin >> n;
    string s;
    cin >> s;
    _c = s[0];
    for( int i = 1; i < s.size(); i++ ){
        if( _c == s[i] ) c++;
        else _c = s[i];
    }
    cout << c << endl;
    return 0;
}