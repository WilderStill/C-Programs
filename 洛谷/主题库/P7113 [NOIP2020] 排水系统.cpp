#include<bits/stdc++.h>
#define M 114514
#define int __int128
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void print(int x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
int gcd(int m,int n)
{
	while(n)
	{
		int t=m%n;
		m=n,n=t;
	}
	return m;
}
vector<int>edge[M];
int n,m;
struct fraction
{
	int mom,son;
	void clear(){mom=0,son=0;}
	fraction operator + (const fraction x)
	{
		if(!mom) return x;
		fraction res;
		int lcm_=mom*x.mom/gcd(mom,x.mom);
		res.son=(x.son*(lcm_/x.mom)+son*(lcm_/mom)),res.mom=lcm_;
		int gcd_=gcd(res.son,res.mom);
		res.son/=gcd_,res.mom/=gcd_;
		return res;
	}
}ans[M],a[M];
void dfs(int x)
{
	if(edge[x].empty())
	{
		ans[x]=ans[x]+a[x];
		a[x].mom=1,a[x].son=0;
		return;
	}
	fraction tmp=a[x];
	tmp.mom*=edge[x].size();
	for(int i=0;i<edge[x].size();i++)
	{
		a[edge[x][i]]=a[edge[x][i]]+tmp;
		dfs(edge[x][i]);
	}
	a[x].clear();
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)ans[i].clear();
	for(int i=1,k;i<=n;i++)
	{
		k=read();
		for(int j=0,p;j<k;j++)p=read(),edge[i].push_back(p);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)a[j].clear();
		a[i].son=a[i].mom=1;
		dfs(i);
	}
	for(int i=1;i<=n;i++)
		if(edge[i].empty())
		{
			print(ans[i].son);printf(" ");
			print(ans[i].mom);printf("\n");
		}
	return 0;
}

