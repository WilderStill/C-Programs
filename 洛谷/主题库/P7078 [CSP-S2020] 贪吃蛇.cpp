#include<bits/stdc++.h>
#define M 1000010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct snake
{
	int id,val;
	snake(){id=0,val=0;}
	snake(int _id,int _val){id=_id,val=_val;}
	bool operator<(const snake&b)const
	{
		if(val^b.val)return val<b.val;
		return id<b.id;
	}
};
int n,sk[M];
int main()
{
	//freopen("snakes.in","r",stdin);
	//freopen("snakes.out","w",stdout);
	int T=read();
	for(int t=1;t<=T;++t)
	{
		if(t==1)
		{
			n=read();
			for(int i=1;i<=n;++i)sk[i]=read();
		}
		else
		{
			int k=read();
			for(int i=1,id;i<=k;++i)
			{
				id=read();
				sk[id]=read();
			}		
		}
		deque<snake>q1,q2;
        for(int i=1;i<=n;++i)q1.push_back(snake(i,sk[i]));
        int ans;
        while(true)
		{
            if(q1.size()+q2.size()==2)
			{
                ans=1;
                break;
            }
            int minn=q1.front().val,maxn,id;
			q1.pop_front();
            if(q2.empty()||!q1.empty()&&q2.back()<q1.back())
			{
                maxn=q1.back().val,id=q1.back().id;
				q1.pop_back();
            }
			else
			{
                maxn=q2.back().val,id=q2.back().id;
				q2.pop_back();
            }
            auto snk=snake(id,maxn-minn);
            if(q1.empty()||snk<q1.front())
			{
                ans=q1.size()+q2.size()+2;
                int cnt=0;
                while(true)
				{
                    cnt++;
                    if(q1.size()+q2.size()==1)
					{
                        if(!(cnt&1))--ans;
                        break;
                    }
                    int smaxn,sid;
                    if(q2.empty()||!q1.empty()&&q2.back()<q1.back())
					{
                        smaxn=q1.back().val,sid=q1.back().id;
						q1.pop_back();
                    }
					else
					{
                        smaxn=q2.back().val,sid=q2.back().id;
						q2.pop_back();
                    }
                    snk=snake(sid,smaxn-snk.val);
                    if((q1.empty()||snk<q1.front())&&(q2.empty()||snk<q2.front()));
                    else
					{
                        if(!(cnt&1))--ans;
                        break;
                    }
                }
                break;
            }
			else q2.push_front(snk);
		}
    	write(ans);
    	puts("");
	} 
    return 0;
}
