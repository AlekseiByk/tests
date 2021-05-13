#include "matrix.hpp"
#include <iostream>
#include <thread>

#define MAX( a, b) ((a > b)? a : b)
#define MIN( a, b) ((a < b)? a : b)

void calc_func (const Matrix<double> &A,const Matrix<double> &B, Matrix<double> &X, int n, double &Det);

int main (int argc, char *argv[], char *envp[]) 
{
    int m, n, pthread_number;
    std::cin >> m >> n;

    Matrix<double> A {n, m, 0};
    Matrix<double> B {n, 1, 0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin>> A[i][j];

    for (int i = 0; i < n; i++)
        std::cin>> B[i][0];

    std::cin >> pthread_number;
    std::cout<< "*********A\n";
    A.print();
    std::cout<< "*********B\n";
    B.print();
    std::cout<< "**********\n";
    std::cout<< "number of threads = " << pthread_number<< std::endl;
    std::thread * pthread = new std::thread[MIN(m, n) + 1];
    Matrix<double> X {n, 1, 0};

    int j = -1;
    int temp1 = 0;
    int temp2 = 0;
    double Det = 0;

    while (j < MIN(m, n)){

        for (; temp1 < temp2 + pthread_number; temp1++){
            if (j < MIN(m, n)){
                pthread[temp1]  = std::thread(calc_func, std::ref(A), std::ref(B), std::ref(X), j, std::ref(Det));
                j++;
            }
            else{
                break;
            }
        }

        for (; temp2 < temp1; temp2++){
            pthread[temp2].join();
        }
    }

    if (Det != 0){
        for (int i = 0; i < n; i++){
            X[i][0] /= Det;
        }
        std::cout<< "*********X\n";
        X.print();
    }
    else
        std::cout << "Det[A] = " << Det << std::endl; 

    return 0;
}

void calc_func (const Matrix<double> &A,const Matrix<double> &B, Matrix<double> &X, int n, double &Det){

    Matrix<double> A1 {A};
    A1.doSquare_min();    

    if (n == -1){
        Det = A1.determinant();
        return;

    }

    A1.changeColumn(n, B);

    X[n][0] = A1.determinant();
    
    return;
}

