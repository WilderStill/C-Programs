#include<bits/stdc++.h>
#define S string 
using namespace std;
vector<S>Split(S s)//�Կո�Ϊ�߽�ָ��ַ���s 
{
    vector<S>res;
    istringstream scin(s);//istringstream������ִ��C++���Ĵ��������������
    S tmp;
    while(scin>>tmp)res.push_back(tmp);//����tmpʱ�����ո�ʱ��ֹͣ���� 
    //for(int i=0;i<res.size();i++)printf("%s\n",res[i].c_str());
    return res;
}
map<S,S>mp;//�����൱��һ������SSE���������ʵ��ֵ� 
S dictionary,words;
S Start_Sorted_End(S s)//SSE��ʽ���Լ���ģ����ǽ�һ���ַ����ֳɿ�ͷ��һ���ַ����м����������ַ��ͽ�β��һ���ַ�����'string'�Ȳ�ֳ�'s'+'trin'+'g'��Ȼ�����'sinrtg'�� 
{
    S tmp,res;
	tmp.clear(),res.clear();
    for(int i=1;i<s.size()-1;i++)tmp+=s[i];
    sort(tmp.begin(),tmp.end());
    res+=s[0];res+=tmp;res+=s[s.size()-1];
    //cout<<res<<endl;
    return res;
}
int t;
vector<S>splited_dict,splited_words,ans;
int main()
{
    scanf("%d",&t);
    getchar();
    while(t--)
	{
		{//�������� 
	        mp.clear();
	        splited_dict.clear();splited_words.clear();ans.clear();
		}
        getline(cin,dictionary);getline(cin,words);
        splited_dict=Split(dictionary);//�ָ��ֵ� 
		splited_words=Split(words);//�ָ�������־� 
        for(auto it:splited_dict)
		{
            S tmp=Start_Sorted_End(it);
            if(!mp.count(tmp))mp[tmp]=it;//���map����û�й�����ַ�����ô��������map�� 
        }
        for(auto it:splited_words)
		{
            S tmp=Start_Sorted_End(it);
            if(mp.find(tmp)!=mp.end())ans.push_back(mp[tmp]);//���map����������ַ�����SSE����ô���map������������� 
            else ans.push_back(it);//�������ԭ������ĵ��� 
        }
        for(int i=0;i<ans.size();i++)
		{
			if(i)printf(" "); 
			printf("%s",ans[i].c_str());//�����������cout���һЩ 
        }printf("\n");
    }
}
