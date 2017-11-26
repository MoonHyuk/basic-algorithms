#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[1000][1000];
int dp[1000][1000];

int go(int i, int j)
{
    if (i >= n || j >= m) return 0;
    if (a[i][j] == '0') return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int& ret = dp[i][j] = 1;
    return ret += min(min(go(i+1, j), go(i, j+1)), go(i+1, j+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ans = max(ans, go(i, j));
        }
    }
    cout << ans * ans;
}
