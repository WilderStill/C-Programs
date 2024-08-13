#include<bits/stdc++.h>
using namespace std;
string tries="RRRRPSSPRR",win,res,ans;
int main()
{
	for(int i=0;i<10;++i)
	{
		cout<<tries[i]<<endl;
		cout.flush(); 
		cin>>win;
		if(win=="ai")res+="0";
		else res+="1";
	}
	if(res=="1111000011")ans="RRRRRRRRRR";
	if(res=="0000100100")ans="PPPPPPPPPP";
	if(res=="0000011000")ans="SSSSSSSSSS";
	if(res=="0010000010")ans="SRPSRPSRPS";
	if(res=="0000110000")ans="PSRPSRPSRP";
	if(res=="0000000110")ans="SPRSPRSPRS";
	for(int i=0;i<10;++i)
	{
		cout<<ans[i]<<endl;
		cout.flush();
		cin>>win;
	}
    return 0;
}

