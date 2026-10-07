#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

struct Lab {
    ll a, b, c;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<Lab> labs(n);
        ll min_sum = LLONG_MAX;
        for (auto &[a, b, c] : labs)
        {
            cin >> a >> b >> c;
            min_sum = min(min_sum, a + b + c);
        }
        auto can = [&](ll target)
        {
            ll used = 0;
            for (auto [a, b, c] : labs)
            {
                ll sum = a + b + c;
                if (sum >= target)
                    continue;
                if (a == b && b == c)
                    return false;
                ll need = target - sum;
                if (!(a <= b && b <= c))
                {
                    used += need;
                }
                else
                {
                    ll gap = min(b - a, c - b);
                    ll activation = 2 * (gap + 1);
                    used += need + activation;
                }
                if (used > k)
                    return false;
            }
            return true;
        };
        ll lo = min_sum;
        ll hi = min_sum + k + 1;
        while (lo + 1 < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (can(mid))
                lo = mid;
            else
                hi = mid;
        }
        cout << lo << '\n';
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}