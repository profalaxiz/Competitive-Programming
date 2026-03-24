#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    string s;
    if (cin >> s) {
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'A']++;
        }

        int odd_count = 0;
        char odd_char = '?';
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                odd_char = i + 'A';
            }
        }

        if (odd_count > 1) {
            cout << "NO SOLUTION\n";
            return;
        }

        string left_half = "";
        for (int i = 0; i < 26; ++i) {
            // Append half of the characters
            left_half += string(counts[i] / 2, i + 'A'); 
        }

        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        if (odd_count == 1) {
            cout << left_half << odd_char << right_half << "\n";
        } else {
            cout << left_half << right_half << "\n";
        }
    }
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