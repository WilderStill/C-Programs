#include<bits/stdc++.h>
#define M 241
using namespace std;
int T,C,n,m,maxn,now,hope[M],sad[M],num[M],match[M],solve[M],vis[M];
vector<int>wish[M][M];
//hope[i]��ʾ��i���˵�����ֵ��wish[i][j][k]��ʾ��i���˵ĵ�j־Ը�еĵ�k���ˡ� 
//sad[i]��ʾʹ��i���˲���ɥ������Ҫ������������������solve[i]��ʾ���ŷ����µ�i���˱�˭¼ȡ�� 
bool found(int x,int t)
{
    if(x<now)maxn=max(maxn,x);//���x�����������ڲ����ǰ 
    for(auto v:wish[x][t])
    {
        if(vis[v])continue;
		vis[v]=1;
        if(num[v])//�����λ��ʦ���п�λ 
        {
            match[x]=v,solve[x]=t;
			--num[v];//����ʦ��λ-1
            return 1;
        }
        for(int i=1;i<=n;i++)//�����������㷨��һ�� 
        {
            if(i==x||match[i]!=v)continue;//��������������߶Է���־Ը��������־Ը���������� 
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
		memset(wish,0,sizeof(wish));memset(match,0,sizeof(match));//��ⲻ��գ�wyy������T_T 
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
			solve[i]=m+1,sad[i]=i;//��ʼ�� 
		}
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
			now=i;//now��ʾ��������ڵ�������maxn��ʾ�����Ҫ��ﵽ־Ըʱ������ 
            for(int j=1;j<=m;j++)
            {
                if(wish[i][j].empty())continue;
				maxn=0;
                if(found(i,j))
				{
					if(j<=hope[i])sad[i]=0;//�����������־Ը����ߵĵ�ʦѡ�� 
					break;
				}
                if(j<=hope[i])sad[i]=min(sad[i],i-maxn);//��������˺���������Բ���ɥ����ô���¡� 
            }
        }
        for(int i=1;i<=n;i++)printf("%d ",solve[i]);printf("\n");
        for(int i=1;i<=n;i++)printf("%d ",sad[i]);printf("\n");
    }
    return 0;
}
