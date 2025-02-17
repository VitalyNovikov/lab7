#include <iostream>
using namespace std;

const int M = 20, N = 20; // Максимальні розміри матриці

// Функція введення матриці
void get_matr(int matr[M][N], int &rows, int &cols) {
    do {
        cout << "Введіть кількість рядків (2-20): ";
        cin >> rows;
        cout << "Введіть кількість стовпців (2-20): ";
        cin >> cols;
    } while (rows < 2 || rows > M || cols < 2 || cols > N);
    
    cout << "Введіть елементи масиву: " << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matr[i][j];
}

// Функція виведення матриці
void show_matr(const int matr[M][N], int rows, int cols) {
    cout << "\nМатриця: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matr[i][j] << "\t";
        cout << endl;
    }
}

// Завдання 1: Пошук елемента, який є максимальним у своєму рядку і мінімальним у своєму стовпці
int find_special_element(const int matr[M][N], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isMaxInRow = true, isMinInCol = true;
            for (int k = 0; k < cols; k++)
                if (matr[i][k] > matr[i][j]) isMaxInRow = false;
            for (int k = 0; k < rows; k++)
                if (matr[k][j] < matr[i][j]) isMinInCol = false;
            
            if (isMaxInRow && isMinInCol) return matr[i][j];
        }
    }
    return 0;
}

// Завдання 2: Дзеркальне відображення матриці відносно горизонтальної осі
void mirror_matrix(int matr[M][N], int rows, int cols) {
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            swap(matr[i][j], matr[rows - i - 1][j]);
        }
    }
}

// Основна функція
int main() {
    int matr[M][N];
    int rows, cols;
    char choice;
    
    do {
        cout << "Виберіть завдання (1 - Пошук спеціяльного елементу, 2 - Відзеркалення матриці, q - Вихід): ";
        cin >> choice;
        
        if (choice == '1') {
            get_matr(matr, rows, cols);
            show_matr(matr, rows, cols);
            cout << "Елемент, який є максимальним у своєму рядку і мінімальним у своєму стовпці: " << find_special_element(matr, rows, cols) << endl;
        } else if (choice == '2') {
            get_matr(matr, rows, cols);
            mirror_matrix(matr, rows, cols);
            show_matr(matr, rows, cols);
        }
    } while (choice != 'q');
    
    return 0;
}
