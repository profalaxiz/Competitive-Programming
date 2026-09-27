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

    int n;
    cin >> n;
    vector<int> x(n);   
    for (auto& y: x) cin >> y;
    int q;
    cin >> q;
    vector<int> m(q);
    for (auto& y: m) cin >> y;

    // sort(x.rbegin(), x.rend());
    // for (int i = 0; i < q; i++){
    //     int m_i = m[i];
    //     int index = n;
    //     for (int j = 0; j < n; j++)
    //     {   
    //         if (x[j] <= m_i)
    //         {
    //             index = j;
    //             break;
    //         }
    //     }  
    //     int res = n - index;
    //     cout << res << '\n'; 
    // }
    sort(x.begin(), x.end());
    for (int i = 0; i < q; i++)
    {
        int index = upper_bound(x.begin(), x.end(), m[i]) - x.begin();
        cout << index << '\n';
    }



    return 0;
}