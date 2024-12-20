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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int m=70010,dg=350;
struct info{int id,pos;};
int n,lastans,blen,klen,tot,cnt,rk[dg],num[m],blo[m],sx[dg][dg],sy[dg][m];
vector<int>v[dg];
inline void add(int l,int r,int k)
{
	for(int i=l;i<=cnt;++i)sx[i][blo[r]]+=k,sy[i][r]+=k;
}
inline info find(int num)
{
	int id=1,pos=0;
	for(;pos+v[id].size()<num;++id)pos+=v[id].size();
	return (info){id,num-pos};
}
inline void modify(int x,int val)
{
	info in=find(x);
	add(in.id,v[in.id][in.pos-1],-1);
	add(in.id,val,1);
	v[in.id][in.pos-1]=val;
}
inline void insert(int x,int val)
{
	++n;
	if(x==n)
	{
		add(cnt,val,1);
		v[cnt].emplace_back(val);
		return;
	}
	info in=find(x);
	add(in.id,val,1);
	v[in.id].insert(v[in.id].begin()+in.pos-1,val);
	return;
}
inline void getsum0(int id,int l,int r){for(int i=l;i<=r;++i)++rk[blo[v[id][i-1]]];}
inline void getsum1(int id,int l,int r,int x)
{
	int lim=(x-1)*blen;
	for(int i=l;i<=r;++i)if(blo[v[id][i-1]]==x)++rk[v[id][i-1]-lim];
}
inline int query(int l,int r,int k)
{	
	info il=find(l),ir=find(r);
	if(il.id==ir.id)getsum0(il.id,il.pos,ir.pos);
	else
	{
		getsum0(il.id,il.pos,v[il.id].size());
		for(int i=1;i<=tot;++i)rk[i]+=(sx[ir.id-1][i]-sx[il.id][i]);
		getsum0(ir.id,1,ir.pos);
	}
	int pos=1,tot=0,nxt;
	while(tot+rk[pos]<k)tot+=rk[pos++];
	memset(rk,0,sizeof rk);
	k-=tot,nxt=pos;
	int lim=(pos-1)*blen;
	if(il.id==ir.id)getsum1(il.id,il.pos,ir.pos,nxt);	
	else
	{
		getsum1(il.id,il.pos,v[il.id].size(),nxt);
		for(int i=1;i<=blen;++i)rk[i]+=(sy[ir.id-1][lim+i]-sy[il.id][lim+i]);
		getsum1(ir.id,1,ir.pos,nxt);
	}
	pos=1;
	while(rk[pos]<k)k-=rk[pos++];
	memset(rk,0,sizeof rk);
	return lim+pos-1;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)num[i]=read()+1;
	blen=sqrt(m);
	tot=(m-1)/blen+1;
	for(int i=1;i<=m;++i)blo[i]=(i-1)/blen+1;
	klen=sqrt(n);
	int L=1,R=0;
	while(R<n)
	{
		R=min(R+klen,n),++cnt;
		for(int i=L;i<=R;++i)v[cnt].emplace_back(num[i]);
		L=R+1;
	}
	for(int i=1;i<=cnt;++i)for(auto j:v[i])add(i,j,1);
	int q=read();
	for(int i=1;i<=q;++i)
	{
		char op[2];
		scanf("%s",op);
		if(op[0]=='Q')
		{
			int l=read()^lastans,r=read()^lastans,x=read()^lastans;
			write(lastans=query(l,r,x)),puts("");
		}
		else if(op[0]=='M')
		{
			int x=read()^lastans,val=read()^lastans;
			modify(x,val+1);
		}
		else
		{
			int x=read()^lastans,val=read()^lastans;
			insert(x,val+1);
		}
	}
	return 0;
}
