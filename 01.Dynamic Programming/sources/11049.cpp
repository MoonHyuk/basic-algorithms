#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
int dp[501][501];

int go(int i, int j)
{
    if (i == j) {
        return 0;
    }
    if (i + 1 == j) {
        return v[i].first * v[i].second * v[j].second;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int& ret = dp[i][j] = 1<<31 - 1;
    for (int k=i; k<j; k++) {
        ret = min(ret, go(i, k) + go(k+1, j) + v[i].first * v[k].second * v[j].second);
    }
    return ret;
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
        int r, c;
        cin >> r >> c;
        v.push_back({r, c});
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, n-1);
}
