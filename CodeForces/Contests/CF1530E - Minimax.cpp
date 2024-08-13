#include<bits/stdc++.h>
#define M 11451411
using namespace std;
int t,kind,alpha[30];
char s[M];
void printchar(int x){putchar(x+'a'-1);}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		kind=0;
		int kind_2=0,len=strlen(s+1);
		memset(alpha,0,sizeof(alpha));
		for(int i=1;i<=len;i++)
		{
			if(!alpha[s[i]-'a'+1])kind++;
			alpha[s[i]-'a'+1]++;
			if(alpha[s[i]-'a'+1]==2)kind_2++;
		}
		if(kind==1){puts(s+1);continue;}//只有一种字符的情况 
		if(kind_2!=kind)//至少有一种没有二个 
		{
			for(int i=1;i<=26;i++)
				if(alpha[i]==1)//先输出只有一个的字符 
				{
					alpha[i]--;
					printchar(i);
					break;
				}
			for(int i=1;i<=26;i++)//再输出有二个及以上的字符 
			{
				while(alpha[i])
				{
					alpha[i]--;
					printchar(i);
				}
			}
		}
		else//每种都至少有两个 
		{
			int cnt=0;
			for(int i=1;i<=26;i++)if(alpha[i]){cnt=alpha[i];break;}//先找出其中出现的ASCII码最小的字符的出现次数 
			if(cnt*2<=len+2)//如果出现过的最小字符的出现次数<=len/2+1 
			{
				int now;
				for(int i=1;i<=26;i++)if(alpha[i]){now=i;break;}//记录其中出现的ASCII码最小的字符的字母表编号 
				alpha[now]-=2;
				printchar(now);//然后先输出它
				printchar(now);//然后先输出它*2 
				int i=now+1;
				while(i<=26)
				{
					while(!alpha[i])i++;//找到其中出现的ASCII码次小，次次小，次次次小……的字符的字母表编号 
					if(i>26)break;
					alpha[i]--;
					printchar(i);//输出它 
					if(alpha[now])//然后再输出最小的，直到它输出完 
					{
						alpha[now]--;
						printchar(now);
					}
				}
			}
			else
			{
				if(kind==2)//如果有2种字符 
				{
					int now1,now2;//斩成1-now1中最小的和now1-now2中最小的 
					for(int i=1;i<=26;i++)if(alpha[i]){now1=i;break;}
					for(int i=now1+1;i<=26;i++)if(alpha[i]){now2=i;break;}
					alpha[now1]--;printchar(now1);
					while(alpha[now2]){alpha[now2]--;printchar(now2);}
					while(alpha[now1]){alpha[now1]--;printchar(now1);}
				}
				else //至少有3种字符 
				{
					int now1,now2,now3;//同上分法，只不过分2次 
					for(int i=1;i<=26;i++)if(alpha[i]){now1=i;break;}
					for(int i=now1+1;i<=26;i++)if(alpha[i]){now2=i;break;}
					for(int i=now2+1;i<=26;i++)if(alpha[i]){now3=i;break;}
					alpha[now1]--,alpha[now2]--;
					printchar(now1);printchar(now2);
					while(alpha[now1]){alpha[now1]--;printchar(now1);}
					printchar(now3);alpha[now3]--;
					int i=now1+1;
					while(i<=26)
					{
						while(!alpha[i])i++;
						if(i>26)break;
						alpha[i]--;
						printchar(i);
					}
				}
			}
		}
		puts("");
	}
	return 0;
}
