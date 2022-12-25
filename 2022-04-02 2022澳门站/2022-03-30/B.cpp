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
const LL mod = 1e9 + 7;
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
LL fp[N],a[N];
int n;
struct node{
    int id;
    int num[N];
    bool operator <(const node &a)const{
        for(int j = 100000;j >= 0;j--)
            if(num[j] != a.num[j])
            return num[j] > a.num[j];
        return 0;
    }
}p[26];
string s[N];
bool vis[26];
int main(){
    fp[0] = 1;
    for(int i = 1;i <= 100000;i++) fp[i]=(fp[i - 1] * 26) % mod;
    int tmp = 0;
    while(scanf("%d",&n)!=EOF){
        for(int i = 0;i < 26;i++){
           for(int j = 0; j <= 100000; j++) p[i].num[j] = 0;
           p[i].id = i;
           vis[i] = 0;
        }
        for(int i = 0;i < n;i++){
            cin>>s[i];
            int len = s[i].size();
            if(len > 1) vis[s[i][0]-'a']=1;
            for(int k = len - 1,j = 0;k >= 0;k--,j++){
                int t = s[i][k] - 'a';
                p[t].num[j]++;
            }
        }
        for(int i = 0;i < 26;i++){
            for(int j = 0;j <= 100000;j++){
                p[i].num[j + 1] += p[i].num[j] / 26;
                p[i].num[j] %= 26;
            }
        }
        sort(p,p + 26);
        for(int i = 25;i >= 0;i--) a[p[25-i].id]=i;

        int t = 25;
        while(vis[p[t].id] && t){
            swap(a[p[t].id],a[p[t - 1].id]);
            t--;
        }
        LL ans = 0;
        for(int i = 0;i < n;i++){
            int len = s[i].size();
            for(int j = 0;j < len;j++){
                ans = (ans + a[s[i][j]-'a'] * fp[len - 1 - j] % mod) % mod;
            }
        }
        printf("Case #%d: %lld\n",++tmp,ans);
    }
    return 0;
}
