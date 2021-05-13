// This matrix is fully usable for int/float, but not for any other classes
#include <iostream>
#include <assert.h>

template <typename T>
class Matrix
{
    const double eps = 1E-06;
    // The size of the matrix
    int nrows_;
    int ncolumns_;
    // The array of pointers
    T **data_;

    // For usability of A[][]
    struct ProxyRow {
        T *row;
        const T &operator[](int n) const { return row[n]; }
        T &operator[](int n) { return row[n]; }
    };
    
public:

    //! Usability: A[][]
    ProxyRow operator[](int n);
    ProxyRow operator[](int n) const;

    //! Constructor of the 'nrows * ncolumns' matrix filled with the value
    Matrix(int nrows, int ncolumns, T value = T{});

    int getRows() const { return nrows_; }
    int getColumns() const { return ncolumns_; }

    Matrix & changeColumn(int n, const Matrix &column) &;
    Matrix & doSquare_max(int val) &;
    Matrix & doSquare_min() &;

    Matrix & subRows(int i, int j, T j_k) &;
    Matrix & swapRows(int i, int j) &;


    //! Print the matrix
    void print() const;
    //! count the determinant of the matrix
    T determinant() const;   

    int columnMax(int j) const;

    template <typename U>
    Matrix(const Matrix<U> &rhs) : 
        nrows_(rhs.getRows()), 
        ncolumns_(rhs.getColumns()), 
        data_(new T *[nrows_]){
        
        for (int i = 0; i < nrows_; ++i) {
            data_[i] = new T[ncolumns_];
            for (int j = 0; j < ncolumns_; ++j)
                data_[i][j] = rhs[i][j];
        }
    }

    Matrix(const Matrix<T> &rhs) : 
        nrows_(rhs.getRows()), 
        ncolumns_(rhs.getColumns()), 
        data_(new T *[nrows_]){
        
        for (int i = 0; i < nrows_; ++i) {
            data_[i] = new T[ncolumns_];
            for (int j = 0; j < ncolumns_; ++j)
                data_[i][j] = rhs[i][j];
        }
    }
    Matrix &operator=(const Matrix &rhs);  

    // Destroy the matrix 
    void destroy();
    ~Matrix();
};

template <typename T>
typename Matrix<T>::ProxyRow Matrix<T>::operator[](int n) {
    ProxyRow temp_row;
    temp_row.row = data_[n];
    return temp_row;
}

template <typename T>
typename Matrix<T>::ProxyRow Matrix<T>::operator[](int n) const {
    ProxyRow temp_row;
    temp_row.row = data_[n];
    return temp_row;
}

