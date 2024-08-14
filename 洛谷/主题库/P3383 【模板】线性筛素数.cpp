//欧拉函数的筛子 
#include<bits/stdc++.h>
using namespace std;
int T,len,prime[6000010],ans[100000010];
bool vis[100000010];
void init()
{
	vis[1] = 1;
    for(int i = 2;i <= 100000000;++i)
	{
        if(!vis[i])
		{
        	ans[i] = i-1;
            prime[++len] = i;
        }
        for(int j = 1;j <= len&&i*prime[j]<=100000000;j++)
		{
        	vis[i*prime[j]] = 1;
            if(i%prime[j] == 0){ans[i*prime[j]] = ans[i]*prime[j];break;}
            else  ans[i*prime[j]] = ans[i]*(prime[j]-1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> T >> T;
    init();
    //for(int i = 1;i <= 10;++i)cout << ans[i] <<" ";
    while(T--)
	{
    	long long N;
		cin >> N;
		cout << prime[N] << "\n";
	}
	return 0;
}
