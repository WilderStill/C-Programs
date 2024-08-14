#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(ll x)
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
struct node
{
	ll l,r,val;
}tr[1000100];
bool check_same(ll pos1,ll pos2)
{
	if(pos1==-1&&pos2==-1)return 1;
	if(pos2==-1||pos1==-1)return 0;
	if(tr[pos1].val^tr[pos2].val)return 0;
	return check_same(tr[pos1].l,tr[pos2].r)&&check_same(tr[pos1].r,tr[pos2].l);
}
ll query(ll pos)
{
	return ~pos?query(tr[pos].l)+query(tr[pos].r)+1:0;
}
int main()
{
	ll n=read(),ans=0;
	for(int i=1;i<=n;++i)tr[i].val=read();
	for(int i=1;i<=n;++i)tr[i].l=read(),tr[i].r=read();
	for(int i=1;i<=n;++i)if(check_same(i,i))ans=max(ans,query(i));
	write(ans);
	return 0;
}