template <typename T>
Matrix<T>& Matrix<T>::swapRows(int i, int j) & {
    T* tmp_row = data_[i];
    data_[i] = data_[j];
    data_[j] = tmp_row;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::subRows(int i, int j, T j_k) & {
    assert(i >= 0 && j >= 0 && i < nrows_ && j < ncolumns_);

    for (int m = 0; m < ncolumns_; ++m) {
        data_[i][m] -= (j_k * data_[j][m]);
        if (std::abs(data_[i][m]) < eps)
            data_[i][m] = 0;
    }

    return *this;
}

template <typename T>
Matrix<T>::Matrix(int nrows, int ncolumns, T value) : 
    data_(new T *[nrows]),
    nrows_(nrows),
    ncolumns_(ncolumns) {
    for (int i = 0; i < nrows_; ++i)
    {
        data_[i] = new T[ncolumns];
        for (int j = 0; j < ncolumns_; ++j)
        {
            data_[i][j] = value;
        }
    }
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &rhs)
{
    // If we have 'a = a', may return quickly
    if (&rhs == this)
        return *this;

    // If the size of the other matrix is the same, don't reinitilize
    if (nrows_ != rhs.nrows_ || ncolumns_ != rhs.ncolumns_)
    {
        destroy();

        nrows_ = rhs.nrows_;
        ncolumns_ = rhs.ncolumns_;
        data_ = new T *[nrows_];
    }

    // Copy all values from the right matrix
    for (int i = 0; i < nrows_; ++i)
    {
        data_[i] = new T[ncolumns_];
        for (int j = 0; j < ncolumns_; ++j)
            data_[i][j] = rhs.data_[i][j];
    }

    return *this;
}

template <typename T>
void Matrix<T>::destroy() {
    for (int i = 0; i < nrows_; ++i)
        delete[] data_[i];

    delete[] data_;
}

template <typename T>
Matrix<T>::~Matrix() {
    destroy();
}

template <typename T>
void Matrix<T>::print() const
{
    //std::cout << "Rows: " << nrows_ << std::endl;
    //std::cout << "Columns: " << ncolumns_ << std::endl;

    for (int i = 0; i < nrows_; ++i)
    {
        for (int j = 0; j < ncolumns_; ++j)
        {
            std::cout << data_[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

template <typename T>
int Matrix<T>::columnMax(int j) const {
    int max = j;

    for (int i = j; i < nrows_; ++i) {
        if (std::abs(data_[i][j]) > std::abs(data_[max][j])) {
            max = i;
        }
    }

    return max;
}

template <typename T>
Matrix<T> & Matrix<T>::changeColumn(int n, const Matrix &column) &{
    assert(n < ncolumns_ && n >= 0 && column.getColumns() == 1 && column.getRows() == nrows_);

    for (int i = 0; i < nrows_; ++i)
        data_[i][n] = column.data_[i][0];

    return *this;
}

template <typename T>
Matrix<T> & Matrix<T>::doSquare_max(int val) &{
    if (ncolumns_ == nrows_)
        return *this;

    int old_rows = nrows_;
    int old_column = ncolumns_;

    nrows_ = (nrows_ > ncolumns_)? nrows_ : ncolumns_;
    ncolumns_ = nrows_;
    T** new_data = new T *[nrows_];

    for (int i = 0; i < nrows_; ++i)
    {
        new_data[i] = new T[ncolumns_] {val};
        for (int j = 0; j < old_column; ++j)
            if (i < old_rows)
                new_data[i][j] = data_[i][j];
    }

    old_rows = nrows_;
    destroy();

    nrows_ = old_rows;
    ncolumns_ = nrows_;
    data_ = new_data;

    return *this;
}

template <typename T>
Matrix<T> & Matrix<T>::doSquare_min() &{
    if (ncolumns_ == nrows_)
        return *this;

    int old_rows = nrows_;
    int old_column = ncolumns_;

    nrows_ = (nrows_ < ncolumns_)? nrows_ : ncolumns_;
    ncolumns_ = nrows_;
    T** new_data = new T *[nrows_];

    for (int i = 0; i < nrows_; ++i)
    {
        new_data[i] = new T[ncolumns_];
        for (int j = 0; j < ncolumns_; ++j)
            new_data[i][j] = data_[i][j];
    }

    old_rows = nrows_;
    destroy();

    nrows_ = old_rows;
    ncolumns_ = nrows_;
    data_ = new_data;

    return *this;
}

template <typename T>
    T Matrix<T>::determinant() const {
        assert(ncolumns_ == nrows_);

        // Gauss elimination
        Matrix<long double> temp{*this};

        int sign = 1;
        T res = 1;
        int max = 0;
        long double max_val = 0;

        for (int i = 0; i < nrows_ - 1; ++i) {
            // Find the maximum value in the current column
            // and put the max to the top (if neccesary)
            max = temp.columnMax(i);
            max_val = temp[max][i];
            if (max != i) {
                temp.swapRows(max, i);
                sign *= -1;
            }
            
            if (max_val == 0)
                return 0;

            // Zero all elements under this maximum value
            for (int j = i + 1; j < nrows_; ++j) {
                temp.subRows(j, i, temp[j][i] / max_val);
            }

            res *= temp[i][i];
        }

        res *= (sign * temp[nrows_ - 1][nrows_ - 1]);
        return res;
    }