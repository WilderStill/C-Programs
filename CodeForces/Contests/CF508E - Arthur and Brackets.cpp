#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;
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
inline void write(ll x)
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
ll n,l[114514],r[114514],p[114514];
char ansdg[114514];
bool fg;
stack<ll>syh;
int main()
{
	n=read();
	ll pcnt=0;
	for(ll i=1;i<=n;++i)
	{
		l[i]=read(),r[i]=read();
        syh.push(i);
        p[i]=pcnt;
        ansdg[++pcnt]='(';
        while(!syh.empty())
		{
            ll top=syh.top();
            if(r[top]+p[top]<pcnt){fg=1;break;}
            if(l[top]+p[top]>pcnt)break;
            ansdg[++pcnt]=')';
            syh.pop();    
        }
	}  
	if(syh.empty()&&!fg)puts(ansdg+1);
	else puts("IMPOSSIBLE");
	return 0;
}
