#include <iostream>
using namespace std;

void shiftDown(int** arr, int rows, int cols, int shifts) {
    if (shifts == 0) return;

    int* lastRow = new int[cols];
    for (int j = 0; j < cols; j++) {
        lastRow[j] = arr[rows - 1][j];
    }

    for (int i = rows - 1; i > 0; i--) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i - 1][j];
        }
    }

    for (int j = 0; j < cols; j++) {
        arr[0][j] = lastRow[j];
    }

    delete[] lastRow;
    shiftDown(arr, rows, cols, shifts - 1);
}

int main() {
    int rows = 3, cols = 4;
    int arr[3][4] = {
        {4, 5, 6, 7},
        {1, 2, 4, 1},
        {4, 3, 6, 8}
    };

    int* matrix[3];
    for (int i = 0; i < rows; i++) matrix[i] = arr[i];

    int shifts;
    cout << "кол-тво сдвигов вниз: ";
    cin >> shifts;

    shiftDown(matrix, rows, cols, shifts);

    cout << "матрица после сдвига вниз:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
