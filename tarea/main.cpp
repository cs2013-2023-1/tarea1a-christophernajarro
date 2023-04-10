// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"


int main() {
    srand(static_cast<unsigned>(time(0))); //
    Matriz2D m1;
    Matriz2D m2(5);
    Matriz2D m3(5, 2);
    Matriz2D m4 = m2;
    Matriz2D m5 = move(m2);

    Matriz2D m6 = t(m3);

    cout << "m1:" << endl << m1 << endl;
    cout << "m2:" << endl << m2 << endl;
    cout << "m3:" << endl << m3 << endl;
    cout << "m4:" << endl << m4 << endl;
    cout << "m5:" << endl << m5 << endl;
    cout << "m6 (transpuesta de m3):" << endl << m6 << endl;

    Matriz2D m7 = m1 + 3;
    Matriz2D m8 = m1 - 1.2;
    Matriz2D m9 = m1 * 5;
    Matriz2D m10 = m1 / 7;

    cout << "m1 + 3:" << endl << m7 << endl;
    cout << "m1 - 1.2:" << endl << m8 << endl;
    cout << "m1 * 5:" << endl << m9 << endl;
    cout << "m1 / 7:" << endl << m10 << endl;

    Matriz2D m11(3, 3);
    Matriz2D m12(3, 3);

    Matriz2D m13 = m11 + m12;
    Matriz2D m14 = m11 - m12;
    Matriz2D m15 = m11 * m12;

    cout << "m11 + m12:" << endl << m13 << endl;
    cout << "m11 - m12:" << endl << m14 << endl;
    cout << "m11 * m12:" << endl << m15 << endl;

    return 0;
}
