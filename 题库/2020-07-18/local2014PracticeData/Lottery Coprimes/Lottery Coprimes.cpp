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
            leftstr = ticketDigit.substr(0,i);//�ָ������ִ������ִ� 
            rightstr = ticketDigit.substr(i);
            leftstr.c_str();rightstr.c_str();
            int leftnum = atoi(leftstr.c_str());//���ָ����������ַ���ת����������� 
            int rightnum = atoi(rightstr.c_str());
            if(areCoprime(leftnum,rightnum))//�ж����������Ƿ񲻺��г�1��Ĺ�ͬ����  
            {
                foundCoprimes = 1;
                printf("%d %d\n\n",leftnum,rightnum);
                break;
            }
        }
        if(!foundCoprimes) printf("Not relative\n\n");//ÿ������֮��Ҫ���һ�� 
    }
    return 0;
}
