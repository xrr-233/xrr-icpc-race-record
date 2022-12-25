#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
   char dic[25];
   int len;
}dict[100];
int main()
{
   char sear[25];
   int cot;
   int n,m;
   scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",dict[i].dic);
        dict[i].len=strlen(dict[i].dic);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s",sear);
        printf("Word #%d: %s\n",i,sear);
        cot=0;
        int len=strlen(sear);

        for(int j=0;j<n;j++){
            if(dict[j].len==len){
                int k=0;
                for(k=0;k<len;k++){
                    if(dict[j].dic[k]!=sear[k]&&sear[k]!='-'){
                         break;
                    }
                }
                if(k==len)
                {
                    printf("%s\n",dict[j].dic);
                    cot++;
                }

            }

        }
        printf("Total number of candidate words = %d\n\n",cot);

    }

    return 0;
}