#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int& x: heights) cin >> x;
    ll sum = 0; 
    for (int i = 0; i < k; i++) sum += heights[i];
    ll min_sum = sum;
    int min_idx = 0;
    for (int r = k; r < n; r++)
    {
        // [r-k+1 ... r]
        sum += heights[r];
        sum -= heights[r - k];
        if (sum < min_sum) 
        {
            min_idx = r - k + 1;
            min_sum = sum;
        }
    }

    cout << min_idx + 1 << '\n';

    return 0;
}