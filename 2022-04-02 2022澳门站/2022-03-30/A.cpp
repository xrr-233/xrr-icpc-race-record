#define B cout << "BreakPoint" << endl;
#define O(x) cout << #x << " " << x << endl;
#define O_(x) cout << #x << " " << x << " ";
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
const int inf = 1e9 + 9;
const int N = 2e5 + 5;
using namespace std;
inline LL read() {
 LL s = 0,w = 1;
 char ch = getchar();
 while(ch < '0' || ch > '9') {
  if(ch == '-')
   w = -1;
  ch = getchar();
 }
 while(ch >= '0' && ch <= '9') {
  s = s * 10 + ch - '0';
  ch = getchar();
 }
 return s * w;
}
int m,tmp,k;
void init(){
    ++tmp;
    //O(log(2))
    k = int(m*log10(2));
    printf("Case #%d: %d\n",tmp,k);
}
int main(){
    while(cin >> m) init();
    return 0;
}
