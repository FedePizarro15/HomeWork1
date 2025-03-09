#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "functions.cpp"

using namespace std;

int main() {
    int n;
    input("Ingrese un valor 'n' para para generar una matriz de n x n:", &n);

    vector<vector<int>> matrix = create_matrix(n);

    string print;

    while (true) {
        input("Imprimir Matriz? (y/n):", &print);

        if (print == "y") {
            print_matrix(matrix, n);
            break;
        } else if (print == "n") {
            break;
        }

        cout << "Ingrese 'y' si quiere imprimir la matriz, 'n' en caso contrario." << endl;
    }

    cout << endl << "Contenido de la Matriz" << endl << endl;

    print_matrix_content(matrix, n);

    return 0;
}