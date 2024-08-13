#include<bits/stdc++.h>
#define int long long
#define M 1145141
using namespace std;
int n,m,k,ans,l=1,r,len,block;
int t[M],raw[M],res[M],num[M],prenum[M],nxtnum[M],vis[M],disc[M];
struct node
{
	int l,r,id;
	inline bool operator<(const node&b)const
	{
		return ((l-1)/block==(b.l-1)/block)?(r<b.r):((l-1)/block<(b.l-1)/block);
	}
}q[M];
void add(int x,int to){ans+=vis[to];++vis[num[x]];}
void remove(int x,int to){--vis[num[x]];ans-=vis[to];}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>t[i];
	disc[++len]=0;disc[++len]=k;disc[++len]=-k;
	for(int i=1,tmp;i<=n;i++)
	{
		cin>>tmp;
		if(t[i]==1)raw[i]=raw[i-1]+tmp;
		else raw[i]=raw[i-1]-tmp;
		disc[++len]=raw[i];
		disc[++len]=raw[i]-k;
		disc[++len]=raw[i]+k;
	}
	sort(disc+1,disc+len+1);
	len=unique(disc+1,disc+len+1)-disc-1;
	for(int i=0;i<=n;i++)
	{
		nxtnum[i]=lower_bound(disc+1,disc+len+1,raw[i]+k)-disc;
		prenum[i]=lower_bound(disc+1,disc+len+1,raw[i]-k)-disc;
		num[i]=lower_bound(disc+1,disc+len+1,raw[i])-disc;
	}
	cin>>m;
	block=sqrt(n);
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].l--;q[i].id=i;
	}
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)remove(l,nxtnum[l]),++l;
		while(r>q[i].r)remove(r,prenum[r]),--r;
		while(l>q[i].l)--l,add(l,nxtnum[l]);
		while(r<q[i].r)r++,add(r,prenum[r]);
		res[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",res[i]);
	return 0;
}
