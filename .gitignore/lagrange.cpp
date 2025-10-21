#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Значения узлов и значений функции
    double x[] = { 0.27, 0.93, 1.46, 2.11, 2.87 };
    double f[] = { 2.60, 2.43, 2.06, 0.25, -2.60 };
    int n = 5; // Количество узлов

    // Коэффициенты многочлена Лагранжа L(x)
    double coefficients[5] = { 0 };  // Начальные значения коэффициентов для x^0, x^1, ..., x^4

    // Вычисляем каждый L_i(x) и добавляем вклад f(x_i) * L_i(x) к общему многочлену
    for (int i = 0; i < n; i++) {
        double term[5] = { 1, 0, 0, 0, 0 };  // Коэффициенты для L_i(x)
        double denom = 1; // Знаменатель для L_i(x)

        // Формируем базисный полином L_i(x)
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // Множим каждый член базисного полинома на (x - x[j])
                for (int k = 4; k > 0; k--) {
                    term[k] = term[k] * (-x[j]) + term[k - 1];
                }
                term[0] *= (-x[j]);
                denom *= (x[i] - x[j]);
            }
        }

        // Делим на знаменатель и добавляем f(x_i) * L_i(x) к итоговому полиному
        for (int k = 0; k < 5; k++) {
            coefficients[k] += f[i] * term[k] / denom;
        }
    }

    // Выводим многочлен L(x)
    cout << "L(x) = ";
    bool firstTerm = true;
    for (int i = 4; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (!firstTerm) {
                cout << (coefficients[i] > 0 ? " + " : " - ");
            }
            else {
                firstTerm = false;
                if (coefficients[i] < 0) {
                    cout << "-";
                }
            }
            cout << fixed << setprecision(2) << abs(coefficients[i]);
            if (i > 0) {
                cout << " * x";
                if (i > 1) {
                    cout << "^" << i;
                }
            }
        }
    }
    cout << endl;

    // Вводим значение x для вычисления L(x)
    double inputX;
    cout << "Введите значение x для вычисления L(x): ";
    cin >> inputX;

    // Вычисляем значение многочлена L(x) в точке inputX
    double result = 0;
    for (int i = 4; i >= 0; i--) {
        result = result * inputX + coefficients[i];
    }

    // Выводим результат
    cout << "L(" << inputX << ") = " << fixed << setprecision(2) << result << endl;

    return 0;
}