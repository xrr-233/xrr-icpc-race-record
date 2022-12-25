#include <bits/stdc++.h>
using namespace std;


int map_id(int id) {
    if (id <= 48) {
        return 1;
    }
    id -= 48;
    if (id <= 8)
        return 2;
    id -=8;
    if (id <= 4)
        return 3;
    id -=4;
    if (id <= 2)
        return 4;
    id -=2;
    return 5;
}

int arr[5];
#define ll long long
ll m = 0;
int main() {
    int T, N;
    scanf("%d", &T);
    for (int t=  1;t<=T;t++) {
        m = 0;
        for (int i = 0;i<5;i++) scanf("%d", &arr[i]);
        scanf("%d", &N);
        for (int i =0;i<N;i++) {
            int curid;
            scanf("%d", &curid);
            m += arr[map_id(curid) -1];
        }
        printf("Case #%d: %lld\n", t, m * 10000);
    }

    return 0;
}

// by hyx 
