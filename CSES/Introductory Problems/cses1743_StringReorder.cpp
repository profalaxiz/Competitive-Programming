#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <chrono>

using namespace std;

// Types & Containers
using ll = long long;
using str = string;
using vi = vector<int>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

// Macros
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)
#define mp make_pair

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define each_perm(x) sort(all(x)); do
#define end_perm(x) while(next_permutation(all(x))) 

// Loops
#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)

void setIO(string name = "") {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void solve() {
    string s;
    cin >> s;

    int n = s.length();
    vi freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    int cur_max = 0;
    for (int i = 0; i < 26; i++) {
        cur_max = max(cur_max, freq[i]);
    }

    if (cur_max > (n + 1) / 2) {
        cout << -1 << "\n";
        return;
    }

    string res;
    res.reserve(n); 
    int last = -1;

    for (int i = 0; i < n; i++) {
        int L = n - i; 
        
        cur_max = 0;
        int cnt_max = 0;
        for (int j = 0; j < 26; j++) {
            if (freq[j] > cur_max) {
                cur_max = freq[j];
                cnt_max = 1;
            } else if (freq[j] == cur_max) {
                cnt_max++;
            }
        }

        int picked = -1;
        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0) continue; 
            if (j == last) continue;    

            int new_max = cur_max;
            if (freq[j] == cur_max && cnt_max == 1) {
                new_max = cur_max - 1;
            }

            if (new_max <= L / 2) {
                picked = j;
                break;
            }
        }

        if (picked == -1) {
            cout << -1 << "\n";
            return;
        }

        res += (char)(picked + 'A');
        freq[picked]--;
        last = picked;
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // setIO("");

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    auto start_time = chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    auto end_time = chrono::high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
        chrono::duration<double, milli> duration = end_time - start_time;
        cerr << "\n--- Execution Time: " << fixed << setprecision(2) << duration.count() << " ms ---" << endl;
    #endif
    return 0;
}