#include <stdio.h>

int main()
{
    int a, b, c, d, deg;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while( a != 0 || b != 0 || c != 0 || d != 0)
    {
        deg = 1080 + (b > a ? 40 - b + a : a - b) * 9 + (c < b ? 40 - b + c : c - b) * 9 + (d > c ? 40 - d + c : c - d) * 9;
        printf("%d\n", deg);
        scanf("%d %d %d %d", &a, &b, &c, &d);
    }
    return 0;
}
