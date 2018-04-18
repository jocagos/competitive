#include <stdio.h>

int main(){
    int n, i, p = 0, a, b, c;
    scanf("%d", &n);
    for( i = 0; i < n; ++i ){
        scanf("%d %d %d", &a, &b, &c);
        if( a & b || a & c || b & c ) p++;
    }
    printf("%d\n", p);
    return 0;
}