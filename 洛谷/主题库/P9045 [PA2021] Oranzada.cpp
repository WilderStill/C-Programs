#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(long long x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,k,cnt,a[500050],vis[500050];
long long ans;
vector<int> tn,kb;
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	n=read(),k=read();
	if(k<=1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(!vis[a[i]])
		{
			cnt++;
			kb.push_back(i);
		}
		vis[a[i]]++;
		if(vis[a[i]]>=2&&i<=k)tn.push_back(i);
	}
	if(cnt<k)
	{
		puts("-1");
		return 0;
	}
	for(int i=0,j=0;i<tn.size();)
	{
		while(tn[i]>kb[j]&&j<kb.size())++j;
		ans+=kb[j]-tn[i];
		if(kb[j]<=k)swap(kb[j],tn[i]);
		else ++j,++i;
	}
	write(ans);
	return 0;
}
