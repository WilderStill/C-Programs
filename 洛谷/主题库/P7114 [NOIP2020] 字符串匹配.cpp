#include<bits/stdc++.h>
#define M (1<<20)+5
#define lowbit(x) ((x)&(-x))
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
int tr[30],pre[30],suf[30],nxt[M];
void modify(int x)
{
	for(int i=x;i<=27;i+=lowbit(i))++tr[i];
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}
char s[M];
void qnxt(int len)
{
    nxt[1]=len;
    for(int i=2,l=0,r=0;i<=len;++i)
	{
        if(i<=r)nxt[i]=min(nxt[i-l+1],r-i+1);
        while(i+nxt[i]<=len&&s[i+nxt[i]]==s[nxt[i]+1])++nxt[i];
        if(i+nxt[i]-1>r)r=i+nxt[i]-1,l=i;
    }
}
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(tr,0,sizeof tr);
		memset(nxt,0,sizeof nxt);
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		scanf("%s",s+1);
		int n=strlen(s+1),all=0,hd=0,tl=0;
		qnxt(n);
		for(int i=1;i<=n;++i)
            if(i+nxt[i]-1==n)--nxt[i];
        for(int i=1;i<=n;++i)++suf[s[i]-'a'];
        for(int i=0;i<26;++i)if(suf[i]&1)++all;
        tl=all;
        long long ans=0;
        for(int i=1;i<=n;++i)
		{
			if(suf[s[i]-'a']&1)--tl;else ++tl;
            --suf[s[i]-'a'];
            if(pre[s[i]-'a']&1)--hd;else ++hd;
            ++pre[s[i]-'a'];
            if(i^1&&i^n)
			{
                int len=nxt[i+1]/i+1;
                ans+=1ll*(len>>1)*query(all+1)+1ll*(len-(len>>1))*query(tl+1);
            }
            modify(hd+1);
        }
        write(ans);
        puts("");
	}
	return 0;
}
