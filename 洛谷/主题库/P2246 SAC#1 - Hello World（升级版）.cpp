#include<bits/stdc++.h>
using namespace std;
long long str[13];
char ch;
int main()
{
	while((ch=getchar())!=EOF)
	{
		switch(ch)
		{
			case 'h':case 'H':{++str[1];str[1]%=1000000007;break;}
			case 'e':case 'E':{str[2]+=str[1];str[2]%=1000000007;break;}
			case 'l':case 'L':
			{
				if(str[4])str[9]+=str[8],str[9]%=1000000007;
				if(str[3])str[4]+=str[3],str[4]%=1000000007; 
				str[3]+=str[2];str[3]%=1000000007;
				break;
			}
			case 'o':case 'O':
			{
				if(str[5])str[7]+=str[6],str[7]%=1000000007;
				str[5]+=str[4];str[5]%=1000000007;
				break;
			}
			case 'w':case 'W':{str[6]+=str[5];str[6]%=1000000007;break;}
			case 'r':case 'R':{str[8]+=str[7];str[8]%=1000000007;break;}
			case 'd':case 'D':{str[10]+=str[9];str[10]%=1000000007;break;}
		}
	}
	printf("%lld",str[10]%1000000007);
	return 0;
}
