#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> cards(n);
    for (auto& x: cards) cin >> x;
    
    int sereja = 0, dima = 0;
    int left = 0, right = n - 1;
    bool flag = true;
    while (left <= right)
    {
        if (flag)
        {
            if (cards[left] > cards[right])
            {
                sereja += cards[left];
                left++;
                flag = false;
            }
            else
            {
                sereja += cards[right];
                right--;
                flag = false;
            }
        }
        else
        {
            if (cards[left] > cards[right])
            {
                dima += cards[left];
                left++;
                flag = true;
            }
            else
            {
                dima += cards[right];
                right--;
                flag = true;
            }
        }
    }

    cout << sereja << " " << dima << '\n';
    
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}