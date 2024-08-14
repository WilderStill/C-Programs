#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[6];
	bool fg=0;
	cin>>s;
	if((s[0]=='s'||s[0]=='S')&&(s[1]=='v'||s[1]=='V')&&(s[2]=='p'||s[2]=='P')&&(s[3]=='o'||s[3]=='O')&&(s[4]=='l'||s[4]=='L')&&(s[5]=='l'||s[5]=='L'))
		cout<<"Genshin";
	else if((s[0]=='A'||s[0]=='a')&&(s[1]=='C'||s[1]=='c')&&(s[2]=='o'||s[2]=='O')&&(s[3]=='I'||s[3]=='i')&&(s[4]=='P'||s[4]=='p')&&(s[5]=='P'||s[5]=='p'))
		cout<<"Luogu";
	else cout<<"Boring";
}
