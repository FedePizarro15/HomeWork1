#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void input(string message, int* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void input(string message, string* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

vector<vector<int>> create_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n*n; i++) {
        matrix[i / n][i % n] = i + 1;
    };
    
    return matrix;
};

void print_matrix(vector<vector<int>> matrix, int n) {
    for (int i = 0; i < n*n; i++) {
        int value = matrix[i / n][i % n];

        cout << setw(4) << value;
        if (i % n == n - 1) {
            cout << endl;
        };
    };
};

void print_matrix_content(vector<vector<int>> matrix, int n) {
    int row, column;
    
    for (int i = n*n - 1; i >= 0; i--) {
        row = i / n;
        column = i % n;

        cout << "M" << (n == 0 ? "\u2080" : n == 1 ? "\u2081" : n == 2 ? "\u2082" : 
                        n == 3 ? "\u2083" : n == 4 ? "\u2084" : n == 5 ? "\u2085" : 
                        n == 6 ? "\u2086" : n == 7 ? "\u2087" : n == 8 ? "\u2088" : "_" + to_string(n)) 
             << "[" << row << "]" << "[" << column << "] = " << matrix[row][column] << endl;
    };
};

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
        };

        cout << "Ingrese 'y' si quiere imprimir la matriz, 'n' en caso contrario." << endl;
    };

    cout << endl << "Contenido de la Matriz" << endl << endl;

    print_matrix_content(matrix, n);

    return 0;
};