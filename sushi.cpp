#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int ans = 0;

    while (i < n && j < m) {
        if (b[j] <= 2 * a[i]) {
            ans++;
            i++;
            j++;
        } else {
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}