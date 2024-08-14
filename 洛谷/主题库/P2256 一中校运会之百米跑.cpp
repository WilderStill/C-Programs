#include<bits/stdc++.h>
using namespace std;
int n,m,k;
map<string,string>fa;
string find(string x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
	{
		string name;
		cin>>name;
		fa[name]=name;
	}
    for(int i=1,x,y;i<=m;i++)
	{
		string name1,name2;
		cin>>name1>>name2;
        fa[find(name1)]=find(name2);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
	{
		string name1,name2;
		cin>>name1>>name2;
        printf(find(name1)==find(name2)?"Yes.\n":"No.\n");
    }
    return 0;
}
