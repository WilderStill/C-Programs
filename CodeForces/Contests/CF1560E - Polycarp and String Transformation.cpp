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
string s,s1,s2,s3;
int f[27],ans[110000],cnt;
bool fg=0;
int main()
{
	int T=read();
	while(T--)
	{
		s.clear();
		cin>>s;
		int len=s.size();
		for(int i=0;i<=26;++i)f[i]=0;
		fg=cnt=0;
		for(int i=len-1;i>=0;i--)
		{
			int c=s[i]-'a'+1;
		    if(!f[c])ans[++cnt]=c;
		    ++f[c];
		}
		int tmp=0;
		for(int i=1;i<=cnt;i++)
		{
		    if(f[ans[i]]%(cnt-i+1))
			{
				fg=1;
				break;
		    }
		    else tmp+=f[ans[i]]/(cnt-i+1);
		}
		if(fg)
		{
			puts("-1");
			continue;
		}
		s1.clear(),s2.clear();
		for(int i=0;i<tmp;i++)s1+=s[i];
		int now=cnt;
		while(s1.size())
		{
			s2+=s1;
			s3.clear();
			len=s1.size();
			for(int i=0;i<len;++i)
			    if(ans[now]!=s1[i]-'a'+1)
					s3+=s1[i];
			s1=s3;
			--now;
		}
		if(s2==s)
		{
			for(int i=0;i<tmp;++i)cout<<s[i];putchar(' ');
			for(int i=cnt;i;--i)putchar(ans[i]+'a'-1);puts("");
		}
		else puts("-1");
	}
	return 0;
}

