#include<bits/stdc++.h>
using namespace std;
int n,k;
struct sb
{
	int val,pos;
}pk[2000009];
deque<sb>q;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&pk[i].val),pk[i].pos=i-1;
    puts("0");
    for(int i=1;i<n;i++)
    {
        while(!q.empty()&&q.back().val>=pk[i].val)q.pop_back();
        q.push_back(pk[i]);
        while(!q.empty()&&q.front().pos<i-k)q.pop_front();
        printf("%d\n",q.front().val);
    }
	return 0;
}
