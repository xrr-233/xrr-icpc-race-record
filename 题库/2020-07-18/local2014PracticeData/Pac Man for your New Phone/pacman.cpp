#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=105;
int board[MAX][MAX];//�洢��Ϸ����Ϣ
int best[MAX][MAX];//�洢��÷���
int main() {
    int n, r, c;//��Ϸ����n����Ϸ�������r������c
    scanf("%d", &n);
    for(int t=1; t<=n; t++) {
        scanf("%d %d", &r, &c);
        //��ȡ��Ϸ������Ϣ
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                //��pacman�������յ���Ϊ0
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
        //��д��һ�е���÷���
        for(int i=1; i<c; i++)
            best[0][i]=best[0][i-1]+board[0][i];
        //��д��һ�е���÷���
        for(int i=1; i<r; i++)
            best[i][0]=best[i-1][0]+board[i][0];
        //ѭ������ÿ�����ܵ�Pac Man�����Ⲣ�����
        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                best[i][j]=max(best[i-1][j], best[i][j-1])+board[i][j];
            }
        }
        //������ս��
        printf("Game Board #%d: %d\n", t, best[r-1][c-1]);
        if(t<n) printf("\n");
    }
    return 0;
}
