#include<bits/stdc++.h>
using namespace std;
char n[114514];
int k,p=1; 
int main()
{
	scanf("%s %d",&n,&k);
	printf("%c",n[strlen(n)-k]);
	return 0;
}
