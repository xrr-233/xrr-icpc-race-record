#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;

unsigned greatestCommonFactor( unsigned a, unsigned b )
{
   if( 0 == b ) return a;

   return greatestCommonFactor( b, a % b );
}


bool areCoprime( unsigned a, unsigned b )
{
   unsigned gcf = greatestCommonFactor( a, b );
   return 1 == gcf;
}

int main()
{
    int numTickets;
    scanf("%d",&numTickets);
    bool foundCoprimes = 0;
    for(int Case = 1;Case <= numTickets;Case++)
    {
        printf("Ticket #%d:\n",Case);
        foundCoprimes = 0;
        string ticketDigit;
        ticketDigit.resize(10);
        scanf("%s",&ticketDigit[0]);
        for(int i = 1;i < ticketDigit.size();i++)
        {
            string leftstr,rightstr;
            leftstr = ticketDigit.substr(0,i);//分隔开左字串和右字串 
            rightstr = ticketDigit.substr(i);
            leftstr.c_str();rightstr.c_str();
            int leftnum = atoi(leftstr.c_str());//将分隔开的两个字符串转变成两个数字 
            int rightnum = atoi(rightstr.c_str());
            if(areCoprime(leftnum,rightnum))//判断两个数字是否不含有除1外的共同因子  
            {
                foundCoprimes = 1;
                printf("%d %d\n\n",leftnum,rightnum);
                break;
            }
        }
        if(!foundCoprimes) printf("Not relative\n\n");//每个数据之间要相隔一行 
    }
    return 0;
}
