#include<bits/stdc++.h>
using namespace std;
int n,a[500010],c[500010];
long long ans;
void Merge(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2,i=l,j=mid+1,k=l;
    Merge(l,mid),Merge(mid+1,r);
    while(i<=mid&&j<=r)
    	if(a[i]<=a[j])c[k++]=a[i++];
    	else c[k++]=a[j++],ans+=mid-i+1;
    while(i<=mid)c[k++]=a[i++];
    while(j<=r)c[k++]=a[j++];
    for(int f=l;f<=r;f++)a[f]=c[f];
} 

int main()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    Merge(1,n);
    printf("%lld",ans);
    return 0;
}
