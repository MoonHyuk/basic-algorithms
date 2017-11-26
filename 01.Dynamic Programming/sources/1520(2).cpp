#include <bits/stdc++.h>

using namespace std;

int board[502][502];
int dp[502][502];
int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, 1, -1};
int n, m;

int go(int i, int j)
{
    if (i == 1 && j == 1) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = 0;
    for (int k=0; k<4; k++) {
        int nx = i + xx[k];
        int ny = j + yy[k];
        if (board[nx][ny] && board[nx][ny] > board[i][j]) {
            dp[i][j] += go(nx, ny);
        }
    }
    return dp[i][j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> board[i][j];
        }
    }
    go(n, m);
    cout << dp[n][m];
}
