//public domain
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

#include <mpblas_qd.h>
#include <mplapack_qd.h>

#define QD_PRECISION_SHORT 16

inline void printnum(qd_real rtmp) {
    std::cout.precision(QD_PRECISION_SHORT);
    if (rtmp >= 0.0) {
        std::cout << "+" << rtmp;
    } else {
        std::cout << rtmp;
    }
    return;
}

//Matlab/Octave format
void printvec(qd_real *a, int len) {
    qd_real tmp;
    printf("[ ");
    for (int i = 0; i < len; i++) {
        tmp = a[i];
        printnum(tmp);
        if (i < len - 1)
            printf(", ");
    }
    printf("]");
}

void printmat(int n, int m, qd_real * a, int lda)
{
    qd_real mtmp;
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("[ ");
        for (int j = 0; j < m; j++) {
            mtmp = a[i + j * lda];
            printnum(mtmp);     
            if (j < m - 1)
                printf(", ");
        }
        if (i < n - 1)
            printf("]; ");
        else
            printf("] ");
    }
    printf("]");
}
void Frank(mplapackint n) {
    mplapackint lwork, liwork, info, m;
    qd_real *a = new qd_real[n * n];
    qd_real *z = new qd_real[n * n]; //not used
    mplapackint *isuppz = new mplapackint[2 * n]; //not used
    qd_real *w = new qd_real[n];
    qd_real *lambda = new qd_real[n];
    qd_real *reldiff = new qd_real[n];
    qd_real vldummy;
    qd_real vudummy;
    mplapackint ildummy;
    mplapackint iudummy;
    qd_real abstol = Rlamch_qd("U");
    qd_real PI;
    PI = pi(PI);

    // setting A matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[(i - 1) + (j - 1) * n] = n - std::max(i, j) + 1;
        }
    }
    printf("a ="); printmat(n, n, a, n); printf("\n");

    // work space query
    lwork = -1;
    qd_real *work = new qd_real[1];
    liwork = -1;
    mplapackint *iwork = new mplapackint[1];

    Rsyevr("N", "A", "U", n, a, n, vldummy, vudummy, ildummy, iudummy, abstol, m, w, z, n, isuppz, work, lwork, iwork, liwork, info);
    lwork = (int)cast2double(work[0]);
    delete[] work;
    work = new qd_real[std::max((mplapackint)1, lwork)];
    liwork = iwork[0];
    delete[] iwork;
    iwork = new mplapackint[std::max((mplapackint)1, liwork)];

    // diagonalize matrix
    Rsyevr("N", "A", "U", n, a, n, vldummy, vudummy, ildummy, iudummy, abstol, m, w, z, n, isuppz, work, lwork, iwork, liwork, info);

    // print out
    printf("#eigenvalues \n");
    printf("w ="); printvec(w, n); printf("\n");

    // print out
    printf("# analytic eigenvalues\n");
    for (int i = 1; i <= n; i++) {
        lambda[(n - i)] = 0.5 * 1.0 / (1.0 - cos((2.0 * i - 1.0) * PI / castREAL_qd(2 * n + 1)));
    }
    printf("lambda ="); printvec(lambda, n); printf("\n");

    for (int i = 1; i <= n; i++) {
        reldiff[i - 1] = abs((lambda[i - 1] - w[i - 1]) / lambda[i - 1]);
    }
    printf("reldiff ="); printvec(reldiff, n); printf("\n");

    qd_real maxreldiff = 0.0;
    maxreldiff = reldiff[0]; 
    for (int i = 2; i <= n; i++) {
        maxreldiff = std::max(reldiff[i - 1], maxreldiff);
    }
    printf("maxreldiff_%d =", (int)n); printnum(maxreldiff); printf("\n");

    delete[] iwork;
    delete[] work;
    delete[] reldiff;
    delete[] lambda;
    delete[] w;
    delete[] isuppz;
    delete[] z;
    delete[] a;
}

int main(int argc, char *argv[]) {
    int STARTN = 100;
    int ENDN = 1000;
    int STEPN = 100;
    if (argc != 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp("-STEPN", argv[i]) == 0) {
                STEPN = atoi(argv[++i]);
            } else if (strcmp("-STARTN", argv[i]) == 0) {
                STARTN = atoi(argv[++i]);
            } else if (strcmp("-ENDN", argv[i]) == 0) {
                ENDN = atoi(argv[++i]);
            }
        }
    }
    for (int n = STARTN; n <= ENDN; n = n + STEPN) {
        printf("# Eigenvalues of Frank matrix of order n=%d\n", n);
        Frank((mplapackint)n);
    }
}
