#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},n;
queue<ll> q;
map<ll,ll> mp;
ll read()
{
    ll x=0;
    char ch;
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
int main()
{
	n=read();
	q.push(n);
	mp[n]=0;
	while(!q.empty())
	{
		ll top=q.front(),mpt[3][3],x,y;
		q.pop();
        if(top==123804765)break;
        ll tmp=top;
        for(ll i=2;i>=0;i--)
        	for(ll j=2;j>=0;j--)
            {
                mpt[i][j]=tmp%10;
				tmp/=10;
                if(!mpt[i][j])x=i,y=j;
            }
        for(ll i=0;i<4;i++)
        {
        	ll xx=x+dx[i],yy=y+dy[i];
        	tmp=0;
        	if(xx>2||yy>2||xx<0||yy<0)continue;
        	swap(mpt[xx][yy],mpt[x][y]);
        	for(ll i=0;i<3;i++)
                for(ll j=0;j<3;j++)
					tmp=tmp*10+mpt[i][j];
			if(!mp.count(tmp))
			{
				mp[tmp]=mp[top]+1;
				q.push(tmp);
			}
			swap(mpt[x][y],mpt[xx][yy]);
		}
	}
	printf("%lld",mp[123804765]);
	return 0;
}
