#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int n {3};

    double A[n][n] {
        {1, -1, 1},
        {5, -4, 3},
        {2, 1, 1}};

    double B[n] {
        -4, -12, 11
        };

    double M[n] {};

    int k {}, i {}, j {};


    k = 0;

    do {
        i = k + 1;

        do {
            M[i] = A[i][k] / A[k][k];
            A[i][k] = 0;
            j = k + 1;
            
            do
            {
                A[i][j] = A[i][j] - M[i]*A[k][j];
                j++;
            } while (j < n);

            B[i] = B[i] - M[i]*B[k];
            i++;
        } while(i < n);

        k++;
    } while (k < n - 1);

    cout << "A1\tA2\tA3\t|\tB" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << '\t';
        }
        cout << "|\t" << B[i] << endl;
    }

    // обратная подстановка

    double X[n] {};
    double S {};

    X[n-1] = B[n-1] / A[n-1][n-1];
    i = n - 2;
    do
    {
        j = i + 1;
        S = 0;
        do
        {
            S += A[i][j] * X[j];
            j++;
        } while (j < n);
        X[i] = (B[i] - S) / A[i][i];
        i--;
    } while (i >= 0);

    cout << endl << "X:" << endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << X[i] << '\t';
        
    }
    cout << endl;
    

    return 0;
}
