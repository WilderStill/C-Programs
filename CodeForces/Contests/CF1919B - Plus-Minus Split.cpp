#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,a=0,b=0;
    scanf("%d",&t);
    while(t--)
	{
        string s;
        scanf("%d",&n);
        cin>>s;
        for(int i=0;i<s.size();i++)
		{
            if(s[i]=='+')a++;
            else b++;
        }
        printf("%d\n",abs(a-b));
        a=b=0;
    }
    return 0;
}
