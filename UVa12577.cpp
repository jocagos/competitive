#include <iostream>
#define o_ios() ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
    string s;
    int i = 1;
    while( cin >> s, s.length() != 1 ){
        cout << "Case " << i++ << ": ";
        if( s == "Hajj" ) cout << "Hajj-e-Akbar" << endl;
        else cout << "Hajj-e-Asghar" << endl;
    }
    return 0;
}