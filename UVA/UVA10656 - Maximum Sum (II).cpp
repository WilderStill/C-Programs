#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
	{
        if(!n)return 0;
		v.clear();
        for(int i=1,x;i<=n;i++)
        {
            scanf("%d",&x);
            if(x)v.push_back(x);
        }
        if(v.empty())printf("0");
        else
            for(int i=0;i<v.size();i++)
            {
                printf("%d",v[i]);
                if(i!=v.size()-1)printf(" ");
            }
		printf("\n");
    }
    return 0;
}
