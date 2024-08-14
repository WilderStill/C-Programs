#include<bits/stdc++.h> 
#define s 1000
using namespace std;
int sa1,sb1,sa2,sb2,ea1,eb1,ea2,eb2; 
int a1=INT_MAX,b1=INT_MAX,a2=-1,b2=-1;
int f[2005][2005];
int main(){
	cin>>sa1>>sb1>>sa2>>sb2>>ea1>>eb1>>ea2>>eb2;
	//标记 
	for(int i=sa1+1;i<=sa2;i++)
		for(int j=sb1+1;j<=sb2;j++)
			f[i+s][j+s]=1; // 加 s 防止负数 RE 
	for(int i=ea1+1;i<=ea2;i++)
		for(int j=eb1+1;j<=eb2;j++)
			f[i+s][j+s]=0;
	//遍历 
	for(int i=0;i<=s*2;i++) // 0 为 -1000，2000 为 1000 
		for(int j=0;j<=s*2;j++)
			if(f[i][j]==1){
				a1=min(a1,i),b1=min(b1,j);
			}  
	for(int i=0;i<=s*2;i++) // 0 为 -1000，2000 为 1000 
		for(int j=0;j<=s*2;j++)
			if(f[i][j]==1){
				a2=max(a2,i),b2=max(b2,j);//这里括号内改成a2/b2 
			}  
	if(a1==INT_MAX&&b1==INT_MAX&&a2==-1&&b2==-1) cout<<0;//这里b1和a2调换位置 ,||换成&& 
	else cout<<(a2-a1+1)*(b2-b1+1);//加else 
	return 0;
}
