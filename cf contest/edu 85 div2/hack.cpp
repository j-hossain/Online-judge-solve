#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i = 0, qaq = 0, maxp = 0, maxc = 0;
        bool tf = true;
        while (n--) {
            int p, c;
            cin >> p >> c;
if (tf) {
            if (p >= maxp && c >= maxc) {
                if (c > p) {
                    tf = false;
                } else if (p > c) {
                    if (p - c >= qaq) {
                        qaq = p - c;
                    } else {
                        tf = false;
                    }
                } else {
                    if (qaq != 0) {
                        tf = false;
                    }
                }
                maxc = c;
                maxp = p;
            } else {
                tf = false;
            }
            }

        }
        if (tf) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
