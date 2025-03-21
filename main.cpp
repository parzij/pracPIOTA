/*************************************************************
 * ДЗ-1 Проектирование и реализация конечного распознавателя
 * Вариант 1.20
 *
 * Студент: Батычков Вячеслав Геннадьевич, Группа: КТбо1-7
 *
 * Программа считывает цепочки из символов {0,1,2},
 * пошагово пропускает их через ДКА с 11 состояниями q0..q10,
 * выводит каждую итерацию, в конце выдает Yes (не кратно 11)
 * или No (кратно 11). При неправильном вводе запрашивает
 * повторный ввод.
 *************************************************************/

#include <iostream>
#include <string>
#include <limits>
 
#define length 3
#define width 11
 
using namespace std;
 
// Функция инициализирует таблицу переходов автомата
// Ввод: таблица переходов
// Вывод: delta[r][d] - номер нового состояния при состоянии r и входном символе d (0..2)
void initDelta(int delta[width][length]);
 
// Функция проверяет, что все символы входной строки принадлежат {0,1,2}
// Ввод: входная строка
// Вывод: true/false.
bool checkInput(const string &input);
 
// Функция реализует один шаг: по текущему состоянию и символу
// Ввод: текущему состоянию и символу
// Вывод: возвращает новое состояние
int processSymbol(int curState, char symbol, const int delta[width][length]);
 
int main() {
    int delta[width][length];
    initDelta(delta);
 
    bool exitFlag = false;
    while (!exitFlag) {
        cout << "Enter input word using ('0','1','2')\n" << "or an empty string to exit: ";
        string input;
        getline(cin, input);
 
        if (input.empty()) {
            cout << "Exiting the program." << endl;
            exitFlag = true;
        } else {
            bool valid = checkInput(input);
            if (!valid) {
                cout << "Error: invalid character.\n" << "Retry input? (Y/N): ";
                char ans; cin >> ans;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (ans != 'Y' && ans != 'y') {
                    cout << "Exiting." << endl;
                    exitFlag = true;
                }
            } else {
                int curState = 0;
                for (char c : input)
                    curState = processSymbol(curState, c, delta);

                (curState == 0) ? cout << "- No\n" : cout << "- Yes\n";
 
                cout << "Retry input? (Y/N): ";
                char rep; cin >> rep;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (rep != 'Y' && rep != 'y') {
                    cout << "Terminating." << endl;
                    exitFlag = true;
                }
            }
        }
    }
    return 0;
}

void initDelta(int delta[width][length]) {
    delta[0][0] = 0;  delta[0][1] = 1;   delta[0][2] = 2;
    delta[1][0] = 3;  delta[1][1] = 4;   delta[1][2] = 5;
    delta[2][0] = 6;  delta[2][1] = 7;   delta[2][2] = 8;
    delta[3][0] = 9;  delta[3][1] = 10;  delta[3][2] = 0;
    delta[4][0] = 1;  delta[4][1] = 2;   delta[4][2] = 3;
    delta[5][0] = 4;  delta[5][1] = 5;   delta[5][2] = 6;
    delta[6][0] = 7;  delta[6][1] = 8;   delta[6][2] = 9;
    delta[7][0] = 10; delta[7][1] = 0;   delta[7][2] = 1;
    delta[8][0] = 2;  delta[8][1] = 3;   delta[8][2] = 4;
    delta[9][0] = 5;  delta[9][1] = 6;   delta[9][2] = 7;
    delta[10][0] = 8; delta[10][1] = 9;  delta[10][2] = 10;
}

bool checkInput(const string &input) {
    bool flag = true;
    for (char c : input) {
        if (c != '0' && c != '1' && c != '2')
            flag = false;
    }
    return flag;
}

int processSymbol(int curState, char symbol, const int delta[width][length]) {
    int d = symbol - '0';
    int newState = delta[curState][d];
    cout << symbol << ": q" << curState << " -> q" << newState << endl;
    return newState;
}