#include "matrix.h"

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

/*template <class T>
MyMatrix<T>::MyMatrix(std::initializer_list<std::initializer_list<T>> list) :
    row(list.size()),
    column(0),
    data(nullptr)
{
    //Проверка поданных данных на корректность
    size_t listSize = list[0].size;
    bool goodInitList = true;
    for(const auto& subList : list) {
        if (subList.size() != listSize) {
            goodInitList = false;
            break;
        }
    }
    //Сам конструктор
    if (goodInitList) {
        column = listSize;
        createMatrix();
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                data[i][j] = list[i][j];
            }
        }
    }
}*/

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
//    Equale
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*template <class T>
MyMatrix<T>& MyMatrix<T>::operator=(MyMatrix<T>& oldMat)
{   
    return newMat(oldMat);
}*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Default operations (Mat + Mat)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
MyMatrix<T>& MyMatrix<T>::operator+=(MyMatrix<T>& matrix)
{
    *this += matrix;
    return *this;
}

template <class T>
MyMatrix<T>& MyMatrix<T>::operator-=(MyMatrix<T>& matrix)
{
    *this -= matrix;
    return *this;
}

template <class T>
MyMatrix<T> operator+(MyMatrix<T>& newMat, MyMatrix<T>& oldMat)
{
    if (oldMat.row == newMat.row && oldMat.column == newMat.column) {
        for (size_t i = 0; i < oldMat.row; ++i) {
            for (size_t j = 0; j < oldMat.column; ++j) {
                newMat.data[i][j] += oldMat.data[i][j];
            }
        }
    }
    return newMat;
}

template <class T>
MyMatrix<T> operator-(MyMatrix<T>& newMat, MyMatrix<T>& oldMat)
{
    if (oldMat.row == newMat.row && oldMat.column == newMat.column) {
        for (size_t i = 0; i < oldMat.row; ++i) {
            for (size_t j = 0; j < oldMat.column; ++j) {
                newMat.data[i][j] -= oldMat.data[i][j];
            }
        }
    }
    return newMat;
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
MyMatrix<T> operator+(MyMatrix<T>& newMat, double num)
{
    if (newMat.row == newMat.row && newMat.column == newMat.column) {
        for (size_t i = 0; i < newMat.row; ++i) {
            for (size_t j = 0; j < newMat.column; ++j) {
                newMat.data[i][j] += num;
            }
        }
    }
    return newMat;
}

template <class T>
MyMatrix<T> operator-(MyMatrix<T>& newMat, double num)
{
    if (newMat.row == newMat.row && newMat.column == newMat.column) {
        for (size_t i = 0; i < newMat.row; ++i) {
            for (size_t j = 0; j < newMat.column; ++j) {
                newMat.data[i][j] -= num;
            }
        }
    }
    return newMat;
}

template <class T>
MyMatrix<T> operator*(MyMatrix<T>& newMat, double num)
{
    if (newMat.row == newMat.row && newMat.column == newMat.column) {
        for (size_t i = 0; i < newMat.row; ++i) {
            for (size_t j = 0; j < newMat.column; ++j) {
                newMat.data[i][j] *= num;
            }
        }
    }
    return newMat;
}

template <class T>
MyMatrix<T> operator/(MyMatrix<T>& newMat, double num)
{
    if (newMat.row == newMat.row && newMat.column == newMat.column) {
        for (size_t i = 0; i < newMat.row; ++i) {
            for (size_t j = 0; j < newMat.column; ++j) {
                newMat.data[i][j] /= num;
            }
        }
    }
    return newMat;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Some Ways to Set or Get Element
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
void MyMatrix<T>::set_elem(size_t i, size_t j, T& elem)
{
    data[i][j] = elem;
}

template <class T>
T& MyMatrix<T>::get_elem(size_t i, size_t j)
{
    return data[i][j];
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Create Iterator
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
typename MyMatrix<T>::Iterator MyMatrix<T>::begin() //Для чего тут typename?
{
    //Work In Progres
    return *this;
}

template <class T>
typename MyMatrix<T>::Iterator MyMatrix<T>::end()
{
    //Work In Progress
    return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    Output Matrix
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T>
std::ostream& operator<<(std::ostream& out, MyMatrix<T>& matrix)
{
    out << "Output Matrix" << std::endl;
    for (size_t i = 0; i < matrix.row; ++i) {
        for (size_t j = 0; j < matrix.column; ++j) {
            out << "[" << matrix[i][j] << "]\t";
        }
        out << std::endl;
    }
    out << std::endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           Iterator
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T>
MyMatrix<T>::Iterator::Iterator(MyMatrix<T> matrix) :
    originalMatrix(matrix.data),
    rowNow(0),
    colNow(0),
    rowMax(matrix.row),
    colMax(matrix.column),
    end(false)
{}

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
    return originalMatrix[rowNow][colNow];
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

/*template <class T>
T& MyMatrix<T>::Iterator::operator*()
{
    return value();
}*/

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
    for (size_t j = 0; j < column; ++j) {
        matrix[j] = new T[column];
    }
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
