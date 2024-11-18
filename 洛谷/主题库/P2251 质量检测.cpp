#include<bits/stdc++.h>
using namespace std;
int n,k,num[1000009],t=1;
deque<int>deq;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=1;i<=n;i++)
	{
		while(deq.size()&&num[deq.back()]>=num[i])deq.pop_back();
		deq.push_back(i); 
		if(i-t>=k) 
		{
			if(t==deq.front())deq.pop_front();
			++t;
		}
		if(i>=k)printf("%d\n",num[deq.front()]);
	}
	return 0;
}
