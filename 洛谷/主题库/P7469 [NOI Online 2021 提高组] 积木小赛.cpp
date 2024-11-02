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
using ll=long long;
const int Base=127;
const ll mod=10000000000000061;
string s,t;
ll h[20000100],tot=-1;
int main()
{
	int n=read();
	cin>>s>>t;
	for(int i=0;i<n;++i)
	{
		ll v=0;
		int pos=0;
		for(int j=i;j<n;++j)
		{
			while(pos<n&&s[pos]!=t[j])++pos;
			if(pos>=n)break;
			++pos;
			v=(v*Base+t[j]-'a'+1)%mod;
			h[++tot]=v;
		}
	}
	sort(h,h+tot);
	tot=unique(h,h+tot)-h;
	write(tot);
	return 0;
}
