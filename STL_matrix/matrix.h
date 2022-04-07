#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>

template <class T>
class Matrix
{
    private:
        size_t row;
        size_t column;
        T** data;

        class Iterator
        {
          private:
            T** originalMatrix;
            size_t rowNow;
            size_t colNow;

          public:
            Iterator();
            Iterator(Matrix<T> matrix);
            ~Iterator();

            Iterator next();
            T value();
            bool is_end();
            Iterator &operator++();
            T &operator*();
            bool operator==(Iterator &rightIt);
            bool operator!=(Iterator &rightIt);
        };

    public:
        Matrix();
        Matrix(size_t n, size_t m);
        Matrix(Matrix<T>& matrix);
        Matrix(Matrix<T>&& matrix);
        explicit Matrix(std::initializer_list<std::initializer_list<T>>);
        ~Matrix();

        Matrix<T>& operator=(Matrix<T>& matrix);
        Matrix<T>& operator+=(Matrix<T>& matrix);
        Matrix<T>& operator-=(Matrix<T>& matrix);

        void set_elem(size_t i, size_t j, T& elem);
        T& get_elem(size_t i, size_t j);
        T& operator()(size_t i, size_t j);

        bool is_square();
        size_t get_count_of_rows();
        size_t get_count_of_columns();

        Iterator begin();
        Iterator end();

        friend Matrix<T> operator+(Matrix<T>& oldMat, Matrix<T>& newMat);
        friend Matrix<T> operator-(Matrix<T>& oldMat, Matrix<T>& newMat);
        friend Matrix<T> operator*(Matrix<T>& oldMat, Matrix<T>& newMat);

        friend Matrix<T> operator+(Matrix<T>& oldMat, double num);
        friend Matrix<T> operator-(Matrix<T>& oldMat, double num);
        friend Matrix<T> operator*(Matrix<T>& oldMat, double num);
        friend Matrix<T> operator/(Matrix<T>& oldMat, double num);

        friend std::ostream& operator <<(std::ostream& out, Matrix<T>& matrix);



};

#endif // MATRIX_H
