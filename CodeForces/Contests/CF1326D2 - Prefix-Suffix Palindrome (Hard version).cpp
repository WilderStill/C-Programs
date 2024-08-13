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
int manacher(char*raw,int len)
{
	string str="$#";
	for(int i=1;i<=len;++i)str+=raw[i],str+="#";
	vector<int>plen;
	plen.push_back(1);
	int mid=0,maxn=0,maxlen=1;
	for(int l=1;l<(int)str.size();++l)
	{
		plen.push_back((maxn>l)?min(maxn-l,plen[mid*2-l]):1);
		while(l+plen[l]<(int)str.size()&&str[l+plen[l]]==str[l-plen[l]])++plen[l];
		if(l==plen[l])maxlen=max(maxlen,plen[l]);
		if(plen[l]+l>maxn)
		{
			maxn=plen[l]+l;
			mid=l;
		}
	}
	return maxlen-1;
}
int m;
char s[10001000],t[10001000];
void solve()
{
	scanf("%s",s+1);
	int n=strlen(s+1),p=1;
	while(p<=n&&s[p]==s[n+1-p])++p;
	if(p==n+1)
	{
		for(int i=1;i<=n;++i)putchar(s[i]);
		puts("");
		return;
	}
	m=0;
	for(int i=p;i<=n+1-p;++i)t[++m]=s[i];
	int l=manacher(t,m);
	reverse(t+1,t+m+1);
	int r=manacher(t,m);
	reverse(t+1,t+m+1);
	if(l<r)reverse(t+1,t+m+1),swap(l,r);
	for(int i=1;i<p;++i)putchar(s[i]);
	for(int i=1;i<=l;++i)putchar(t[i]);
	for(int i=p-1;i;--i)putchar(s[i]);
	puts("");
}
int main()
{
	int T=read();
	while(T--)
	{
		solve();
	}
	return 0;
}

