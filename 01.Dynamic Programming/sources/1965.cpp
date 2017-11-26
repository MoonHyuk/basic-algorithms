#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000];
int dp[1000];

int go(int i)
{
    if (i==0) return 1;
    if (dp[i] != 0) return dp[i];
    dp[i] = 1;
    for (int j=0; j<i; j++) {
        if (a[i] > a[j]) {
            dp[i] = max(dp[i], go(j) + 1);
        }
    }
    return dp[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, go(i));
    }
    cout << ans;
}
