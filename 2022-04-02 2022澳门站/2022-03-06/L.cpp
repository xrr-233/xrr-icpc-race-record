#include <bits/stdc++.h>
using namespace std;


int T;
string cur;

string pst1 = string("01:59:59"); // 2nd Sunday of March
string pst2 = string("02:59:59");

string pdt1 = string("00:59:59"); // 1st Sunday of November
string pdt2 = string("01:59:59");



// String wk_list[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
// int Y = yr.toInt();
// int M = mon.toInt();
// int D = da.toInt();
// int ind = (D + 2*M + 3*(M+1)/5 + Y + Y/4 - Y/100 + Y/400) % 7;

int main() {
    scanf("%d", &T);
    getchar();
    for (int t= 1;t<=T;t++) {
        getline(cin, cur);
        int Y = 0;
        int M = 0;
        int D = 0;
        for (int i = 0;i<10;i++) {
            if (i < 4  )
                Y = 10 * Y + (cur[i] - '0');
            else if (i < 7 && i >= 5)
                M= 10 * M  + (cur[i] - '0');
            else if (i >= 8)
                D = 10 * D + (cur[i] - '0');
        }
        printf("Case #%d: ", t);
        if (M < 3 || M == 12) {
            printf("PST\n");
            continue;
        }
        if (M >= 4 && M <= 10) {
            printf("PDT\n");
            continue;
        }
        int const MY = 2 * M + 3*(M+1)/5 + Y + Y / 4 - Y/100 + Y/400;
        string nycur = string(cur, 11, cur.length() - 11);
        if (M == 3) {
            // cal the 2nd Sunday of March
            int i = 1;
            for (;i<=31;i++) {
                if  ((i + MY)%7 == 6) {
                    i+=7;
                    break;
                }
            }
            if (D < i) {
                printf("PST\n");
                continue;
            }
            else if (D > i) {
                printf("PDT\n");
                continue;
            }
            if (nycur <= pst1) {
                printf("PST\n");
            }
            else if (nycur.compare(pst2) <=0) {
                printf("Neither\n");
            }
            else {
                printf("PDT\n");
            }
        }
        else {
            int i = 1;
            for (;i<=31;i++) {
                if  ((i + MY)%7 == 6) {
                    break;
                }
            }
            if (D < i) {
                printf("PDT\n");
                continue;
            }
            else if (D > i) {
                printf("PST\n");
                continue;
            }
            
            if (nycur.compare(pdt1) <= 0) {
                printf("PDT\n");
            }
            else if (nycur.compare(pdt2) <= 0){
                printf("Both\n");
            }
            else {
                printf("PST\n");
            }
        }

    }
    return 0;
}
/*
 
4
2016-03-13 01:59:59
2016-03-13 02:00:00
2016-11-06 00:59:59
2016-11-06 01:00:00

 */
