#include <iostream>
#include <string>
#define o_ios() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main(){
    //o_ios();
    string s;
    int n = 0, t;
    scanf("%d", &t);
    while(t--){
        getline(cin, s);
        if(s.empty()) { t++; continue;} //Dude wtf why does it read an empty line wut
        if( s.length() == 6) cout << n << endl;
        else //retrieve k
            n += stoi(s.substr(7));
    }
    return 0;
}