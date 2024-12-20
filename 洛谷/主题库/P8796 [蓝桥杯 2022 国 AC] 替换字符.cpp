#include<bits/stdc++.h>
#define lson rt<<1
#define rson rt<<1|1
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
char s[100010];
struct SegmentTree
{
	int l,r,tag[26];
	char val;
	void init(){for(int i=0;i<26;++i)tag[i]=i;}
}tr[400010];
inline void build(int rt,int l,int r)
{
	tr[rt].l=l;
	tr[rt].r=r;
	tr[rt].init();
	if(l==r)
	{
		tr[rt].val=s[l];
		return;
	}
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	return;
}
void pushdown(int rt)
{
	for(int i=0;i<26;++i)
	{
		tr[lson].tag[i]=tr[rt].tag[tr[lson].tag[i]];
		tr[rson].tag[i]=tr[rt].tag[tr[rson].tag[i]];
	}
	tr[rt].init();
}
void modify(int rt,int l,int r,char x,char y)
{
	if(tr[rt].l>r||tr[rt].r<l)return;
	if(tr[rt].l>=l&&tr[rt].r<=r)
	{
		for(int i=0;i<26;++i)
			if(tr[rt].tag[i]==x-'a')
				tr[rt].tag[i]=y-'a';
		return;
	}
	pushdown(rt);
	modify(lson,l,r,x,y);
	modify(rson,l,r,x,y);
}
void print(int rt)
{
	if(!tr[rt].l||!tr[rt].r)return;
	if(tr[rt].l==tr[rt].r)
	{
		putchar(tr[rt].tag[tr[rt].val-'a']+'a');
		return ;
	}
	pushdown(rt);
	print(lson);
	print(rson);
}
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),m=read();
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		char x[2],y[2];
		scanf("%s%s",x,y);
		modify(1,l,r,x[0],y[0]);
	}
	print(1);
	return 0;
}

