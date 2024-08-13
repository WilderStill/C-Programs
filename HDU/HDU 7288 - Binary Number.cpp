#include<bits/stdc++.h>
using namespace std;
long long T;
long long n,k;
char str01[100010];
vector<pair<long long,long long>>sub0;
bool is0=0;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		sub0.clear();is0=0;
		scanf("%lld%lld%s",&n,&k,str01+1);
		long long l=0,r=0;
	    for(long long i=1;i<=n;++i)
	    {
	        if(str01[i]=='0')
	        {
	            if(!is0)l=i,is0=1;
	            r=i;
	        }
	        else if(is0)
	        {
	            sub0.push_back(make_pair(l,r));
	            is0=0;
	        }
	    }
	    if(is0)sub0.push_back(make_pair(l,r));
	    if(n==1)
	    {
	        if(k%2)puts(str01[1]=='0'?"1":"0");
	        else puts(str01[1]=='0'?"0":"1");
	        continue;
	    }
	    if(sub0.empty()&&k==1)
	    {
	        str01[n]='0';
	        puts(str01+1);
	        continue;
	    }
	    long long sz=sub0.size();
	    for(long long i=0;i<min(sz,k);i++)
	    {
	    	pair<long long,long long>qj=sub0[i];
	        for(long long j=qj.first;j<=qj.second;++j)str01[j]='1';
	    }
	    puts(str01+1);
	}
	return 0;
}

