#include <iostream>

using namespace std;

int getPower(int k, int N) {
    const int MOD = 1000000007;
    if (N == 0) return 1;
    if (N == 1) return k;
    if (N & 1) return (getPower(k, N-1) * k) % MOD;
    long long tmp = static_cast<long long>(k) * k % MOD;
    return getPower(tmp, N >> 1);
}

int main() {
    int k, N;
    while (cin >> k >> N) {
        cout << "pow(" << k << ", " << N << ") = " << getPower(k, N) << endl;
    }

    return 0;
}
