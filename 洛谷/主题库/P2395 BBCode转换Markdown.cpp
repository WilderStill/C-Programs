#include<bits/stdc++.h>
using namespace std;
string ans="";
stack<string>stk,name;
int main()
{
	char ch=getchar();
	while(ch!=EOF)
	{
		if(ch=='[')
		{
			ch=getchar();
			string in="";bool syh=1;
			while(ch!=']')in+=ch,ch=getchar();
			if(in[0]=='/')syh=0,in=in.substr(1);
			if(in[0]=='h')
			{
				int cnt=in[1]&15;
				if(syh)
				{
					for(int i=1;i<=cnt;++i)ans+="#";
					ans+=" ";
					stk.push(in);
				}
				else
				{
					if(stk.empty()||stk.top()!=in)
					{
						puts("Match Error");
						return 0;
					}
					stk.pop();
					ans+=" ";
					for(int i=1;i<=cnt;++i)ans+="#";
				}
			}
			else if(in=="i")
			{
				if(syh)
				{
					ans+="*";
					stk.push(in);
				}
				else
				{
					if(stk.empty()||stk.top()!=in)
					{
						puts("Match Error");
						return 0;
					}
					stk.pop();
					ans+="*";
				}
			}
			else if(in[0]=='b')
			{
				if(syh)
				{
					ans+="__";
					stk.push(in);
				}
				else
				{
					if(stk.empty()||stk.top()!=in)
					{
						puts("Match Error");
						return 0;
					}
					stk.pop();
					ans+="__";
				}
			}
			else if(in.substr(0,3)=="url")
			{
				if(syh)
				{
					ans+="[";
					name.push(in.substr(4));
					stk.push(in.substr(0,3));
				}
				else
				{
					if(stk.empty()||stk.top()!=in.substr(0,3))
					{
						puts("Match Error");
						return 0;
					}
					ans+="]("+name.top()+")";
					stk.pop(),name.pop();			
				}
			}
			else if(in.substr(0,3)=="img")
			{
				if(syh)
				{
					ans+="![";
					name.push(in.substr(4));
					stk.push(in.substr(0,3));
				}
				else
				{
					if(stk.empty()||stk.top()!=in.substr(0,3))
					{
						puts("Match Error");
						return 0;
					}
					ans+="]("+name.top()+")";
					stk.pop(),name.pop();			
				}
			}
			else
			{
				if(!syh)
				{
					printf("Uncl");
					puts("osed Mark");
					return 0;
				}
				ch=getchar();
				while(ch=='\n'||ch=='\r')ch=getchar();
				in="";
				while(ch!=EOF)
				{
					in+=ch;
					if(in.size()>=8&&in.substr(in.size()-8)=="[/quote]")break;
					ch=getchar();
				}
				if(ch==EOF)
				{
					puts("Unclosed Mark");
					return 0;
				}
				in.erase(in.size()-8);
				while(in.back()=='\n'||in.back()=='\r')in.pop_back();
				if(ans.back()!='\n'&&ans.back()!='\r')ans+='\n';
				ans+="> ";
				for(auto s:in)
				{
					ans+=s;
					if(s=='\n'||s=='\r')ans+="> ";
				}
				ans+='\n';
			}
		}
		else ans+=ch;
		ch=getchar();
	}
	if(!stk.empty())
	{
		printf("Uncl");
		puts("osed Mark");
		return 0;
	}
	cout<<ans;
    return 0;
}
