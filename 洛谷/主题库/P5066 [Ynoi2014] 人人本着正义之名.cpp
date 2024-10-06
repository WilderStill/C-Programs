#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define npt nullptr
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
mt19937_64 dg(time(0));
struct node
{
	int key,val,sum,size[2],tl,tr,tagl,tagr,lenmin[2];
	node *l,*r;
	node(){}
	node(int _key,int _val,int _tl,int _tr){key=_key,val=_val,tl=_tl,tr=_tr,l=r=npt,clear();}
	inline void clear()
	{
		size[val]=1,size[val^1]=0;
		sum=val*(tr-tl+1);
		tagl=tagr=0;
		lenmin[val]=tr-tl+1,lenmin[val^1]=INF;
	}
	node operator+(const node&b)const
	{
		node res=*this;
		res.sum+=b.sum;
		res.size[0]+=b.size[0],res.size[1]+=b.size[1];
		res.lenmin[0]=min(res.lenmin[0],b.lenmin[0]);
		res.lenmin[1]=min(res.lenmin[1],b.lenmin[1]);
		return res;
	}
};
node syh[10000010];
int tot;
node*root;
queue<node*>wbin;
inline node*newnode(int val,int l,int r){return &(syh[tot++]=node(dg(),val,l,r));}
inline void update(node*rt,int l,int r)
{
	if(!rt)return;
	rt->tagl+=l,rt->tagr+=r;
	rt->lenmin[0]-=l+r,rt->lenmin[1]+=l+r;
	rt->sum+=(l+r)*rt->size[1];
	if(rt->val)rt->tl-=l,rt->tr+=r;
	else rt->tl+=r,rt->tr-=l;
}
inline void pushdown(node*rt)
{
	if(!rt->tagl&&!rt->tagr)return;
	if(rt->l)update(rt->l,rt->tagl,rt->tagr);
	if(rt->r)update(rt->r,rt->tagl,rt->tagr);
	rt->tagl=rt->tagr=0;
}
inline void fempty(node*rt)
{
	if(!rt)return;
	if(rt->lenmin[0]&&rt->lenmin[1])return;
	pushdown(rt);
	if(rt->tl>rt->tr)wbin.push(rt);
	fempty(rt->l);
	fempty(rt->r);
}
inline void pushup(node*rt)
{
	rt->clear();
	if(rt->l)*rt=*rt+*(rt->l);
	if(rt->r)*rt=*rt+*(rt->r);
}
inline node*merge(node*l,node*r)
{
	if(!r){return l;}
	if(!l){return r;}
	if(l->key<r->key)
	{
		pushdown(l);
		l->r=merge(l->r,r);
		pushup(l);
		return l;
	}  
	else
	{
		pushdown(r);
		r->l=merge(l,r->l);
		pushup(r);
		return r;
	}
}
inline void split(node*rt,int v,node*&l,node*&r,int op)
{
	if(!rt)
	{
		l=r=npt;
		return;
	}
	pushdown(rt);
	if((op==1?rt->tl:rt->tr)<=v)
	{
		l=rt;
		split(rt->r,v,l->r,r,op);
	}
	else
	{
		r=rt;
		split(rt->l,v,l,r->l,op);
	}
	pushup(rt);
}
inline void clean()
{
	while(!wbin.empty())
	{
		node*p=wbin.front();
		wbin.pop();
		node *xl=npt,*tpl=npt,*xr=npt,*tpr=npt;
		split(root,p->tl-1,root,tpr,1);
		split(tpr,p->tl,tpl,tpr,1);
		split(root,p->tl-2,root,xl,2);
		if(p==tpl)xr=(p->l?p->l:p->r);
		else xr=tpl,xr->l=xr->r=npt;
		if(xl&&xr)xl->tr=xr->tr,xl->clear(),xr=npt;
		root=merge(merge(merge(root,xl),xr),tpr);
	}
}
inline void insert(int l,int r,int val){root=merge(root,newnode(val,l,r));}
inline void op1_2(int l,int r,int val)
{
	node*p=npt,*xl=npt,*xr=npt,*tpr=npt;
	split(root,l-1,root,p,2),split(p,r,p,tpr,1);
	split(p,l-1,xl,p,1),split(p,r,p,xr,2);
	if(xl)
	{
		if(xl->tr>r)xr=newnode(xl->val,r,xl->tr);
		xl->tr=l-1,xl->clear();
	}
	else split(root,l-2,root,xl,2);
	if(xr)xr->tl=r+1,xr->clear();
	else split(tpr,r+1,xr,tpr,1);
	p=newnode(val,l,r);
	if(xl&&p->val==xl->val)
	{
		p->tl=xl->tl,p->clear();
		xl=npt;
	}
	if(xr&&p->val==xr->val)
	{
		p->tr=xr->tr,p->clear();
		xr=npt;
	}
	root=merge(merge(merge(merge(root,xl),p),xr),tpr);
}
inline void op3_5(int l,int r,int op)
{
	r--;
	node*tpl=npt,*tpr=npt,*x=npt;
	split(root,l-1,root,tpl,2);
	split(tpl,r,tpl,tpr,1);
	split(tpl,l,x,tpl,1);
	if(x&&(op==3?x->val:x->val^1))root=merge(root,x);
	else tpl=merge(x,tpl);
	x=npt;
	split(tpl,r-1,tpl,x,2);
	if(x&&(op==3?x->val^1:x->val))
	{
		if(x->tr>r)tpr=merge(x,tpr);
		else
		{
			tpl=merge(tpl,x);
			node*xr=npt;
			split(tpr,r+1,xr,tpr,1);
			tpl=merge(tpl,xr);
		}
	}
	else tpl=merge(tpl,x);
	if(tpl)op==3?update(tpl,1,0):update(tpl,0,-1); 
	root=merge(merge(root,tpl),tpr);
	fempty(root),clean();
}
inline void op4_6(int l,int r,int op)
{
	l++;
	node*tpl=npt,*tpr=npt,*x=npt;
	split(root,l-1,root,tpl,2);
	split(tpl,r,tpl,tpr,1);
	split(tpl,l,x,tpl,1);
	if(x&&(op==4?x->val^1:x->val))
	{
		if(x->tl<l)root=merge(root,x);
		else
		{
			tpl=merge(x,tpl);
			node*xl=npt;
			split(root,l-2,root,xl,2);
			tpl=merge(xl,tpl);
		}
	}
	else tpl=merge(x,tpl);
	x=npt;
	split(tpl,r-1,tpl,x,2);
	if(x&&(op==4?x->val:x->val^1))tpr=merge(x,tpr);
	else tpl=merge(tpl,x);
	if(tpl)op==4?update(tpl,0,1):update(tpl,-1,0);
	root=merge(merge(root,tpl),tpr);
	fempty(root),clean();
}
inline int op7(int l,int r)
{
	node*x=npt,*p=npt,*tpr=npt;
	split(root,l-1,root,p,2);
	split(p,r,p,tpr,1);
	int res=0;
	if(p)res+=p->sum;
	split(p,l-1,x,p,1);
	if(x)res-=x->val*(l-x->tl);
	p=merge(x,p);
	x=npt;
	split(p,r,p,x,2);
	if(x)res-=x->val*(x->tr-r);
	root=merge(merge(root,merge(p,x)),tpr);
	return res;
}
int num[3000010];
int main()
{
	int n=read(),m=read(),lst=1;
	for(int i=1;i<=n;++i)num[i]=read();
	for(int i=1;i<n;++i)
		if(num[i]^num[i+1])insert(lst,i,num[i]),lst=i+1;
	insert(lst,n,num[n]);
	lst=0;
	for(int i=1;i<=m;++i)
	{
		int op=read(),l=read()^lst,r=read()^lst;
		switch(op)
		{
			case 1:{op1_2(l,r,0);break;}
			case 2:{op1_2(l,r,1);break;}
			case 3:{op3_5(l,r,3);break;}
			case 4:{op4_6(l,r,4);break;}
			case 5:{op3_5(l,r,5);break;}
			case 6:{op4_6(l,r,6);break;}
			default:{write(lst=op7(l,r)),puts("");break;}
		}
	}
	return 0;
}
