#include<bits/stdc++.h>
#define ll long long
#define M 21341521
using namespace std;
struct node_to_exkmp
{
    int len;
	ll nxt[M],ext[M];
    char str[M];
    void qnxt(char s[])
	{
		len=strlen(s+1);
        nxt[1]=len,str[1]=s[1];
        for(int i=2,l=0,r=0;i<=len;++i)
		{
            str[i]=s[i];
            if(i<=r)nxt[i]=min(nxt[i-l+1],r-i+1ll);
            while(i+nxt[i]<=len&&s[i+nxt[i]]==s[nxt[i]+1])++nxt[i];
            if(i+nxt[i]-1>r)r=i+nxt[i]-1,l=i;
        }
    }
    void exkmp(char s[])
	{
		int len2=strlen(s+1);
        for(int i=1,l=0,r=0;i<=len2;++i)
		{
            if(i<=r)ext[i]=min(nxt[i-l+1],r-i+1ll);
            while(i+ext[i]<=len2&&s[i+ext[i]]==str[ext[i]+1])++ext[i];
            if(i+ext[i]-1>r)r=i+ext[i]-1,l=i;
        }
    }
}boxx;
char a[M],b[M];
int main()
{
	scanf("%s%s",a+1,b+1);
	boxx.qnxt(b);
	boxx.exkmp(a);
	ll ans=0;
	for(int i=1;i<=(int)strlen(b+1);++i)ans^=i*(boxx.nxt[i]+1);
	printf("%lld\n",ans);
	ans=0;
	for(int i=1;i<=(int)strlen(a+1);++i)ans^=i*(boxx.ext[i]+1);
	printf("%lld",ans);
    return 0;
}
