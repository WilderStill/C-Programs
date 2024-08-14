#include<bits/stdc++.h>
#define M 114514
using namespace std;
bool inroad[M],can[M];       
int dis[M];                      
vector<int>edge[M],egde[M];  //正为edge,反则为egde         
queue<int>q;
int n,m,s,t;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);egde[y].push_back(x);
    }
    scanf("%d%d",&s,&t);
    can[t]=true;
    q.push(t);
    while(!q.empty())            
    {
        int top=q.front();
        q.pop();
        for(int i=egde[top].size()-1;i>=0;i--)
        {
            int to=egde[top][i];
            if(!can[to])
            {
                q.push(to);
                can[to]=true;
            }
        }
    }
    if(!can[s]){printf("-1");return 0;}
    for(int i=1;i<=n;i++)       
    {
        if(can[i])
        {
            inroad[i]=true;
            for(int j=edge[i].size()-1;j>=0;j--)  
            {
                int to=edge[i][j];
                if(!can[to])           
                {
                    inroad[i]=false;
                    break;
                }
            }
        }
    }
    if(!inroad[s]){printf("-1");return 0;}
    dis[s]=1;q.push(s);
    while(!q.empty())               
    {
        int top=q.front();
        q.pop();
        if(top==t){printf("%d",dis[t]-1);return 0;}
        for(int i=edge[top].size()-1;i>=0;i--)
        {
            int to=edge[top][i];
            if(inroad[to]&&!dis[to])
            {
                dis[to]=dis[top]+1;
                q.push(to);
            }
        }
    }
    printf("-1");
	return 0;           
}
