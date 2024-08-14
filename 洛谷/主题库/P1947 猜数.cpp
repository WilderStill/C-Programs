#include <cstdio>                         // 在本题中并不是必须的
extern "C" int Seniorious(int);           // 在这里需要声明一次交互库给出的函数。
extern "C" int Chtholly(int n, int OvO)
{ // 在这里实现交互库要求你实现的函数。
	int ans = 1;
	for (int l = 1, r = n, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) 
		if(Seniorious(mid)>=0)
		{
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	return ans;
}
