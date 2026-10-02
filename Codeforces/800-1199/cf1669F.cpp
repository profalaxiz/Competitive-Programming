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

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int& x : w) cin >> x;

        int left = 0, right = n - 1;
        ll sum_left = 0, sum_right = 0;
        int cnt_left = 0, cnt_right = 0;
        int ans = 0;

        while (left <= right)
        {
            if (sum_left <= sum_right)
            {
                sum_left += w[left];
                cnt_left++;
                left++;
            }
            else 
            {
                sum_right += w[right];
                cnt_right++;
                right--;
            }
            if (sum_left == sum_right) ans = cnt_left + cnt_right;
        }
        cout << ans << '\n';        
    }

    return 0;
}