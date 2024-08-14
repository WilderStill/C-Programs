#include<bits/stdc++.h>
using namespace std;
int a[1145141],b[1145141];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
	{
        scanf("%d",&a[i]);
    }
    for(int i=1;i<t;i++)
	{
        b[i]=abs(a[i]-a[i+1]);
    }
    sort(b+1,b+t);
    for(int i=1;i<t;i++)
	{
        if(b[i]!=i)
		{
			printf("Not jolly\n");
			return 0;
		}
    }
    printf("Jolly\n");
    return 0;
}
