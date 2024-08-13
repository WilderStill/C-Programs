#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		int seek=0;
		bool flag=1;
		for(int i=0;i<s.size();i++)
		{
			char ch=s[i];
			if(ch=='b'||ch=='d'||ch=='f'||ch=='h'||ch=='k'||ch=='l'||ch=='t')seek++;
			else if(ch=='g'||ch=='j'||ch=='p'||ch=='q'||ch=='y')
			{
				if(!seek)
				{
					flag=false;break;
				}
				else seek--;
			}
		}	
		printf((flag&&!seek)?"YES":"NO");
		printf("\n");
	}
	return 0;
}
