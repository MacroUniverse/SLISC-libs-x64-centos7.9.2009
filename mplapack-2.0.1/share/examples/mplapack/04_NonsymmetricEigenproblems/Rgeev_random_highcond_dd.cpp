//public domain
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

#include <mpblas_dd.h>
#include <mplapack_dd.h>

#define DD_PRECISION_SHORT 16

inline void printnum(dd_real rtmp) {
    std::cout.precision(DD_PRECISION_SHORT);
    if (rtmp >= 0.0) {
        std::cout << "+" << rtmp;
    } else {
        std::cout << rtmp;
    }
    return;
}

//Matlab/Octave format
void printvec(dd_real *a, int len) {
    dd_real tmp;
    printf("[ ");
    for (int i = 0; i < len; i++) {
        tmp = a[i];
        printnum(tmp);
        if (i < len - 1)
            printf(", ");
    }
    printf("]");
}

void printmat(int n, int m, dd_real * a, int lda)
{
    dd_real mtmp;
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
//taken from https://math.stackexchange.com/questions/1275358/how-to-generate-3-times-3-integer-matrices-with-integer-eigenvalues
#include <random>

int compare_real(const void *a, const void *b)
{
    return *(dd_real*)a > *(dd_real*)b;
}

int main(int argc, char *argv[]) {
    mplapackint n = 15;
    mplapackint dispersion = 3;
    if (argc != 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp("-DIMN", argv[i]) == 0) {
                n = atoi(argv[++i]);
            }
            if (strcmp("-DISPERSION", argv[i]) == 0) {
                dispersion = atoi(argv[++i]);
            }
        }
    }

    printf("#dimension %d, dispersion = %d \n", (int)n, (int)dispersion);
    dd_real *a = new dd_real[n * n];
    dd_real *aorg = new dd_real[n * n];
    dd_real *ainv = new dd_real[n * n];
    dd_real *s = new dd_real[n * n];
    dd_real *wr = new dd_real[n];
    dd_real *wi = new dd_real[n];
    dd_real *vl = new dd_real[n * n]; //not used
    dd_real *vr = new dd_real[n * n]; //not used

    mplapackint *ipiv = new mplapackint[n];
    mplapackint info;
    mplapackint lwork;

    // work space query
    lwork = -1;
    dd_real *work = new dd_real[1];
    Rgeev("N", "N", n, a, n, wr, wi, vl, n, vr, n, work, lwork, info);
    lwork = (int)cast2double(work[0]);
    delete[] work;
    work = new dd_real[std::max((mplapackint)1, lwork)];

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::normal_distribution<> dist(0, (double)dispersion);
    std::normal_distribution<> dist2(0.0, (double)dispersion);

    // Generation of high condition integer matrix. 
    // Strategy. Generate a matrix whose elements are integer with determinant = 1.
    // Then the elements of inverse of the matrix is also integer.
    // Prepare a geometric integer series, and obtain a matrix with diagonal elements by the series.
    // Calculate A-1 S A.
    //1. Set Hessenberg matirx with a[1,n] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                int r = dist(engine);
                   a[i + j * n] = r;
                aorg[i + j * n] = r;
            } else if (j == i) {
                int r = dist(engine);
                while (r == 0) {
                    r = dist(engine);
                }
                   a[i + j * n] = r;
                aorg[i + j * n] = r;
            } else if (j == i - 1) {
                   a[i + j * n] = 1.0;
                aorg[i + j * n] = 1.0;
            } else {
                   a[i + j * n] = 0.0;
                aorg[i + j * n] = 0.0;
            }
        }
    }
       a[0 + (n - 1) * n] = 0.0;
    aorg[0 + (n - 1) * n] = 0.0;
    printf("split_long_rows(0)\n");
    printf("aorg ="); printmat(n, n, aorg, n); printf("\n");

    //2. get determinant via LU factorization
    Rgetrf(n, n, a, n, ipiv, info);
    //printf("aLU ="); printmat(n, n, a, n); printf("\n");
    dd_real det = 1;
    for (int i = 0; i < n; i++) {
        det = det * a[i + i * n];
        if (ipiv[i] != i+1) det = det * -1.0;
    }
    printf("det="); printnum(det); printf("\n");

    //3. Set Hessenberg matirx with a[1,n] = 0;
    aorg[0 + (n - 1) * n] = -det + 1;
    printf("anew ="); printmat(n, n, aorg, n); printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ainv[i + j * n] = aorg[i + j * n];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i + j * n] = 0.0;
        }
    }
    //4. genrarate a random geometric series. This part depends on the size of mplapackint = int64_t.
    for (int i = 0; i < n; i++) s[i + i * n] = abs((mplapackint)(pow(10.0, (double)(i)) * dist2(engine)));
    s[0] = 1.0;
    printf("s = ["); for (int i = 0; i < n; i++) {printnum(s[ i + i * n]); printf (" "); } printf("]\n");

    //5. inverse matrix. All the elements are integers.
    Rgetrf(n, n, ainv, n, ipiv, info);
    Rgetri(n, ainv, n, ipiv, work, lwork, info);

    // A' = Ainv * S * A
    printf("ainv ="); printmat(n, n, ainv, n); printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dd_real rtmp = 0.0;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                rtmp = rtmp + ainv [i + k * n] * s[k + l * n] * aorg[l + j *n];
		}
            }
            a[i + j * n ] = rtmp;
        }
    }
    printf("a ="); printmat(n, n, a, n); printf("\n");
    //6. Check eigenvalues. These must be the same as the obtained series in 4.
    Rgeev("V", "V", n, a, n, wr, wi, vl, n, vr, n, work, lwork, info);

    qsort(wr, n, sizeof(dd_real), compare_real);
    for (int i = 0; i < n; i = i + 1) {
        printf("w_%d = ", (int)i); printnum(wr[i]); printf("\n");
    }

    printf("exactw = ["); for (int i = 0; i < n; i++) {printnum(s[ i + i * n]); printf (" "); } printf("]\n");

    delete[] ipiv;
    delete[] vl;
    delete[] vr;
    delete[] wi;
    delete[] wr;
    delete[] work;
    delete[] s;
    delete[] aorg;
    delete[] ainv;
    delete[] a;
}
