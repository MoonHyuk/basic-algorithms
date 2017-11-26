#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int n;
int a[501];
int s[501];
int dp[501][501];

int go(int i, int j)
{
    if (i == j) return 0;
    if (i + 1 == j) {
        return a[i] + a[j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int& ret = dp[i][j] = INF;
    for (int k=i; k<j; k++) {
        ret = min(ret, go(i, k) + go(k+1, j));
    }
    ret += s[j] - s[i-1];
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            sum += a[i];
            s[i] = sum;
        }
        memset(dp, -1, sizeof(dp));
        cout << go(1, n) << '\n';
    }
}
