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
namespace FHQ_Treap_Array
{
	#define INF 0x3f3f3f3f
	int tot=0,root=0;
	struct node
	{
		int size,key,l,r,val;
	}tr[200010];
	int newnode(int v)//建立新节点 
	{
		tr[++tot].val=v;
		tr[tot].l=tr[tot].r=0;
		tr[tot].key=rand()*rand()%INF+1;
		tr[tot].size=1;
		return tot;
	}
	void update(int rt)//更新节点子树大小 
	{
		tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+1;
	}
	void split(int rt,int v,int&l,int&r)//关键：分裂操作
	{
		if(!rt)
		{
			l=r=0;
			return;
		}
		if(tr[rt].val<=v)
		{
			l=rt;
	        split(tr[rt].r,v,tr[rt].r,r);
	    }
	    else
		{
			r=rt;
	        split(tr[rt].l,v,l,tr[rt].l);
	    }
	    update(rt);
	}
	int merge(int l,int r)//关键：合并操作 
	{
		if(!l||!r)return l+r;
		if(tr[l].key<=tr[r].key)
		{
	        tr[r].l=merge(l,tr[r].l);
	        update(r);
	        return r;
	    }
	    else
		{
	        tr[l].r=merge(tr[l].r,r);
	        update(l);
	        return l;
	    }
	}
	void insert(int v)
	{
		int l,r;
	    split(root,v-1,l,r);
	    root=merge(merge(l,newnode(v)),r);
	}
	void destroy(int v)
	{
		int x,y,z;
	    split(root,v,x,z);
	    split(x,v-1,x,y);
	    if(y)y=merge(tr[y].l,tr[y].r);
	    root=merge(merge(x,y),z);
	}
	int find_rank(int v)
	{
	    int l,r,res;
	    split(root,v-1,l,r);
	    res=tr[l].size+1;
	    root=merge(l,r);
	    return res;
	}
	int find_val(int rk)
	{
	    int k=root;
	    while(k)
		{
	        if(tr[tr[k].l].size+1==rk)break;
	        else if(tr[tr[k].l].size>=rk)k=tr[k].l;
	        else rk-=tr[tr[k].l].size+1,k=tr[k].r;
	    }
	    return k?tr[k].val:INF;
	}
	int find_pre(int v)
	{
	    int l,r,k,res;
	    split(root,v-1,l,r);k=l;
	    while(tr[k].r)k=tr[k].r;
		res=tr[k].val;
	    root=merge(l,r);
	    return res;
	}
	int find_nxt(int v)
	{
	    int l,r,k,res;
	    split(root,v,l,r);k=r;
	    while(tr[k].l)k=tr[k].l;
		res=tr[k].val;
	    root=merge(l,r);
	    return res;
	}
}
using namespace FHQ_Treap_Array;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int op=read(),x=read();
		switch(op)
		{
			case 1:{insert(x);break;}
			case 2:{destroy(x);break;}
			case 3:{write(find_rank(x));putchar('\n');break;}
			case 4:{write(find_val(x));putchar('\n');break;}
			case 5:{write(find_pre(x));putchar('\n');break;}
			case 6:{write(find_nxt(x));putchar('\n');break;}
			default:break;
		}
    }
	return 0;
}
