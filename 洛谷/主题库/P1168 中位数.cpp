#include<bits/stdc++.h>
#define M 1000001
using namespace std;
priority_queue<int>b;
priority_queue<int>s;
int n,a;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a);
    	if(i==1)
		{
    		b.push(-1*a);
            printf("%d\n",-1*b.top());
		}
    	else if(i%2==0)
		{
			int t=b.top();
			if(a<=-1*t) s.push(a);
			else
			{
				b.pop();
				b.push(-1*a);
				s.push(-1*t);
			}
		}
		else if(i%2==1)
		{
			int t=s.top();
			if(a>=t)b.push(-1*a);
			else
			{
				s.pop();
				s.push(a);
				b.push(-1*t);
			}
			printf("%d\n",-1*b.top());
		}
	}
    return 0;
}
