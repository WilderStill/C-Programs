#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline double qpow(double x,int y)
{
	double res=1.0;
	while(y)
	{
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
double f[5010][5010],p[5010],ans;
int t[5010];
int main()
{
	int n=read(),T=read();
	for(int i=1;i<=n;++i)p[i]=read()/100.0,t[i]=read();
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		double sum=0;
		for(int j=i;j<=T;++j)
		{
			sum=sum*(1-p[i])+f[i-1][j-1];
			if(j>t[i])sum-=f[i-1][j-t[i]-1]*qpow(1-p[i],t[i]);
			if(j>=t[i])f[i][j]+=f[i-1][j-t[i]]*qpow(1-p[i],t[i]);
			f[i][j]+=sum*p[i];
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=T;++j)ans+=f[i][j];
	printf("%lf",ans);
    return 0;
}

