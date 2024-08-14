#include<bits/stdc++.h>
#define M 11451411
using namespace std;
struct srt
{
	char key;
	srt* ls;
	srt* rs;
	srt(char ch=0):key(ch),ls(NULL),rs(NULL){}
}tree;
srt* build(char ch)
{
	if(ch=='*')return 0;
	return new srt(ch);
}
srt* findn(char ch, srt* t=&tree)
{
	if(t->key==ch) return t;
	srt* ans=0;
	if(t->ls)ans=findn(ch,t->ls);
	if(ans)return ans;
	if(t->rs)ans=findn(ch,t->rs);
	return ans;
}
void preorder(srt* rt)
{
	if(rt==NULL)return;
	printf("%c",rt->key);//´¦Àí 
	preorder(rt->ls);
	preorder(rt->rs);
}
int main()
{
	int n;
	char key,ls,rs;
    scanf("%d",&n);
	cin>>key>>ls>>rs;
	tree.key=key;
	tree.ls=build(ls);
	tree.rs=build(rs);
    for(int i=2;i<=n;i++)
	{
		cin>>key>>ls>>rs;
		srt* tmp=findn(key);
		tmp->ls=build(ls);
		tmp->rs=build(rs);
	}
    preorder(&tree);
    return 0;
}
