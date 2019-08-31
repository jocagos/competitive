#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int m, n, t = 1;
    scanf("%d %d ", &m, &n );
    while(m || n)
    {
        string line;
        int board[m][n];
        memset( board, 0, sizeof board);
        for (int i = 0; i < m; ++i)
        {
            getline(cin, line);
            for (int j = 0; j < n; ++j)
            {
                if (line[j] == '*')
                {
                    board[i][j] = '*';
                    if (i >= 1)
                    {
                        if (j >= 1)
                        {
                            board[i - 1][j - 1] += (board[i - 1][j - 1] != '*' ? 1 : 0);
                        }
                        if (j < n - 1)
                        {
                            board[i - 1][j + 1] += (board[i - 1][j + 1] != '*' ? 1 : 0);
                        }
                        board[i - 1][j] += (board[i - 1][j] != '*' ? 1 : 0);
                    }
                    if (i < m - 1)
                    {
                        if (j >= 1)
                        {
                            board[i + 1][j - 1] += (board[i + 1][j - 1] != '*' ? 1 : 0);
                        }
                        if (j < n - 1)
                        {
                            board[i + 1][j + 1] += (board[i + 1][j + 1] != '*' ? 1 : 0);
                        }
                        board[i + 1][j] += (board[i + 1][j] != '*' ? 1 : 0);
                    }
                    if (j >= 1)
                    {
                        board[i][j - 1] += (board[i][j - 1] != '*' ? 1 : 0);
                    }
                    if (j < n - 1)
                    {
                        board[i][j + 1] += (board[i][j + 1] != '*' ? 1 : 0);
                    }
                }
            }
        }
        printf("Field #%d:\n", t++);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == '*')
                    printf("%c", (char)board[i][j]);
                else
                    printf("%d", board[i][j]);
            }
            printf("\n");
        }
        scanf("%d %d ", &m, &n );
        if( m || n ) printf("\n");
    }
    return 0;
}
