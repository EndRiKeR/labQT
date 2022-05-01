#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T>
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
            Iterator(MyMatrix<T>& matrix, bool end_state); //Как оправдать отсутствие () и ~
            //explicit Iterator(MyMatrix<T>::Iterator oldIt);

            Iterator next();
            T value();
            bool is_end();
            Iterator& operator++();
            Iterator operator++(int i);
            T& operator*();
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
        MyMatrix<T>& operator=(MyMatrix<T>& matrix);
        MyMatrix<T>& operator=(MyMatrix<T>&& oldMat);

        //Default operations (Mat + Mat)
        MyMatrix<T>& operator+=(MyMatrix<T>& oldMat);
        MyMatrix<T>& operator-=(MyMatrix<T>& oldMat);
        MyMatrix<T>& operator+(MyMatrix<T>& oldMat);
        MyMatrix<T>& operator-(MyMatrix<T>& oldMat);
        //MyMatrix<T>& operator*(MyMatrix<T>& oldMat);

        //Default operations (Mat + Num)
        MyMatrix<T> operator+(double num);
        MyMatrix<T> operator-(double num);
        MyMatrix<T> operator*(double num);
        MyMatrix<T> operator/(double num);

        //Some Ways to Set or Get Element
        void set_elem(size_t i, size_t j, T& elem);
        T& get_elem(size_t i, size_t j);
        T& operator()(size_t i, size_t j);
        T* operator[](size_t i); //Чуть привычней, чем ()
        bool is_square();
        size_t get_count_of_rows();
        size_t get_count_of_columns();
        T** get_pointer_on_data();

        //Create Iterator
        Iterator begin();
        Iterator end();

        //Output Matrix
        friend std::ostream& operator<<(std::ostream& out, MyMatrix<T>& matrix)
        {
            if (matrix.data != nullptr && (matrix.row != 0 || matrix.column != 0)) {
                for (size_t i = 0; i < matrix.row; ++i) {
                    for (size_t j = 0; j < matrix.column; ++j) {
                        out << "[" << matrix[i][j] << "]\t";
                    }
                    out << std::endl;
                }
                out << std::endl;
            } else {
                if (matrix.row !=0 || matrix.column != 0) {
                    throw std::string("Error! << can't print matrix");
                    return out;
                } else {
                    throw std::string("Error! << can't print nullptr matrix!");
                    return out;
                }
            }
            return out;
        }

        //Help Functions
        T** createMatrix();
        void copyMatrix(MyMatrix<T>& oldMat);
        void clearMatrix();

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           Matrix
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Construct And Distruct
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
MyMatrix<T>::MyMatrix() :
    row(0),
    column(0),
    data(nullptr)
{}

template <class T>
MyMatrix<T>::MyMatrix(size_t rows, size_t columns) :
    row(rows),
    column(columns),
    data(nullptr)
{
   createMatrix();
}

template <class T>
MyMatrix<T>::MyMatrix(MyMatrix<T>& matrix) :
    row(matrix.row),
    column(matrix.column),
    data(nullptr)
{
    createMatrix();
    copyMatrix(matrix);
}

template <class T>
MyMatrix<T>::MyMatrix(MyMatrix<T>&& matrix) :
    row(matrix.row),
    column(matrix.column),
    data(matrix.data)
{
    matrix.data = nullptr;
}

//template <class T>
//MyMatrix<T>::MyMatrix(std::initializer_list<std::initializer_list<T>> list)
//{

//    if (list.size() != 0) {
//        bool correctMatrix = true;
//        column = list.begin()->size();
//        for(const auto& subList : list) {
//            if (subList.size() != column) {
//                correctMatrix = false;
//                break;
//            }
//        }
//        if (correctMatrix) {
//            row = list.size();
//            column = 0;
//            data = nullptr;
//            column = list.begin()->size();
//            createMatrix();
//            for (size_t i = 0; i < row; ++i) {
//                auto it = list.begin();
//                auto doubleIt = it->begin();
//                for (size_t j = 0; j < column; ++j) {
//                    data[i][j] = *doubleIt++;
//                }
//                it++;
//            }
//        } else {
//            throw 1;
//            //throw "Uncorrect size";
//        }
//    } else {
//        throw "List of arguments is empty!";
//    }
//}

template <class T>
MyMatrix<T>::~MyMatrix()
{
    if (data != nullptr) {
        for (size_t i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                                                          Equale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
MyMatrix<T>& MyMatrix<T>::operator=(MyMatrix<T>& oldMat)
{
    if (this != &oldMat) {
        clearMatrix();
        row = oldMat.row;
        column = oldMat.column;
        createMatrix();
        copyMatrix(oldMat);
    }
    return *this;
}

template <class T>
MyMatrix<T>& MyMatrix<T>::operator=(MyMatrix<T>&& oldMat)
{
    delete[] this->data;
    this->data = oldMat.data;
    oldMat.data = nullptr;
    return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                                      Default operations (Mat + Mat)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
MyMatrix<T>& MyMatrix<T>::operator+=(MyMatrix<T>& oldMat)
{
    if (oldMat.row == row && oldMat.column == column) {
        for (size_t i = 0; i < oldMat.row; ++i) {
            for (size_t j = 0; j < oldMat.column; ++j) {
                data[i][j] += oldMat.data[i][j];
            }
        }
    }
    return *this;
}

template <class T>
MyMatrix<T>& MyMatrix<T>::operator-=(MyMatrix<T>& oldMat)
{
    if (oldMat.row == row && oldMat.column == column) {
        for (size_t i = 0; i < oldMat.row; ++i) {
            for (size_t j = 0; j < oldMat.column; ++j) {
                data[i][j] -= oldMat.data[i][j];
            }
        }
    }
    return *this;
}

template <class T>
MyMatrix<T>& MyMatrix<T>::operator+(MyMatrix<T>& oldMat)
{
    *this += oldMat;
    return *this;
}

template <class T>
MyMatrix<T>& MyMatrix<T>::operator-(MyMatrix<T>& oldMat)
{
    *this-= oldMat;
    return *this;
}

template <class T>
MyMatrix<T> operator*(MyMatrix<T>& newMat, MyMatrix<T>& oldMat)
{
    if (oldMat.row == newMat.row && oldMat.column == newMat.column) {
        for (size_t i = 0; i < oldMat.row; ++i) {
            for (size_t j = 0; j < oldMat.column; ++j) {
                newMat.data[i][j] *= oldMat.data[i][j];
            }
        }
    }
    return newMat;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Default operations (Mat + Num)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
MyMatrix<T> MyMatrix<T>::operator+(double num)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            data[i][j] += num;
        }
    }
    return *this;
}

template <class T>
MyMatrix<T> MyMatrix<T>::operator-(double num)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            data[i][j] -= num;
        }
    }
    return *this;
}

