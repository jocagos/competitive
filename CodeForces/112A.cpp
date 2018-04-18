#include <iostream>

using namespace std;

int main(){
    string a, b;
    cin >> a;
    cin >> b;
    for( int i = 0; i < a.size(); ++i ){
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }
    cout << (a.compare(b) < 0 ? -1 : (a.compare(b) == 0 ? 0 : 1)) << endl;
    return 0;
}