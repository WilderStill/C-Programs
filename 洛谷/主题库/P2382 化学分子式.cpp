#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int stk[11451411];
int sum(string elements)
{
    int top=0;stk[0]=0;
	string Element;
    for(int i=0;i<elements.length();i++)
	{
        if(elements[i]=='(')top++;
        if(isalpha(elements[i]))
		{
            if('a'<=elements[i+1]&&elements[i+1]<='z')Element=elements.substr(i,2),stk[top]+=mp[Element],i++;
            else Element=elements.substr(i,1),stk[top]+=mp[Element];
            if(!mp[Element]) return 0;
        }
        if(isdigit(elements[i]))
		{
            int tmp=0;
            while(isdigit(elements[i]))tmp=tmp*10+elements[i]-'0',i++;i--;
			stk[top]+=(tmp-1)*mp[Element];
        }
        if(elements[i]==')')
		{
            int tmp=0;i++;
            while(isdigit(elements[i]))tmp=tmp*10+elements[i]-'0',i++;
            stk[top-1]+=tmp*stk[top];
            i--,stk[top--]=0;
        }
    }
    return 1;
}
int main()
{
	string defElements,readThings;
    cin>>defElements;
    for(int tmp;defElements!="END_OF_FIRST_PART";)
	{
        scanf("%d",&tmp);
        mp[defElements]=tmp;
		cin>>defElements;
    }
    cin>>readThings;
    for(;readThings!="0";)
	{
		sum(readThings)?printf("%d\n",stk[0]):printf("UNKNOWN\n");
        cin>>readThings;
    }
    return 0;
}
