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
inline void write(int x)
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
int cnt,mp[1010][1010];
int ind[100010],oud[100010];
char sl[100100];
bool vis[100010];
void dfs(int pos)
{
	vis[pos]=0;
	for(int i=1;i<=26;++i)if(mp[pos][i]&&vis[i])dfs(i);
}
int main()
{
	int T=read();
	while(T--)
	{
		++cnt;
		memset(vis,0,sizeof vis);
		memset(mp,0,sizeof mp);
		memset(ind,0,sizeof ind);
		memset(oud,0,sizeof oud);
		int n=read(),rt=0,cnt1=0,cnt2=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",sl+1);
			int slen=strlen(sl+1),s=sl[1]-'a'+1,t=sl[slen]-'a'+1;
			++mp[s][t],++mp[t][s]; 
			++oud[s],++ind[t]; 
			vis[s]=1,vis[t]=1;
			rt=t;
		}
		bool fg=0;
		for(int i=1;i<=26;++i)
		{
			if(oud[i]^ind[i])
			{
				if(oud[i]-ind[i]==1)++cnt1,rt=i;
				else if(ind[i]-oud[i]==1)++cnt2;
				else
				{
					fg=1;
					break;
				}
			}
		}
		dfs(rt);
		for(int i=1;i<=26;++i)
			if(vis[i])
			{
				fg=1;
				break;
			}
		if(!fg)fg=!((cnt1==cnt2&&cnt1==1)||(cnt1==cnt2&&cnt1==0));
		if(!fg)puts("Ordering is possible.");
		else puts("The door cannot be opened.");
	}
	return 0; 
}
