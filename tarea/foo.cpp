#include "foo.h"

Matriz2D::Matriz2D() : ptr(nullptr), filas(3), columnas(3) {
    ptr = new float*[3];
    for (int i = 0; i < 3; ++i) {
        ptr[i] = new float[3];
        for (int j = 0; j < 3; ++j) {
            ptr[i][j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // Inicializa la matriz con números aleatorios entre 0 y 1
        }
    }
}

Matriz2D::Matriz2D(int n) : filas(n), columnas(n) {
    ptr = new float*[n];
    for (int i = 0; i < n; ++i) {
        ptr[i] = new float[n];
        for (int j = 0; j < n; ++j) {
            ptr[i][j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // Inicializa la matriz con números aleatorios entre 0 y 1
        }
    }
}

Matriz2D::Matriz2D(int n, int m) : filas(n), columnas(m) {
    ptr = new float*[filas];
    for (int i = 0; i < filas; ++i) {
        ptr[i] = new float[columnas];
        for (int j = 0; j < columnas; ++j) {
            ptr[i][j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // Inicializa la matriz con números aleatorios entre 0 y 1
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m) : filas(m.filas), columnas(m.columnas) {
    ptr = new float*[filas];
    for (int i = 0; i < filas; ++i) {
        ptr[i] = new float[columnas];
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

Matriz2D t(Matriz2D& m) {
    Matriz2D transpuesta(m.getColumnas(), m.getFilas());
    for (int i = 0; i < m.getFilas(); ++i) {
        for (int j = 0; j < m.getColumnas(); ++j) {
            transpuesta.ptr[j][i] = m.ptr[i][j];
        }
    }
    return transpuesta;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m) {
os << fixed << setprecision(2);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            os << m.ptr[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2) {
    if (m1.filas != m2.filas || m1.columnas != m2.columnas) {
        throw std::invalid_argument("Las dimensiones de las matrices no coinciden para la suma.");
    }

    Matriz2D resultado(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m1.columnas; ++j) {
            resultado.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
        }
    }
    return resultado;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2) {
    if (m1.filas != m2.filas || m1.columnas != m2.columnas) {
        throw std::invalid_argument("Las dimensiones de las matrices no coinciden para la resta.");
    }

    Matriz2D resultado(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m1.columnas; ++j) {
            resultado.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return resultado;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2) {
    if (m1.columnas != m2.filas) {
        throw std::invalid_argument("Las dimensiones de las matrices no coinciden para la multiplicación.");
    }

    Matriz2D resultado(m1.filas, m2.columnas);
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m2.columnas; ++j) {
            for (int k = 0; k < m1.columnas; ++k) {
                resultado.ptr[i][j] += m1.ptr[i][k] * m2.ptr[k][j];
            }
        }
    }
    return resultado;
}

Matriz2D operator+(const Matriz2D& m, float n) {
    Matriz2D resultado(m.filas, m.columnas);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            resultado.ptr[i][j] = m.ptr[i][j] + n;
        }
    }
    return resultado;
}

Matriz2D operator-(const Matriz2D& m, float n) {
    return m + (-n);
}

Matriz2D operator*(const Matriz2D& m, float n) {
    Matriz2D resultado(m.filas, m.columnas);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            resultado.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return resultado;
}

Matriz2D operator/(const Matriz2D& m, float n) {
    if (n == 0) {
        throw std::invalid_argument("No se puede dividir por cero.");
    }
    return m * (1 / n);
}

float Matriz2D::get(int i, int j) {
    if (i < 0 || i >= filas || j < 0 || j >= columnas) {
        throw std::out_of_range("Índices fuera de rango.");
    }
    return ptr[i][j];
}

int Matriz2D::getFilas() {
    return filas;
}

int Matriz2D::getColumnas() {
    return columnas;
}
