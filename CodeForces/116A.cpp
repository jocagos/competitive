#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, a, b, m = 0, s = 0;
    scanf("%d", &n);
    for( int i = 0; i < n; ++i ){
        scanf("%d %d", &a, &b);
        s += b-a;
        m = max(m, s);
    }
    printf("%d\n", m);
    return 0;
}