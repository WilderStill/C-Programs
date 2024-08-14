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
const int T=100001,F=-100001,U=0;
int n,m,fa[100010];
bool siv[200010];
int find(int x)
{
	if(x==T||x==F||x==U)return x;
	if(siv[n-x])return U;
	if(siv[x+n])return T;
	if(x<0)
	{
		if(x==-fa[-x])return x;
		else
		{
			siv[n+x]=1;
			int xfa=find(-fa[-x]);
			siv[n+x]=0;
			return xfa;
		}
	}
	else
	{
		if(x==fa[x])return x;
		else
		{
			siv[x+n]=1;
			int xfa=fa[x]=find(fa[x]);
			siv[x+n]=0;
			return xfa;
		}
	}
}
int main()
{
	int c=read(),t=read();
	while(t--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1,x,y;i<=m;++i)
		{
			char op[3];
			scanf("%s",op);
			x=read();
			switch(op[0])
			{
				case 'T':{fa[x]=T;break;}
				case 'F':{fa[x]=F;break;}
				case 'U':{fa[x]=U;break;}
				case '+':{y=read();fa[x]=fa[y];break;}
				case '-':{y=read();fa[x]=-fa[y];break;}
				default:break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(find(i)==U)++ans;
		}
		write(ans),putchar('\n');
	}
    return 0;
}

