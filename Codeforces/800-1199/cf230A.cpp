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

    int s, n;
    cin >> s >> n;
    vector<pair<int,int>> str_bon;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        str_bon.push_back({x, y});
    }
    
    sort(str_bon.begin(), str_bon.end());
    for (auto it: str_bon)
    {
        if (it.first >= s)
        {
            cout << "NO";
            return 0;
        }
        s += it.second;
    }

    cout << "YES";

    return 0;
}