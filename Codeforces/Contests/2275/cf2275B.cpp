#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

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
        cin >> n;
        string s;
        cin >> s;
        vector<bool> printed(n + 1, false);
        stack<int> st;

        for (int i = 1; i <= n; i++) {
            char cmd = s[i - 1];

            if (cmd == '1') {
                st.push(i);
            }
            else if (cmd == '2') {
                if (!st.empty()) {
                    int doc = st.top();
                    st.pop();
                    printed[doc] = true;
                }
                else {
                    printed[i] = true;
                }
            }
            else { 
                printed[i] = true;
            }
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (!printed[i]) {
                ans.push_back(i);
            }
        }
        cout << ans.size() << '\n';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}