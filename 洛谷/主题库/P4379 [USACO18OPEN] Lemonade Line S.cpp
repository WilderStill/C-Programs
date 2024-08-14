#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    sort(a,a+n);
    for (int i = n - 1;i >= 0;i--){
        if (a[i] < ans) break;
        ans++;
    }
    cout << ans;
    return 0;
}
