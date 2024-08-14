#include <bits/stdc++.h>
using namespace std;
int n,edge[114][114],in[114];
queue<int>q;
vector<int>ans;
void tp()
{
    for(int i=1;i<=n;i++)
        if(!in[i])
			q.push(i);
    while(!q.empty())
	{
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(int i=1;i<=n;i++)
            if(edge[top][i])
				if(--in[i]==0)
					q.push(i);
    }
    for(int i=0;i<n;i++)
    	printf("%d ",ans[i]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1,k;i<=n;i++)
	{
        while(true)
		{
			scanf("%d",&k);
			if(k==0)break;
            edge[i][k]=1;
            in[k]++;
        }
    }
    tp();
    return 0;
}
