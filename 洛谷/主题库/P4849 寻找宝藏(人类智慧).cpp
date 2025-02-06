#include<bits/stdc++.h>
#define int long long
#define getchar getchar_unlocked
using namespace std;
const int mod=998244353;
inline int read()
{
	int x=0;
	char ch=getchar();
	while((ch<48)|(ch>57))ch=getchar();
	while((ch>=48)&(ch<=57))x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
	return x;
}
inline void write(int x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct node
{
	int a,b,c,d,val;
}dot[80004];
int n,m,ans,res,f[80004],cnt[80004];
inline bool cmp(node x,node y)
{
	if(x.a^y.a)return x.a<y.a;
	if(x.b^y.b)return x.b<y.b;
	if(x.c^y.c)return x.c<y.c;
	return x.d<y.d;
}
inline int pmod(int x){return x>=mod?x-mod:x;}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)dot[i]={read(),read(),read(),read(),read()};
	sort(dot+1,dot+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
        cnt[i]=1;
		for(int j=max(0,i-12000);j<i;++j)
        {
            if((dot[j].b<=dot[i].b)&(dot[j].c<=dot[i].c)&(dot[j].d<=dot[i].d))
            {
                if(f[i]==f[j])cnt[i]=pmod(cnt[i]+cnt[j]);
                if(f[i]<f[j])f[i]=f[j],cnt[i]=cnt[j];
            }
        }
        f[i]+=dot[i].val;
	}
    ans=*max_element(f+1,f+1+n);
    for(int i=1;i<=n;++i)if(f[i]==ans)res=pmod(res+cnt[i]);
    write(ans);
    putchar('\n');
	write(res);
	return 0;
}