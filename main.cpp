#include <iostream>
using namespace std;

const int M = 20, N = 20; // Максимальні розміри матриці

// Функція введення матриці
void get_matr(int matr[M][N], int &rows, int &cols) {
    // Запитуємо користувача ввести розміри матриці, перевіряючи коректність введених значень
    do {
        cout << "Введіть кількість рядків (2-20): ";
        cin >> rows;
        cout << "Введіть кількість стовпців (2-20): ";
        cin >> cols;
    } while (rows < 2 || rows > M || cols < 2 || cols > N);
    // Запитуємо елементи матриці
    cout << "Введіть елементи масиву: " << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matr[i][j];
}

// Функція виведення матриці
void show_matr(const int matr[M][N], int rows, int cols) {
    cout << "\nМатриця: " << endl;
    // Виводимо кожен елемент матриці у вигляді таблиці
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matr[i][j] << "\t";
        cout << endl;
    }
}

// Завдання 1: Пошук елемента, який є максимальним у своєму рядку і мінімальним у своєму стовпці
int find_special_element(const int matr[M][N], int rows, int cols) {
    // Перебираємо всі елементи матриці
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isMaxInRow = true, isMinInCol = true;

            // Перевіряємо, чи є поточний елемент максимальним у своєму рядку
            for (int k = 0; k < cols; k++)
                if (matr[i][k] > matr[i][j]) isMaxInRow = false;

            // Перевіряємо, чи є поточний елемент мінімальним у своєму стовпці
            for (int k = 0; k < rows; k++)
                if (matr[k][j] < matr[i][j]) isMinInCol = false;

            // Якщо обидві умови виконуються, повертаємо цей елемент
            if (isMaxInRow && isMinInCol) return matr[i][j];
        }
    }
    return 0;   // Якщо такого елемента немає, повертаємо 0
}

// Завдання 2: Дзеркальне відображення матриці відносно горизонтальної осі
void mirror_matrix(int matr[M][N], int rows, int cols) {
    // Відзеркалюємо матрицю по горизонталі (відзеркалюємо рядки)
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            swap(matr[i][j], matr[rows - i - 1][j]);
        }
    }
}

// Основна функція
int main() {
    int matr[M][N];   // Масив для збереження матриці
    int rows, cols;  // Змінні для збереження кількості рядків і стовпців
    char choice;    // Вибір користувача
    
    do {
        // Вивід меню та отримання вибору користувача
        cout << "Виберіть завдання (1 - Пошук спеціяльного елементу, 2 - Відзеркалення матриці, q - Вихід): ";
        cin >> choice;
        
        if (choice == '1') {
            get_matr(matr, rows, cols);      // Введення матриці
            show_matr(matr, rows, cols);    // Вивід матриці
            cout << "Елемент, який є максимальним у своєму рядку і мінімальним у своєму стовпці: " << find_special_element(matr, rows, cols) << endl;
        } else if (choice == '2') {
            get_matr(matr, rows, cols);       // Введення матриці
            mirror_matrix(matr, rows, cols); // Дзеркальне відображення матриці
            show_matr(matr, rows, cols);    // Вивід перетвореної матриці
        }
    } while (choice != 'q');    // Програма виконується, поки користувач не вибере вихід (q)
    
    return 0;   // Завершення програми
}
