#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 2) ans1++;
            else ans2++;
        }
        int p1 = ans1 / 3, p2 = ans2 / 3;
        ans1 %= 3, ans2 %= 3;
        if (ans1 == 0 && ans2 == 0) cout << "YES\n";
        else {
            if (ans1 != 0) cout << "NO\n";
            else if (ans2 == 2) {
                if (p1 >= 2) cout << "YES\n";
                else cout << "NO\n";
            }
            else if (ans2 == 1) {
                if (p2 != 0) {
                    if (p1 >= 1) cout << "YES\n";
                    else cout << "NO\n";
                }
                else cout << "NO\n";
            }
        }
    }
    return 0;
}