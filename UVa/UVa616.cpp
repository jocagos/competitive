#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int n;
    char coconuts[] = " coconuts";
    char sol[] = " people and 1 monkey";
    char uns[] = " no solution";
    while( scanf("%d", &n), n >= 0 ){
        int n0, j = 0;
        bool valid = false;
        for( int i = (int)ceil(sqrt(n)); i >= 2; --i ){
            n0 = n;
            for( j = 0; j < i; ++j ){
                if( n0 % i != 1 ){
                    break;
                }
                n0 = n0 - n0/i -1;//(i-1) * (n0-1) / i;
            }
            if( j == i && n0 % i == 0 ){
                valid = true;
                printf("%d%s, %d%s\n", n, coconuts, i, sol);
                break;
            }
        }
        if( !valid ) printf("%d%s,%s\n", n, coconuts, uns);
    }
    return 0;
}