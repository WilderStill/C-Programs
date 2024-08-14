#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define M 511414
using namespace std;
using namespace __gnu_pbds;
int n,num[M],cnt,tot;
map<string,int> mp;
string ss[M];
struct node
{
    int val,id;
    bool operator < (const node &x) const {return val==x.val?id<x.id:val>x.val;}
};
tree<node,null_type,less<node>,rb_tree_tag,tree_order_statistics_node_update> t;
int main()
{
	scanf("%d",&n);
	char c;
	string s;
	int numt,tp;
    while(n--)
	{
		cin>>c>>s;
        if(c=='+')
		{
            if(mp[s])
			{
                tp=mp[s];
				t.erase(node{num[tp],tp});
				tot--;
            }
            mp[s]=++cnt;
			scanf("%d",&num[cnt]);
			t.insert(node{num[cnt],cnt});
			tot++;
            ss[cnt]=s;
        }
        else if(c=='?'&&!isdigit(s[0])) 
		{
            numt=mp[s];
            printf("%d\n",t.order_of_key(node{num[numt],numt})+1);
        }
        else
		{
            numt=0;
            for(int i=0;i<=s.size()-1;i++)numt=(numt<<3)+(numt<<1)+(s[i]^48);
        	tp=min(tot,numt+9);
            for(int i=numt-1;i<=tp-1;i++)printf("%s ",ss[t.find_by_order(i)->id].c_str());
			printf("\n");
        }
    }
    return 0;
}    
