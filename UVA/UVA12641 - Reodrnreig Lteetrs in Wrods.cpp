#include<bits/stdc++.h>
#define S string 
using namespace std;
vector<S>Split(S s)//以空格为边界分割字符串s 
{
    vector<S>res;
    istringstream scin(s);//istringstream类用于执行C++风格的串流的输入操作。
    S tmp;
    while(scin>>tmp)res.push_back(tmp);//读入tmp时遇到空格时会停止读入 
    //for(int i=0;i<res.size();i++)printf("%s\n",res[i].c_str());
    return res;
}
map<S,S>mp;//作用相当于一本翻译SSE到正常单词的字典 
S dictionary,words;
S Start_Sorted_End(S s)//SSE格式（自己编的）就是将一个字符串分成开头的一个字符、中间的排序过的字符和结尾的一个字符，如'string'先拆分成's'+'trin'+'g'，然后会变成'sinrtg'。 
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
		{//多测需清空 
	        mp.clear();
	        splited_dict.clear();splited_words.clear();ans.clear();
		}
        getline(cin,dictionary);getline(cin,words);
        splited_dict=Split(dictionary);//分割字典 
		splited_words=Split(words);//分割输入的字句 
        for(auto it:splited_dict)
		{
            S tmp=Start_Sorted_End(it);
            if(!mp.count(tmp))mp[tmp]=it;//如果map里面没有过这个字符，那么将他存入map中 
        }
        for(auto it:splited_words)
		{
            S tmp=Start_Sorted_End(it);
            if(mp.find(tmp)!=mp.end())ans.push_back(mp[tmp]);//如果map里面有这个字符串的SSE，那么输出map里面的正常单词 
            else ans.push_back(it);//否则输出原来输入的单词 
        }
        for(int i=0;i<ans.size();i++)
		{
			if(i)printf(" "); 
			printf("%s",ans[i].c_str());//输出（或许用cout会好一些 
        }printf("\n");
    }
}
