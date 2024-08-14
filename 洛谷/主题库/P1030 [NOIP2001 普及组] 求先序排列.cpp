#include<bits/stdc++.h>
using namespace std;
int num=0;
char mid[11],back[11];
void search(int lmid,int rmid,int lback,int rback)
{
	if (lmid > rmid || lback > rback)
		return ;
	if (back[rback]=='\0')
		return ;
	else
		cout<<back[rback];
	char root=back[rback];
	int rtid;
	for (int i = lmid;i <= rmid;i++)
	{
		if (mid[i]==root)
		{
			rtid=i;
			break;
		}
	}
	int len=rtid-1-lmid;
	search(lmid,rtid-1,lback,lback+len);
	search(rtid+1,rmid,lback+len+1,rback-1);
	return ;
}
int main (){
	scanf("%s%s",mid,back);
	search(0,strlen(mid)-1,0,strlen(back)-1);
	return 0;
}
