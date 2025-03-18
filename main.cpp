#include <iostream>
#include <string>

using namespace std;

// Функция для вычисления остатка от деления числа в троичной системе на 11
int getRemainder(string number) {
    int remainder = 0;
    for (char digit : number) {
        remainder = (remainder * 3 + (digit - '0')) % 11;
    }
    return remainder;
}

bool isNotMultipleOf11(string number) {
    // Получаем остаток от деления на 11
    int remainder = getRemainder(number);
    // Если остаток не равен 0, значит число не кратно 11
    return remainder != 0;
}

int main() {
    string number;
    cout << "Введите троичное число: ";
    cin >> number;

    // Проверка, является ли число не кратным 11
    if (isNotMultipleOf11(number)) {
        cout << "Число не кратно 11." << endl;
    } else {
        cout << "Число кратно 11." << endl;
    }

    return 0;
}
