#include<bits/stdc++.h>
#define limit 1000000 
#define ll long long
#define M 414514
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,sublen1,sublen2,a[M],sub1[M],sub2[M],vis[M];
bool ans[M];
void dfs(int pos)
{
	if(vis[a[pos-1]]>2)return;
	if(clock()>limit)
    {
        puts("No");
        exit(0);
    }
	if(pos==4*n+1)
	{
		puts("Yes");
		for(int i=4*n;i>=1;--i)putchar(ans[i]?'1':'0');
		exit(0);
	}
	if(sublen1<=sublen2)//��sub1��sub2��Ҫ��ʱ��ֱ�Ӱ�pos�ϵ�������sub1 
	{
		ans[pos]=0;
		sub1[++sublen1]=a[pos];
		++vis[a[pos]];
		dfs(pos+1);
		--sublen1;
		--vis[a[pos]];
	}
	else//��sub1��sub2��Ҫ��ʱ
	{
		if(a[pos]==sub1[sublen2+1])//��sub1�ĵ�sublen2λ�ĺ�һλ��pos�ϵ�����ͬʱ�ſ��Էŵ�sub2�� 
		{
			ans[pos]=1;
			sub2[++sublen2]=a[pos];
			dfs(pos+1);
			--sublen2;
		}
		ans[pos]=0;
		sub1[++sublen1]=a[pos];
		++vis[a[pos]];
		dfs(pos+1);
		--sublen1;
		--vis[a[pos]];
	}
}
int main()
{ 
	n=read();
	for(register int i=4*n;i>=1;--i)a[i]=read();
	dfs(1);
	puts("No");
	return 0;
}
