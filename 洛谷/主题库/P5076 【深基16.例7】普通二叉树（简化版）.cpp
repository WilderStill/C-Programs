#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int n;
int main()
{ 
	scanf("%d",&n);
    for(int i=1,op,x;i<=n;++i)
	{
		scanf("%d%d",&op,&x);
        if(op==1)printf("%d\n",lower_bound(v.begin(),v.end(),x)-v.begin()+1);
        else if(op==2) printf("%d\n",v[x-1]);
        else if(op==3)
		{
			auto p=lower_bound(v.begin(),v.end(),x);
        	if(p==v.begin())puts("-2147483647");
        	else printf("%d\n",*(p-1));
		}
        else if(op==4)
		{
            auto p=upper_bound(v.begin(),v.end(),x);
            if(p==v.end())puts("2147483647");
            else printf("%d\n",*p);
        }
        else v.insert(upper_bound(v.begin(),v.end(),x),x);
    }
    return 0;
}
