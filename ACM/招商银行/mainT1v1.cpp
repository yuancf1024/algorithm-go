#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a = 0, b = 0;
        cin >> n;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            if (x == 2) a++;
            else b++;
        }
        int sum = 2*a + 3*b;
        if (sum % 3) cout << "NO" << endl;
        else {
            int t = sum / 3;
            bool flag = false;
            for (int x1 = 0; x1 <= a; x1++) {
                if (2*x1 > t) break;
                if ((t-2*x1)%3) continue;
                int y1 = (t-2*x1)/3;
                for (int x2 = x1; x1 + x2 <= a; x2++) {
                    if (2*x2 > t) break;
                    if ((t-2*x2)%3) continue;
                    int y2 = (t-2*x2)/3;
                    int x3 = a-x1-x2;
                    if (2*x3 > t) continue;
                    if ((t-2*x3)%3) continue;
                    int y3 = (t-2*x3)/3;
                    if (y1+y2+y3 == b) flag = true;
                    if (flag) break;
                }
                if (flag) break;
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        } 
    }
    return 0;
}