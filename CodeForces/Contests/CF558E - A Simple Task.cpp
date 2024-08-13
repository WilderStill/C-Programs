#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 100005
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
char s[M],ans[M];
struct node
{
	int l,r,cnt,tag;
}tree[27][M<<3];
void build(int rt,int l,int r,int id)
{
	tree[id][rt].l=l;
	tree[id][rt].r=r;
	tree[id][rt].tag=-1;
	if(l==r)
	{
		tree[id][rt].cnt=(s[l]==id+'a');
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid,id);
	build(rson,mid+1,r,id);
	tree[id][rt].cnt=tree[id][lson].cnt+tree[id][rson].cnt;
}
void update(int rt,int id)
{
	if(~tree[id][rt].tag)
	{
		tree[id][lson].tag=tree[id][rson].tag=tree[id][rt].tag;
		tree[id][lson].cnt=tree[id][lson].tag*(tree[id][lson].r-tree[id][lson].l+1);
		tree[id][rson].cnt=tree[id][rson].tag*(tree[id][rson].r-tree[id][rson].l+1);
		tree[id][rt].tag=-1;
	}
}
void modify(int rt,int l,int r,int val,int id)
{
	if(l<=tree[id][rt].l&&tree[id][rt].r<=r)
	{
		tree[id][rt].tag=val;
		tree[id][rt].cnt=val*(tree[id][rt].r-tree[id][rt].l+1);
		return;
	}
	update(rt,id);
	if(l<=tree[id][lson].r)modify(lson,l,r,val,id);
	if(tree[id][rson].l<=r)modify(rson,l,r,val,id);
	tree[id][rt].cnt=tree[id][lson].cnt+tree[id][rson].cnt;
}
int query(int rt,int l,int r,int id)
{
	if(l<=tree[id][rt].l&&tree[id][rt].r<=r)return tree[id][rt].cnt;
	update(rt,id);
	int res=0;
	if(l<=tree[id][lson].r)res+=query(lson,l,r,id);
	if(tree[id][rson].l<=r)res+=query(rson,l,r,id);
	return res;
}
void syh(int rt,int id)
{
	if(tree[id][rt].l==tree[id][rt].r)
	{
		if(tree[id][rt].cnt==1)ans[tree[id][rt].l]='a'+id;
		return;
	}
	update(rt,id);
	syh(lson,id);
	syh(rson,id);
}
int main()
{
	int n=read(),q=read();
	scanf("%s",s+1);
	for(int i=0;i<26;++i)build(1,1,n,i);
	while(q--)
	{
		int l=read(),r=read(),op=read();
		if(op==1)
		{
			int tmp=l,len;
			for(int i=0;i<26;++i)
			{
				len=query(1,l,r,i);
				if(!len)continue;
				modify(1,l,r,0,i);
				modify(1,tmp,tmp+len-1,1,i);
				tmp+=len;
			}
		}
		else
		{
			int tmp=r,len;
			for(int i=0;i<26;++i)
			{
				len=query(1,l,r,i);
				if(!len)continue;
				modify(1,l,r,0,i);
				modify(1,tmp-len+1,tmp,1,i);
				tmp-=len;
			}
		}
	}
	for(int i=0;i<26;++i)syh(1,i);
	for(int i=1;i<=n;++i)putchar(ans[i]);
	return 0;
}

