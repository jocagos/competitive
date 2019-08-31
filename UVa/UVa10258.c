#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXBUF 50
typedef struct {
    int id, ac, time;
} contestant;
int cmp(const void * left, const void * right) {
    contestant *a, *b;
    a = (contestant *) left, b = (contestant *) right;
    if(a->ac != b->ac)
        return b->ac - a->ac;
    if(a->time != b->time)
        return a->time - b->time;
    return a->id - b->id;
}
int main() {
    int t, i, j;
    char line[MAXBUF], cmd[10];
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--){
        int scoreboard[101][10] = {};
        int ac_board[101][10] = {}, app[101] = {};
        int team, prob, time;
        while(fgets(line, MAXBUF, stdin)){
            if(!strcmp(line, ""))
                break;
            sscanf(line, "%d %d %d %s", &team, &prob, &time, cmd);
            app[team] = 1;
            if(cmd[0] == 'I'){
                if(ac_board[team][prob] == 1) continue;
                scoreboard[team][prob] += 20;
            }
	    else if(cmd[0] == 'C'){
                if(ac_board[team][prob] == 1) continue;
                ac_board[team][prob] = 1;
                scoreboard[team][prob] += time;
            }
        }
        contestant out[100];
        int Idx = 0;
        for(i = 1; i <= 100; i++) {
            if(app[i]) {
                out[Idx].id = i;
                out[Idx].ac = 0;
                out[Idx].time = 0;
                for(j = 0; j < 10; j++) {
                    if(ac_board[i][j]) {
                        out[Idx].ac++;
                        out[Idx].time += scoreboard[i][j];
                    }
                }
                Idx++;
            }
        }
        qsort(out, Idx, sizeof(contestant), cmp);
        for(i = 0; i < Idx; i++)
            printf("%d %d %d\n", out[i].id, out[i].ac, out[i].time);
        if(t)
            printf("\n");
    }
    return 0;
}
