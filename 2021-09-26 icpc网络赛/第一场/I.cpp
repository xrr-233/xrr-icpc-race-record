#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct bignum
{
	int len,num[105];
	bool f;
	bignum operator + (const bignum &a,const char &b) const
	{
		bignum c=a;
		c.num[1]*=10;
		int i=1;
		while(c.num[i]/10!=0)
		{
			c.num[i+1]+=c.num[i]/10;
			c.num[i]%=10;
			i++;
		}
		whil(c.num[i]==0)
			i--;
		c.len=max(c.len,i);
		c.num[1]=b-'0';
	}
	bool operator <(const bignum &a,const bignum &b) const
	{
		if(a.f&&!b.f)
			return 1;
		if(!a.f&&b.f)
			return 0;
		if(a.f&&b.f)
		{
			if(a.len!=b.len)
				return a.len<b.len;
			for(int i=a.len;i>=1;i--)
				if(a.num[i]!=b.num[i])
					return a.num[i]<b.num[i];
			return 1;
		}
		if(!a.f&&!b.f)
		{
			if(a.len!=b.len)
				return a.len>b.len;
			for(int i=a.len;i>=1;i--)
				if(a.num[i]!=b.num[i])
					return a.num[i]>b.num[i];
			return 0;
		}
	}
	bignum():len(1),f(0)
	{
		memset(num,0,sizeof(num));
	}
}S[2e5+10];
bool cmp(bignum a, bignum b) {
	return b<a;
}
int main() {
	string s;
	getline(cin,s);
	bignum v=bignum();
	int size = 0,len=s.size();
	bool f = 0;
	for (int i = 0; i < len; i++) {
		if(s[i] != ' ') {
			if(s[i] == '-')
				v.f = 1;
			else {
				v = v+s[i];
			}
		}
		else {
			S[size++] = v;
			v=bignum();
		}
	}
	S[size++] = v;
	sort(S, S + size, cmp);
	
	long long a, r;
	cin >> a >> r;
	len = 0;
	for (int i = 0; i < size; i++) {
		if(S[i] <= a + r && S[i] >= a - r) {
			cout << S[i] << ' ';
			len++;
		}
	}
	return 0;
} 
//5 -6 8 9 -4 7 -3
