#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {

    int bronze_b, bronze_a, silver_b, silver_a, gold_b, gold_a, plat_b, plat_a;
    cin >> bronze_b >> bronze_a >> silver_b >> silver_a >> gold_b >> gold_a >> plat_b >> plat_a;
    int gold_promo = plat_a - plat_b;
    int silver_promo = gold_a - gold_b + gold_promo;
    int bronze_promo = silver_a - silver_b + silver_promo;

    cout << bronze_promo << '\n';
    cout << silver_promo << '\n';
    cout << gold_promo << '\n';
    
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);


    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}