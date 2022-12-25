#include <bits/stdc++.h>
#define ll long long
#define G 3
using namespace std;
const int MAXN = 100010;
const ll mod = (1ll<<33)+1;
ll wn[MAXN*10],rev[MAXN*10];
ll bin(ll x,ll n,ll p){
	ll ret = p != 1;
	for(x%=p;n;n>>=1,x=x*x%p)
		if(n&1) ret = ret*x%p;
	return ret;
}
ll get_inv(ll x,ll p){return bin(x,p-2,p);}
int NTT_init(int n_){
	int step = 0;int n = 1;
	for(;n<n_;n<<=1) ++step;
	for(int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(step-1));
	ll g = bin(G,(mod-1)/n,mod); 
	wn[0] = 1;
	for(int i=1;i<=n;++i){
		wn[i] = wn[i-1]*g%mod;
	}
	return n;
}
void NTT(ll a[],int n,int f){
	for(int j=0;j<n;j++) if (j<rev[j])
		swap(a[j],a[rev[j]]);
	for(int k=1;k<n;k<<=1){
		for(int i=0;i<n;i+=(k<<1)){
			int t = n/(k<<1);
			for(int j=0;j<k;j++){
				ll w = f==1? wn[t*j]:wn[n-t*j];
				ll x = a[i+j];
				ll y = a[i+j+k]*w%mod;
				a[i+j] = (x+y)%mod;
				a[i+j+k] = (x-y+mod)%mod;
			}
		}
	}
	if(f == -1){
		ll ninv = get_inv(n,mod);
		for(int i=0;i<n;i++){
			a[i] = a[i]*ninv%mod;
		}
	}
}
ll s1[MAXN<<1],s2[MAXN<<1],s3[MAXN<<1];
int n;
int main(){
	freopen("test.in","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&s1[i]);
	for(int i=0;i<n;i++) scanf("%lld",&s2[i]);
	int nn = NTT_init(n<<1);
	printf("%d\n",nn);
	NTT(s1,nn,1);
	NTT(s2,nn,1);
	for(int i=0;i<nn;i++){	
		s3[i] = s1[i]*s2[i]%mod;
	}
	NTT(s3,nn,-1);
	for(int i=0;i<nn;i++) printf("%lld ",s3[i]);printf("\n");
	return 0;
}
