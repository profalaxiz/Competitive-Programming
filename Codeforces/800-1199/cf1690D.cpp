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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll best = LLONG_MIN;
        ll count = 0;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            if (s[right] == 'B') count++;
            if (right - left + 1 > k)
            {
                if (s[left] == 'B') 
                {
                    count--;
                }
                left++;
            }
            if (right - left + 1 == k) best = max(best, count);
        }
        cout << k - best << '\n';
    }

    return 0;
}