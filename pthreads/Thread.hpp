#include "matrix.hpp"
#include <pthread.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <unistd.h>

class mission_t{
public:
    Matrix<double> *A;
    double answer;

    mission_t();
    ~mission_t ();
};