#include <iostream>
#define o_ios() ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        int l = s.length();
        if( s == "1" || s == "4" || s == "78" ) cout << "+" << endl;
        else if( s[l-1] == '5' && s[l-2] == '3' ) cout << "-" << endl;
        else if( s[0] == '9' && s[l-1] == '4' ) cout << "*" << endl;
        else if( s[0] == '1' && s[1] == '9' && s[2] == '0' ) cout << "?" << endl;
        else cout << "?" << endl;
    }
    return 0;
}