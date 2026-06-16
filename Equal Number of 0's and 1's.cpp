#include <bits/stdc++.h>
using namespace std;

int maxLen(string s) {
    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0, ans = 0;

    for (int i = 0; i < s.size(); i++) {
        sum += (s[i] == '1') ? 1 : -1;

        if (mp.count(sum))
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << maxLen(s);
    return 0;
}