template <class T>
MyMatrix<T> MyMatrix<T>::operator*(double num)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            data[i][j] *= num;
        }
    }
    return *this;
}

template <class T>
MyMatrix<T> MyMatrix<T>::operator/(double num)
{
    if (num != 0) {
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                data[i][j] /= num;
            }
        }
    }
    return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Some Ways to Set or Get Element
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
void MyMatrix<T>::set_elem(size_t i, size_t j, T& elem)
{
    if (i < row && j < column) {
        data[i][j] = elem;
    }
}

template <class T>
T& MyMatrix<T>::get_elem(size_t i, size_t j)
{
    if (i < row && j < column) {
        return data[i][j];
    }
}

template <class T>
T& MyMatrix<T>::operator()(size_t i, size_t j)
{
    return data[i][j];
}

template <class T>
T* MyMatrix<T>::operator[](size_t i)
{
    return data[i];
}

template <class T>
bool MyMatrix<T>::is_square()
{
    return row == column;
}

template <class T>
size_t MyMatrix<T>::get_count_of_rows()
{
    return row;
}

template <class T>
size_t MyMatrix<T>::get_count_of_columns()
{
    return column;
}

template <class T>
T** MyMatrix<T>::get_pointer_on_data()
{
    return data;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Create Iterator
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
typename MyMatrix<T>::Iterator MyMatrix<T>::begin() //Для чего тут typename?
{
    return MyMatrix<T>::Iterator(*this, false);
}

template <class T>
typename MyMatrix<T>::Iterator MyMatrix<T>::end()
{
    return MyMatrix<T>::Iterator(*this, true);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           Iterator
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T>
MyMatrix<T>::Iterator::Iterator(MyMatrix<T>& matrix, bool end_state) :
    originalMatrix(matrix.data),
    rowNow(0),
    colNow(0),
    rowMax(matrix.row),
    colMax(matrix.column),
    end(end_state)
{}

//template <typename T>
//MyMatrix<T>::Iterator::Iterator(MyMatrix<T>::Iterator oldIt) :
//    originalMatrix(oldIt.originalMatrix),
//    rowNow(oldIt.rowNow),
//    colNow(oldIt.colNow),
//    rowMax(oldIt.rowMax),
//    colMax(oldIt.colMax),
//    end(oldIt.end)
//{}

template <typename T>
typename MyMatrix<T>::Iterator MyMatrix<T>::Iterator::next()
{
    if (!end) {
        if (colNow + 1 < colMax) {
            colNow += 1;
        } else if (rowNow + 1 < rowMax) {
            rowMax += 1;
            colNow = 0;
        } else {
            end = true;
        }
    }
    return *this;
}

template <class T>
T MyMatrix<T>::Iterator::value()
{
    if (!end) {

        auto val = originalMatrix[rowNow][colNow];
        return val;
    }
}

template <class T>
bool MyMatrix<T>::Iterator::is_end()
{
    return end;
}

template <typename T>
typename MyMatrix<T>::Iterator& MyMatrix<T>::Iterator::operator++()
{
    if (!end) {
        *this = next();
    }
    return *this;
}

template <typename T>
typename MyMatrix<T>::Iterator MyMatrix<T>::Iterator::operator++(int i)
{
    auto tmp(*this);
    if (!end) {
        *this = next();
    }
    return *tmp;
}

template <class T>
T& MyMatrix<T>::Iterator::operator*()
{
    if (!end){
        auto val = originalMatrix[rowNow][colNow];
        return val;
    }
}

template <class T>
bool MyMatrix<T>::Iterator::operator==(MyMatrix<T>::Iterator &rightIt)
{
    return (rowNow == rightIt.rowNow &&
            colNow == rightIt.colNow) ? true: false;
}

template <class T>
bool MyMatrix<T>::Iterator::operator!=(MyMatrix<T>::Iterator &rightIt)
{
    return !(*this == rightIt);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Help Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
T** MyMatrix<T>::createMatrix()
{
    T** matrix = new T*[row];
    for (size_t j = 0; j < row; ++j) {
        matrix[j] = new T[column];
    }
    data = matrix;
    return data;
}

template <class T>
void MyMatrix<T>::copyMatrix(MyMatrix<T>& oldMat)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            data[i][j] = oldMat.data[i][j];
        }
    }
}

template <class T>
void MyMatrix<T>::clearMatrix()
{
    for (size_t i = 0; i < row; ++i) {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
}


#endif // MATRIX_H
