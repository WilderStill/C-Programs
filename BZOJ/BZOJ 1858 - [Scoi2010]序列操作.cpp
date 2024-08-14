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
int syh[200010];
namespace FHQ_Treap_Array
{
	int tot=0,root=0;
	struct node
	{
		int size,key,l,r,val,sum,tag,pre[2],suf[2],ans[2];
		bool rev;
	}tr[200010];
	int newnode(int v) 
	{
		++tot;
		tr[tot].size=tr[tot].val=v;
		tr[tot].pre[1]=tr[tot].suf[1]=tr[tot].ans[1]=v;
        tr[tot].pre[0]=tr[tot].suf[0]=tr[tot].ans[0]=!v;
		tr[tot].key=rand();
		tr[tot].size=1;
		return tot;
	}
	void update(int rt)
	{
		tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+1;
		tr[rt].sum=tr[tr[rt].l].sum+tr[tr[rt].r].sum+tr[rt].val;
        tr[rt].pre[1]=tr[tr[rt].l].pre[1];
        tr[rt].suf[1]=tr[tr[rt].r].suf[1];
        tr[rt].pre[0]=tr[tr[rt].l].pre[0];
        tr[rt].suf[0]=tr[tr[rt].r].suf[0];
        if(tr[rt].val&&tr[tr[rt].l].size==tr[tr[rt].l].sum)tr[rt].pre[1]=max(tr[rt].pre[1],tr[tr[rt].l].sum+tr[tr[rt].r].pre[1]+1);
        if(tr[rt].val&&tr[tr[rt].r].size==tr[tr[rt].r].sum)tr[rt].suf[1]=max(tr[rt].suf[1],tr[tr[rt].r].sum+tr[tr[rt].l].suf[1]+1);
        if(!tr[rt].val&&!tr[tr[rt].l].sum)tr[rt].pre[0]=max(tr[rt].pre[0],tr[tr[rt].l].size+tr[tr[rt].r].pre[0]+1);
        if(!tr[rt].val&&!tr[tr[rt].r].sum)tr[rt].suf[0]=max(tr[rt].suf[0],tr[tr[rt].r].size+tr[tr[rt].l].suf[0]+1);
        tr[rt].ans[0]=max(tr[tr[rt].l].ans[0],tr[tr[rt].r].ans[0]);
        tr[rt].ans[1]=max(tr[tr[rt].l].ans[1],tr[tr[rt].r].ans[1]);
        if(tr[rt].val)tr[rt].ans[1]=max(tr[rt].ans[1],tr[tr[rt].l].suf[1]+tr[tr[rt].r].pre[1]+1);
        if(!tr[rt].val)tr[rt].ans[0]=max(tr[rt].ans[0],tr[tr[rt].l].suf[0]+tr[tr[rt].r].pre[0]+1);
    }
    void push_k1(int rt)
    {
    	tr[rt].sum=tr[rt].size-tr[rt].sum;
        tr[rt].val^=1;
        swap(tr[rt].pre[0],tr[rt].pre[1]);
        swap(tr[rt].suf[0],tr[rt].suf[1]);
        swap(tr[rt].ans[0],tr[rt].ans[1]);
        tr[rt].rev^=1;
        tr[rt].tag=-tr[rt].tag;
	}
	void push_k2(int rt,int v)
	{
		tr[rt].val=v;
        tr[rt].sum=(v==1)?tr[rt].size:0;
        tr[rt].pre[1]=tr[rt].suf[1]=tr[rt].ans[1]=tr[rt].sum;
        tr[rt].pre[0]=tr[rt].suf[0]=tr[rt].ans[0]=tr[rt].size-tr[rt].sum;
        tr[rt].tag=(v==1)?1:-1;
	}
    void modify(int rt)
    {
    	if(tr[rt].rev)
		{
            if(tr[rt].l)push_k1(tr[rt].l);
            if(tr[rt].r)push_k1(tr[rt].r);
            tr[rt].rev=0;
        }
        if(tr[rt].tag)
		{
            int v=(tr[rt].tag==1)?1:0;
			if(tr[rt].l)push_k2(tr[rt].l,v);
            if(tr[rt].r)push_k2(tr[rt].r,v);
            tr[rt].tag=0;
        }
	}
	void split(int rt,int v,int&l,int&r)
	{
		if(!rt)
		{
			l=r=0;
			return;
		}
		modify(rt);
		if(tr[tr[rt].l].size<v)
		{
			l=rt;
	        split(tr[rt].r,v-tr[tr[rt].l].size-1,tr[rt].r,r);
	    }
	    else
		{
			r=rt;
	        split(tr[rt].l,v,l,tr[rt].l);
	    }
	    update(rt);
	}
	int merge(int l,int r) 
	{
		modify(l);modify(r);
		if(!l||!r)return l|r;
		if(tr[l].key<tr[r].key)
		{
	        tr[l].r=merge(tr[l].r,r);
	        update(l);
	        return l;
	    }
	    else
		{
	        tr[r].l=merge(l,tr[r].l);
	        update(r);
	        return r;
	    }
	}
	void reverse(int l,int r)
	{
        int x,y,z;
        split(root,l-1,x,y);
        split(y,r-l+1,y,z);
		push_k1(y);
        root=merge(merge(x,y),z);
	}
	void change(int l,int r,int v)
	{
        int x,y,z;
        split(root,l-1,x,y);
        split(y,r-l+1,y,z);
        push_k2(y,v);
        root=merge(merge(x,y),z);
    }
	int query_sum(int l,int r)
	{
        int x,y,z,res;
        split(root,l-1,x,y);
        split(y,r-l+1,y,z);
        res=tr[y].sum;
        root=merge(merge(x,y),z);
        return res;
    }
	int query_ans(int l,int r)
	{
        int x,y,z,res;
        split(root,l-1,x,y);
        split(y,r-l+1,y,z);
        res=tr[y].ans[1];
        root=merge(merge(x,y),z);
        return res;
    }
    int build(int l,int r)
	{
        if(l>r)return 0;
        int mid=(l+r)>>1,rt=newnode(syh[mid]);
        tr[rt].l=build(l,mid-1);
        tr[rt].r=build(mid+1,r);
        update(rt);
        return rt;
    }
}
using namespace FHQ_Treap_Array;
int main()
{
	int n=read(),q=read();
	for(int i=1;i<=n;++i)syh[i]=read();
	root=build(1,n);
	for(int i=1;i<=q;++i)
	{
		int op=read(),l=read(),r=read();++l,++r;
		switch(op)
		{
			case 0:{change(l,r,0);break;}
			case 1:{change(l,r,1);break;}
			case 2:{reverse(l,r);break;}
			case 3:{write(query_sum(l,r));puts("");break;}
			default:{write(query_ans(l,r));puts("");break;}
		}
    }
	return 0;
}
