#include <bits/stdc++.h>
#define M 114514 
using namespace std;
int n,p,q;
string a[M],b[M],ans[M];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	string song,ud;
        cin>>song>>ud;
        if(ud=="UP")b[q++]=song;
        if(ud=="SAME")ans[i]=song;
        if(ud=="DOWN") a[p++]=song;
    }
    int nowa=0,nowb=0;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]=="")
        {
            if(nowa<p)ans[i]=a[nowa++];
            else ans[i]=b[nowb++];
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
    return 0;
}
