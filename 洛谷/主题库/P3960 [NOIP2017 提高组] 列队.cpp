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
mt19937 dg(time(0));
int tot,linert,endrt,sl,mid,sr,tpl,tpmid,tpr,tpsyh,tp1,tp2,res,rk;
struct node
{
	int size,key,l,r,s,t;
}tr[1200010];
inline int newnode(int s,int t)
{
	tr[++tot].s=s;
	tr[tot].t=t;
	tr[tot].l=tr[tot].r=0;
	tr[tot].key=dg();
	tr[tot].size=t-s+1;
	return tot;
}
inline void update(int rt)
{
	if(rt==0)return; 
	tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+tr[rt].t-tr[rt].s+1;
	return;
}
inline void split(int rt,int v,int&l,int&r,bool op)
{
	if(!rt)return;
	if(tr[tr[rt].l].size+tr[rt].t-tr[rt].s+1>=v&&v>tr[tr[rt].l].size)
	{
		if(!op)
		{
			l=rt,r=tr[rt].r;
			tr[rt].r=0;
			update(r);
			update(rt);
		}
		else
		{
			r=rt,l=tr[rt].l;
			tr[rt].l=0;
			update(l);
			update(rt);
		}
		return;
	}
	if(tr[tr[rt].l].size+tr[rt].t-tr[rt].s+1<=v)
	{
		l=rt;
		split(tr[rt].r,v-(tr[tr[rt].l].size+tr[rt].t-tr[rt].s+1),tr[rt].r,r,op);
		update(rt);
		return;
	}
	else
	{
		r=rt;
		split(tr[rt].l,v,l,tr[rt].l,op);
		update(rt);
		return;
	}
}
inline int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tr[l].key>=tr[r].key)
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
signed main()
{
	//freopen("phalanx.in","r",stdin);
	//freopen("phalanx.out","w",stdout);
	int n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		linert=merge(linert,newnode((i-1)*m+1,i*m-1));
		endrt=merge(endrt,newnode(i*m,i*m));
	} 
	while(q--)
	{
		int x=read(),y=read();
		if(y==m)
		{
			split(endrt,x,mid,sr,0);
			split(mid,x,sl,mid,1);
			write(tr[mid].s),puts("");
			endrt=merge(sl,merge(sr,mid));
		}
		else
		{
			rk=(x-1)*(m-1)+y;
			split(linert,x*(m-1),sr,tpr,0);
			split(sr,rk,mid,sr,0);
			split(mid,rk,sl,mid,1);
			split(endrt,x,tpl,tpmid,0);
			split(tpl,x,tpsyh,tpl,1);
			res=tr[mid].s+rk-1-tr[sl].size;
			write(res),puts("");
			tp1=tp2=0;
			if(res>tr[mid].s)tp1=newnode(tr[mid].s,res-1);
			if(res<tr[mid].t)tp2=newnode(res+1,tr[mid].t);
			tr[mid].s=tr[mid].t=res,tr[mid].size=1;
			tr[mid].l=tr[mid].r=0;
			linert=merge(merge(merge(sl,tp1),merge(tp2,merge(sr,tpl))),tpr);
			endrt=merge(tpsyh,merge(tpmid,mid));
		}
	} 
    return cerr<<endl<<1.0*clock()/CLOCKS_PER_SEC<<endl,0;
}
