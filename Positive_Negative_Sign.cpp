#include <iostream>
#include <cmath>

using namespace std;

void solve(int A, int B, int C, long long k) {
    long long max_a = min((long long)pow(10, A) - 1, k - 1);
    long long max_b = min((long long)pow(10, B) - 1, k - 1);

    long long count = (max_a + 1) * (max_b + 1);
    if (count < k) {
        cout << -1 << endl;
        return;
    }

    long long a = 1, b = 1;
    while (k > 0) {
        long long count_a = min(max_a - a + 1, k);
        long long count_b = min(max_b - b + 1, k);

        count = count_a * count_b;

        if (count >= k) {
            for (int i = 0; i < count_a; ++i) {
                if (b > max_b) {
                    break;
                }
                cout << a + i << " + " << b << " = " << a + i + b << endl;
                --k;
                if (k == 0) {
                    return;
                }
            }
            ++b;
        } else {
            k -= count;
            ++a;
        }
    }
}

int main() {
    int t;
    cin >> t;  // Read the number of test cases

    while (t--) {
        int A, B, C;
        long long k;
        cin >> A >> B >> C >> k;  // Read A, B, C, and k

        solve(A, B, C, k);
    }

    return 0;
}
