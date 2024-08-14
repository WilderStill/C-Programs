#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int A_c=0,T_c=0;
	char x[1005];
	for(int i=0;i<n;++i)
	{
		cin>>x[i];
		if(x[i]=='A')A_c+=1;
		else if(x[i]=='T')T_c+=1;
	}
	if(A_c>T_c)
	{
		cout<<"A";
		return 0;
	}
	if(A_c<T_c)
	{
		cout<<"T";
		return 0;
	}
	if(A_c==T_c)
	{
		for(int i=n;i>1;i--)
		{
			if(x[i]=='A')
			{
				cout<<"T";
				return 0;
			}
			else if(x[i]=='T')
			{
				cout<<"A";
				return 0;
			}
		}	
	}
	return 0;
}
