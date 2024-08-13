#include<bits/stdc++.h>
#define M 100010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
struct node
{
	int x,y,id;
	bool operator<(const node&b)
	{
	    if(y^b.y)return y>b.y;
	    return x<b.x;
	}
}epos[M<<1];
vector<node>spos[M<<1],p;
vector<int>kind;
unordered_map<int,int>vis;
int main()
{
    int n=read(),w=read(),h=read();
    for(int i=1;i<=n;++i)
	{
        int op=read(),p=read(),t=read(),id=p-t+M;
        if(op==1)spos[id].emplace_back((node){p,0,i});
        else spos[id].emplace_back((node){0,p,i});
        if(!vis[id])
		{
			kind.emplace_back(id);
			vis[id]=1;
		}
    }
    for(auto id:kind)
	{
        vector<node>tmp;
        for(auto peo:spos[id])
		{
            if(!peo.y)tmp.emplace_back((node){peo.x,h,0});
            else tmp.emplace_back((node){w,peo.y,0});
        }
        sort(spos[id].begin(),spos[id].end());
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<spos[id].size();++i)epos[spos[id][i].id]=tmp[i];
    }
    for(int i=1;i<=n;++i)
    {
    	write(epos[i].x),putchar(' ');
    	write(epos[i].y),putchar('\n');
	}
    return 0;
}
