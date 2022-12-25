#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=105;
int board[MAX][MAX];//存储游戏板信息
int best[MAX][MAX];//存储最好分数
int main() {
    int n, r, c;//游戏板数n，游戏板的行数r和列数c
    scanf("%d", &n);
    for(int t=1; t<=n; t++) {
        scanf("%d %d", &r, &c);
        //读取游戏板中信息
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                //将pacman的起点和终点标记为0
                if((!i && !j) || (i==r-1 && j==c-1)) {
                    char temp;
                    scanf(" %c", &temp);
                    board[i][j]=0;
                }
                else
                    scanf("%d", &board[i][j]);
            }
        }
        memset(best, 0, sizeof(best));
        //填写第一行的最好分数
        for(int i=1; i<c; i++)
            best[0][i]=best[0][i-1]+board[0][i];
        //填写第一列的最好分数
        for(int i=1; i<r; i++)
            best[i][0]=best[i-1][0]+board[i][0];
        //循环遍历每个可能的Pac Man子问题并解决它
        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                best[i][j]=max(best[i-1][j], best[i][j-1])+board[i][j];
            }
        }
        //输出最终结果
        printf("Game Board #%d: %d\n", t, best[r-1][c-1]);
        if(t<n) printf("\n");
    }
    return 0;
}
