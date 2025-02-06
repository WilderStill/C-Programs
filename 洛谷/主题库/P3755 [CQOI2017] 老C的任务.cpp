#include<bits/stdc++.h>
#define lowbit(x) (x)&(-x)
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=500004;
int n,m,len,clen,A[M],tr[M],ans[M];
struct moves
{
	int id,x,y,op,val;
	inline bool operator<(moves b){return x==b.x?id<b.id:x<b.x;}
}p[M];
inline void modify(int x,int v)
{
	for(int i=x;i<=len;i+=lowbit(i))tr[i]+=v;
	return;
}
inline int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}
signed main()
{	
	n=read(),m=read();
	for(int i=1;i<=n;++i)p[++clen]={0,read(),read(),0,read()};
	for(int i=1;i<=m;++i)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		p[++clen]={i,x2,y2,1,0};
		p[++clen]={i,x2,y1-1,-1,0};
		p[++clen]={i,x1-1,y2,-1,0};
		p[++clen]={i,x1-1,y1-1,1,0};
	}
	for(int i=1;i<=clen;++i)A[i]=p[i].y;
	sort(A+1,A+clen+1),sort(p+1,p+clen+1);
	len=unique(A+1,A+clen+1)-A-1;
	for(int i=1;i<=clen;++i)
	{
		int y=lower_bound(A+1,A+len+1,p[i].y)-A;
		if(!p[i].id)modify(y,p[i].val);
		else ans[p[i].id]+=query(y)*p[i].op;
	}
	for(int i=1;i<=m;++i)write(ans[i]),puts("");
	return 0;
}
