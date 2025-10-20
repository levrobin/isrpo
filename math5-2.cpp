#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Значения узлов и значений функции
    double x[] = { 0.27, 0.93, 1.46, 2.11, 2.87 };
    double f[] = { 2.60, 2.43, 2.06, 0.25, -2.60 };
    int n = 5; // Количество узлов

    // Вычисляем разностные коэффициенты
    double dividedDifferences[5][5] = { 0 }; // Таблица разностных коэффициентов

    // Заполняем первый столбец значениями функции
    for (int i = 0; i < n; i++) {
        dividedDifferences[i][0] = f[i];
    }

    // Вычисляем разностные коэффициенты
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dividedDifferences[i][j] = (dividedDifferences[i + 1][j - 1] - dividedDifferences[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Выводим многочлен Ньютона
    cout << "I Интерполяционная формула Ньютона: P(x) = ";
    bool firstTerm = true;

    for (int i = 0; i < n; i++) {
        if (dividedDifferences[0][i] != 0) {
            if (!firstTerm) {
                cout << (dividedDifferences[0][i] > 0 ? " + " : " - ");
            }
            else {
                firstTerm = false;
                if (dividedDifferences[0][i] < 0) {
                    cout << "-";
                }
            }
            cout << fixed << setprecision(2) << abs(dividedDifferences[0][i]);

            // Добавляем множитель (x - x[j]) для каждого члена
            for (int j = 0; j < i; j++) {
                cout << " * (x - " << x[j] << ")";
            }
        }
    }
    cout << endl;

    // Упрощенная формула
    cout << "Упрощенная формула P(x) = ";
    cout << "0.51 * x^4 - 3.18 * x^3 + 5.51 * x^2 - 3.66 * x + 3.25" << endl;

    // Вводим три значения x для экстраполяции
    double inputX[3];
    cout << "Введите три значения x для вычисления P(x): " << endl;
    for (int i = 0; i < 3; i++) {
        cin >> inputX[i];
    }

    // Заголовок таблицы
    cout << setw(10) << "x" << setw(15) << "P(x)" << endl;
    cout << "-------------------------" << endl;

    // Вычисляем и выводим результаты в виде таблицы
    for (int k = 0; k < 3; k++) {
        double result = dividedDifferences[0][0];
        double termProduct = 1.0;

        for (int i = 1; i < n; i++) {
            termProduct *= (inputX[k] - x[i - 1]);
            result += dividedDifferences[0][i] * termProduct;
        }

        // Выводим результат в таблице
        cout << setw(10) << inputX[k] << setw(15) << fixed << setprecision(3) << result << endl;
    }

    return 0;
}