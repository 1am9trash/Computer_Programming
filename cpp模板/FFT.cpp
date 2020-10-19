#include <bits/stdc++.h>
using namespace std;

// FFT
// edit by Jason

// 必須為比 (nA + nB - 1) 大的 2 的次方
#define MAXN = 1000000;

typedef complex<double> cplx;
cplx A[MAXN + 5], B[MAXN + 5], C[MAXN + 5];

int len;
void FFT(cplx *A, int n, int type) {
    const double PI = acos(-1);
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(A[i], A[j]);
        for (int k = (n >> 1); (j ^= k) < k; k >>= 1)
            ;
    }
    for (int s = 2; s <= n; s <<= 1) {
        int t = (s >> 1);
        cplx u = cplx(cos(type * PI / t), sin(type * PI / t));
        for (int i = 0; i < n; i += s) {
            cplx r = cplx(1, 0);
            for (int j = 0; j < t; j++, r = r * u) {
                cplx e = A[i + j], o = A[i + j + t];
                A[i + j] = e + r * o;
                A[i + j + t] = e - r * o;
            }
        }
    }
}
void FFT(cplx *A, int &nA, cplx *B, int &nB) {
    // A[i] B[i] 為 x^i 的係數
    // nA 為 A(x) 的項數 = degree(A) + 1
    // nB 為 B(x) 的項數 = degree(B) + 1
    // nA + nB - 1 為 C(x) 的項數 = degree(A) + 1
    // C 即為 A(x) * B(x) 的係數
    len = 1;
    while (len < (nA + nB - 1))
        len <<= 1;
    FFT(A, len, 1);
    FFT(B, len, 1);
    for (int i = 0; i < len; i++)
        C[i] = A[i] * B[i];
    FFT(C, len, -1);
    for (int i = 0; i < nA + nB - 1; i++) {
        C[i] = {round(real(C[i]) / len), 0};
    }
}

int main() {

    return 0;
}