#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<int>shelf; 
string t[1145141];
int main()
{
	int n,m,q;
	string p;
	scanf("%d",&n);for(int i=n;i>=1;i--){t[shelf.size()].resize(10);scanf("%s",&t[shelf.size()][0]);shelf.push_back(shelf.size());}	
	scanf("%d",&m);for(int i=m,x;i>=1;i--){t[shelf.size()].resize(10);scanf("%s",&t[shelf.size()][0]);scanf("%d",&x);shelf.insert(x,shelf.size());}
	scanf("%d",&q);for(int i=q,x;i>=1;i--){scanf("%d",&x);printf("%s\n",t[shelf[x]].c_str());}	
	return 0;
}
