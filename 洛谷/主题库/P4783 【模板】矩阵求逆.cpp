#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll coef[444][844],n;
static ll sta[36];
inline ll read(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
inline void write(ll x) {
    int top=0;
    do{
    	sta[top++]=x%10,x/=10;
    }while(x);
    while(top)putchar(sta[--top]+48);
}
inline ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%1000000007ll;
		y>>=1;
		x=x*x%1000000007ll;
	}
	return res%1000000007ll;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            coef[i][j]=read(),coef[i][i+n]=1;
    for(int i=1;i<=n;++i)
	{
        int maxn=i;
        for(int j=i+1;j<=n;++j)if(coef[maxn][i]<coef[j][i])maxn=j;
		if(!coef[maxn][i])
		{
            puts("No Solution");
            return 0;
        }
		if(maxn!=i)swap(coef[i],coef[maxn]);
        ll tmp=qpow(coef[i][i],1000000005ll);
        for(int j=1;j<=n;++j)
		{
			if(i==j)continue;
            ll kp=coef[j][i]*tmp%1000000007ll;
            for(int k=i;k<=2*n;++k)coef[j][k]=(coef[j][k]-kp*coef[i][k]%1000000007ll+1000000007ll)%1000000007ll;
        }
        for(int j=1;j<=2*n;++j)coef[i][j]=coef[i][j]*tmp%1000000007ll;
    }
    for(int i=1;i<=n;++i)
    {
    	for(int j=1;j<=n;++j)write(coef[i][j+n]),putchar(' ');
    	putchar('\n');
	}
}
