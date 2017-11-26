#include <bits/stdc++.h>

using namespace std;

int n;
int a[500][500];
int dp[500][500];
int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, 1, -1};

int go(int i, int j)
{
    if (dp[i][j] != 0) return dp[i][j];
    int& ret = dp[i][j] = 1;
    for (int k=0; k<4; k++) {
        int nx = i + xx[k];
        int ny = j + yy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[i][j] < a[nx][ny]) {
            ret = max(ret, go(nx, ny) + 1);
        }
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
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans = max(ans, go(i, j));
        }
    }
    cout << ans;
}
