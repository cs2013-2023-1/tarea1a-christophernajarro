#include <cstdlib>
#include <ctime>
#include "foo.h"

Matriz2D::Matriz2D() : filas(3), columnas(3) {
    allocateMemory(filas, columnas);
    initializeMatrix();
}

Matriz2D::Matriz2D(int n) : filas(n), columnas(n) {
    allocateMemory(filas, columnas);
    initializeMatrix();
}

Matriz2D::Matriz2D(int n, int m) : filas(n), columnas(m) {
    allocateMemory(filas, columnas);
    initializeMatrix();
}

Matriz2D::Matriz2D(const Matriz2D& m) : filas(m.filas), columnas(m.columnas) {
    allocateMemory(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            ptr[i][j] = m.ptr[i][j];
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m) : ptr(m.ptr), filas(m.filas), columnas(m.columnas) {
    m.ptr = nullptr;
    m.filas = 0;
    m.columnas = 0;
}

Matriz2D::~Matriz2D() {
    if (ptr) {
        for (int i = 0; i < filas; ++i) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }
}

void Matriz2D::allocateMemory(int n, int m) {
    ptr = new float*[n];
    for (int i = 0; i < n; ++i) {
        ptr[i] = new float[m];
    }
}

void Matriz2D::initializeMatrix() {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            ptr[i][j] = randFloat();
        }
    }
}

{
Matriz2D transposed(m.columnas, m.filas);
for (int i = 0; i < m.columnas; ++i) {
for (int j = 0; j < m.filas; ++j) {
transposed.ptr[i][j] = m.ptr[j][i];
}
}
return transposed;
}

ostream& operator<<(ostream& os, const Matriz2D& m) {
    os << fixed << setprecision(2);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            os << m.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2) {
    if (m1.filas != m2.filas || m1.columnas != m2.columnas) {
        throw "Las matrices no tienen las mismas dimensiones";
    }
    Matriz2D result(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m1.columnas; ++j) {
            result.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
        }
    }
    return result;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2) {
    if (m1.filas != m2.filas || m1.columnas != m2.columnas) {
        throw "Las matrices no tienen las mismas dimensiones";
    }
    Matriz2D result(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m1.columnas; ++j) {
            result.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return result;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2) {
    if (m1.columnas != m2.filas) {
        throw "Las matrices no tienen las dimensiones compatibles para multiplicarse";
    }
    Matriz2D result(m1.filas, m2.columnas);
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m2.columnas; ++j) {
            float sum = 0;
            for (int k = 0; k < m1.columnas; ++k) {
                sum += m1.ptr[i][k] * m2.ptr[k][j];
            }
            result.ptr[i][j] = sum;
        }
    }
    return result;
}

Matriz2D operator+(const Matriz2D& m, float n) {
    Matriz2D result(m.filas, m.columnas);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            result.ptr[i][j] = m.ptr[i][j] + n;
        }
    }
    return result;
}

{
Matriz2D result(m.filas, m.columnas);
for (int i = 0; i < m.filas; ++i) {
for (int j = 0; j < m.columnas; ++j) {
result.ptr[i][j] = m.ptr[i][j] - n;
}
}
return result;
}

Matriz2D operator*(const Matriz2D& m, float n) {
    Matriz2D result(m.filas, m.columnas);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            result.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return result;
}

Matriz2D operator/(const Matriz2D& m, float n) {
    if (n == 0) {
        throw "División por cero";
    }
    Matriz2D result(m.filas, m.columnas);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            result.ptr[i][j] = m.ptr[i][j] / n;
        }
    }
    return result;
}

float Matriz2D::get(int i, int j) const {
    return ptr[i][j];
}

int Matriz2D::getFilas() const {    
    return filas;
}

int Matriz2D::getColumnas() const {
    return columnas;
}

float Matriz2D::randFloat() {
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}
