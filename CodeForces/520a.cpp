#include <iostream>
#include <cctype>

using namespace std;

int letters[26];

int main(){
    int n;
    string s;
    cin >> n >> s;
    if( n < 26 ){
        cout << "NO" << endl;
        return 0;
    }
    for( int i = 0; i < n; ++i ) letters[tolower(s.at(i)) - 'a']++;
    for( int i = 0; i < 26; ++i )
        if( !letters[i] ){
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}