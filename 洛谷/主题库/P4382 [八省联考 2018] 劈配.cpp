#include<bits/stdc++.h>
#define M 241
using namespace std;
int T,C,n,m,maxn,now,hope[M],sad[M],num[M],match[M],solve[M],vis[M];
vector<int>wish[M][M];
//hope[i]表示第i个人的理想值，wish[i][j][k]表示第i个人的第j志愿中的第k个人。 
//sad[i]表示使第i个人不沮丧最少需要让他上升的排名数，solve[i]表示最优方案下第i个人被谁录取。 
bool found(int x,int t)
{
    if(x<now)maxn=max(maxn,x);//如果x的排名在现在查的人前 
    for(auto v:wish[x][t])
    {
        if(vis[v])continue;
		vis[v]=1;
        if(num[v])//如果这位导师还有空位 
        {
            match[x]=v,solve[x]=t;
			--num[v];//给导师空位-1
            return 1;
        }
        for(int i=1;i<=n;i++)//否则匈牙利算法跑一遍 
        {
            if(i==x||match[i]!=v)continue;//如果遍历到他或者对方的志愿不是他的志愿，立刻跳过 
            if(found(i,solve[i]))
            {
                match[x]=v,solve[x]=t;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
	scanf("%d%d",&T,&C);
    while(T--)
    {
        scanf("%d%d",&n,&m);
		memset(wish,0,sizeof(wish));memset(match,0,sizeof(match));//多测不清空，wyy两行泪T_T 
        for(int i=1;i<=m;i++)scanf("%d",&num[i]);
        for(int i=1;i<=n;i++)
            for(int j=1,x;j<=m;j++)
            {
                scanf("%d",&x);
                wish[i][x].push_back(j);
            }
        for(int i=1;i<=n;i++)
		{
			scanf("%d",&hope[i]);
			solve[i]=m+1,sad[i]=i;//初始化 
		}
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
			now=i;//now表示这个人现在的排名，maxn表示这个人要想达到志愿时的排名 
            for(int j=1;j<=m;j++)
            {
                if(wish[i][j].empty())continue;
				maxn=0;
                if(found(i,j))
				{
					if(j<=hope[i])sad[i]=0;//如果他被他的志愿或更高的导师选中 
					break;
				}
                if(j<=hope[i])sad[i]=min(sad[i],i-maxn);//跑完这个人后，如果他可以不沮丧，那么更新。 
            }
        }
        for(int i=1;i<=n;i++)printf("%d ",solve[i]);printf("\n");
        for(int i=1;i<=n;i++)printf("%d ",sad[i]);printf("\n");
    }
    return 0;
}
