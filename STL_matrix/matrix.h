#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>

template <class T>
class MyMatrix
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
            Iterator(MyMatrix<T> matrix); //Как оправдать отсутствие () и ~

            Iterator next();
            T value();
            bool is_end();
            Iterator &operator++();
            //T &operator*();
            bool operator==(Iterator &rightIt);
            bool operator!=(Iterator &rightIt);
        };

    public:
        //Construct And Distruct
        MyMatrix();
        MyMatrix(size_t n, size_t m);
        MyMatrix(MyMatrix<T>& matrix);
        MyMatrix(MyMatrix<T>&& matrix);
        //explicit MyMatrix(std::initializer_list<std::initializer_list<T>> list);
        ~MyMatrix();

        //Equale
        //MyMatrix<T>& operator=(MyMatrix<T>& matrix);

        //Default operations (Mat + Mat)
        MyMatrix<T>& operator+=(MyMatrix<T>& matrix);
        MyMatrix<T>& operator-=(MyMatrix<T>& matrix);
        friend MyMatrix<T> operator+(MyMatrix<T>& newMat, MyMatrix<T>& oldMat);
        friend MyMatrix<T> operator-(MyMatrix<T>& newMat, MyMatrix<T>& oldMat);
        friend MyMatrix<T> operator*(MyMatrix<T>& newMat, MyMatrix<T>& oldMat);

        //Default operations (Mat + Num)
        friend MyMatrix<T> operator+(MyMatrix<T>& newMat, double num);
        friend MyMatrix<T> operator-(MyMatrix<T>& newMat, double num);
        friend MyMatrix<T> operator*(MyMatrix<T>& newMat, double num);
        friend MyMatrix<T> operator/(MyMatrix<T>& newMat, double num);

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
        friend std::ostream& operator <<(std::ostream& out, MyMatrix<T>& matrix);

        //Help Functions
        T** createMatrix();
        void copyMatrix(MyMatrix<T>& oldMat);
        void clearMatrix();

};

#endif // MATRIX_H
