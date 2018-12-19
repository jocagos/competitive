#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for( auto i = 1; i < n; ++i ){
        if( i % 2 ) cout << "I hate that ";
        else if( !(i % 2) ) cout << "I love that ";
    }
    cout << (n % 2 ? "I hate it" : "I love it") << endl;
    return 0;
}