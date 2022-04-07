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

            size_t rowMax;
            size_t colMax;

            bool end;

          public:
            Iterator(Matrix<T> matrix); //Как оправдать отсутствие () и ~

            Iterator next();
            T value();
            bool is_end();
            Iterator &operator++();
            T &operator*();
            bool operator==(Iterator &rightIt);
            bool operator!=(Iterator &rightIt);
        };

    public:
        //Construct And Distruct
        Matrix();
        Matrix(size_t n, size_t m);
        Matrix(Matrix<T>& matrix);
        Matrix(Matrix<T>&& matrix);
        explicit Matrix(std::initializer_list<std::initializer_list<T>> list);
        ~Matrix();

        //Equale
        Matrix<T>& operator=(Matrix<T>& matrix);

        //Default operations (Mat + Mat)
        Matrix<T>& operator+=(Matrix<T>& matrix);
        Matrix<T>& operator-=(Matrix<T>& matrix);
        friend Matrix<T> operator+(Matrix<T>& newMat, Matrix<T>& oldMat);
        friend Matrix<T> operator-(Matrix<T>& newMat, Matrix<T>& oldMat);
        friend Matrix<T> operator*(Matrix<T>& newMat, Matrix<T>& oldMat);

        //Default operations (Mat + Num)
        friend Matrix<T> operator+(Matrix<T>& newMat, double num);
        friend Matrix<T> operator-(Matrix<T>& newMat, double num);
        friend Matrix<T> operator*(Matrix<T>& newMat, double num);
        friend Matrix<T> operator/(Matrix<T>& newMat, double num);

        //Some Ways to Set or Get Element
        void set_elem(size_t i, size_t j, T& elem);
        T& get_elem(size_t i, size_t j);
        T& operator()(size_t i, size_t j);
        T* operator[](size_t i); //Чуть привычней, чем ()
        bool is_square();
        size_t get_count_of_rows();
        size_t get_count_of_columns();

        //Create Iterator
        Iterator begin();
        Iterator end();

        //Output Matrix
        friend std::ostream& operator <<(std::ostream& out, Matrix<T>& matrix);

        //Help Functions
        T** createMatrix();
        void copyMatrix(Matrix<T>& oldMat);

};

#endif // MATRIX_H
