#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

char board[8][8];
bool cols[8];
bool diag1[15]; 
bool diag2[15]; 
int ans = 0;

void solve(int row)
{
    if (row == 8) 
    {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++)
    {
        if (board[row][c] == '.' && !cols[c] && !diag1[row - c + 7] && !diag2[row + c])
        {
            cols[c] = true;
            diag1[row - c + 7] = true;
            diag2[row + c] = true;
            solve(row + 1);
            cols[c] = false;
            diag1[row - c + 7] = false;
            diag2[row + c] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(0);

    cout << ans << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}