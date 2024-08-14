#include<bits/stdc++.h>
#define int long long
#define maxn 100040
using namespace std;
int cnt,a[maxn],num,dp[maxn];
signed main(){
	while(cin>>num)a[++cnt]=num;
	if(cnt==0){
		cout<<0<<'\n'<<0;
		return 0;
	}
	dp[1]=maxn;
	int ans=0;
	for(int i=1;i<=cnt;++i){
		int l=0,r=ans+1;
		while(r-l>1){
            int mid=l+(r-l)/2;
            if(dp[mid]>=a[i])l=mid;
			else r=mid;
        }
        int x=l+1;
        if(x>ans)ans=x;
		dp[x]=a[i];
	}
	cout<<ans<<'\n';
	ans=0;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=cnt;++i){
		int l=0,r=ans+1;
		while(r-l>1){
            int mid=l+(r-l)/2;
            if(dp[mid]<a[i])l=mid;
			else r=mid;
        }
        int x=l+1;
        if(x>ans)ans=x;
		dp[x]=a[i];
	}
	cout<<ans;
	return 0;
}
