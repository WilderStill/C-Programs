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
		if(kind==1){puts(s+1);continue;}//ֻ��һ���ַ������ 
		if(kind_2!=kind)//������һ��û�ж��� 
		{
			for(int i=1;i<=26;i++)
				if(alpha[i]==1)//�����ֻ��һ�����ַ� 
				{
					alpha[i]--;
					printchar(i);
					break;
				}
			for(int i=1;i<=26;i++)//������ж��������ϵ��ַ� 
			{
				while(alpha[i])
				{
					alpha[i]--;
					printchar(i);
				}
			}
		}
		else//ÿ�ֶ����������� 
		{
			int cnt=0;
			for(int i=1;i<=26;i++)if(alpha[i]){cnt=alpha[i];break;}//���ҳ����г��ֵ�ASCII����С���ַ��ĳ��ִ��� 
			if(cnt*2<=len+2)//������ֹ�����С�ַ��ĳ��ִ���<=len/2+1 
			{
				int now;
				for(int i=1;i<=26;i++)if(alpha[i]){now=i;break;}//��¼���г��ֵ�ASCII����С���ַ�����ĸ���� 
				alpha[now]-=2;
				printchar(now);//Ȼ���������
				printchar(now);//Ȼ���������*2 
				int i=now+1;
				while(i<=26)
				{
					while(!alpha[i])i++;//�ҵ����г��ֵ�ASCII���С���δ�С���δδ�С�������ַ�����ĸ���� 
					if(i>26)break;
					alpha[i]--;
					printchar(i);//����� 
					if(alpha[now])//Ȼ���������С�ģ�ֱ��������� 
					{
						alpha[now]--;
						printchar(now);
					}
				}
			}
			else
			{
				if(kind==2)//�����2���ַ� 
				{
					int now1,now2;//ն��1-now1����С�ĺ�now1-now2����С�� 
					for(int i=1;i<=26;i++)if(alpha[i]){now1=i;break;}
					for(int i=now1+1;i<=26;i++)if(alpha[i]){now2=i;break;}
					alpha[now1]--;printchar(now1);
					while(alpha[now2]){alpha[now2]--;printchar(now2);}
					while(alpha[now1]){alpha[now1]--;printchar(now1);}
				}
				else //������3���ַ� 
				{
					int now1,now2,now3;//ͬ�Ϸַ���ֻ������2�� 
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
