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
char s[100005];
bitset<100005>ans,dg[26];
int main()
{
	scanf("%s",s+1);
	int T=read();
	int n=strlen(s+1);
	for(int i=1;i<=n;++i)dg[s[i]-'a'].set(i);
	for(int i=1;i<=T;++i)
	{
		int op=read();
		if(op==2)
		{
			string t;
			int l=read(),r=read();
			cin>>t;
			if(t.size()>r-l+1)
			{
				puts("0");
				continue;
			}
			ans.set();
			for(int i=0;i<t.size();++i)ans&=dg[t[i]-'a']>>i;
			write((ans>>l).count()-(ans>>r-t.size()+2).count());
			puts("");
		}
		else
		{
			int x=read();char y=getchar();
			while(!isalpha(y))y=getchar();
			dg[s[x]-'a'].reset(x);
			dg[(s[x]=y)-'a'].set(x);
		}
	}
	return 0;
}
