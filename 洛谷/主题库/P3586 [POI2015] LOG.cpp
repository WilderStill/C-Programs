#include<bits/stdc++.h>
#define int long long
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
		int sum,vsize,size,key,l,r,val;
	}tr[1000010];
	int newnode(int v)
	{
		tr[++tot].val=v;
		tr[tot].sum=v;
		tr[tot].l=tr[tot].r=0;
		tr[tot].key=rand()*rand()%INF+1;
		tr[tot].size=tr[tot].vsize=1;
		return tot;
	}
	void update(int rt)
	{
		tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+tr[rt].vsize;
		tr[rt].sum=tr[tr[rt].l].sum+tr[tr[rt].r].sum+tr[rt].val*tr[rt].vsize;
	}
	void split(int rt,int v,int&l,int&r)
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
	int merge(int l,int r)
	{
		if(!l||!r)return l|r;
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
		int x=0,y=0,z=0;
	    split(root,v,x,z);
		split(x,v-1,x,y);
	    if(!y)root=merge(merge(x,newnode(v)),z);
		else
		{
			++tr[y].vsize;
			++tr[y].size;
			tr[y].sum+=v;
			root=merge(merge(x,y),z);
		}
	}
	void destroy(int v)
	{
		int x=0,y=0,z=0;
	    split(root,v,x,z);
	    split(x,v-1,x,y);
	    if(tr[y].size==1)root=merge(x,z);
		else
		{
			--tr[y].vsize;
			--tr[y].size;
			tr[y].sum-=v;
			root=merge(merge(x,y),z);
		}
	}
	int find_size(int v)
	{
	    int l,r,res;
	    split(root,v-1,l,r);
	    res=tr[r].size;
	    root=merge(l,r);
	    return res;
	}
	int find_sum(int v)
	{
	    int l,r,res;
	    split(root,v-1,l,r);
	    res=tr[l].sum;
	    root=merge(l,r);
	    return res;
	}
}
using namespace FHQ_Treap_Array;
int num[1000100];
signed main()
{
	srand(time(0));
	int n=read(),m=read();
	while(m--)
	{
		char op[2];
		scanf("%s",op);
		int x=read(),y=read();
		if(op[0]=='U')
		{
			if(num[x])destroy(num[x]);
			if(y)insert(y);
			num[x]=y;
		}
		else puts(find_sum(y)>=(x-find_size(y))*y?"TAK":"NIE");				
	}
	return 0;
}
