#include <iostream>
#include <string>
#include <windows.h>   // для SetConsoleCP / SetConsoleOutputCP
using namespace std;

// i - поточна позиція, found - чи зустрілась трійка, result - рядок-результат
void process(const string& s, int i, bool& found, string& result) {
    if (i >= (int)s.size())                       // база рекурсії: рядок закінчився
        return;

    if (i + 2 < (int)s.size() &&
        s[i] == '*' && s[i + 1] == '*' && s[i + 2] == '*') {
        found = true;
        result += "!!";                           // трійка -> "!!"
        process(s, i + 3, found, result);         // пропускаємо 3 зірочки
    }
    else {
        result += s[i];                           // звичайний символ залишаємо
        process(s, i + 1, found, result);
    }
}

int main() {
    SetConsoleCP(1251);          // кодування вводу
    SetConsoleOutputCP(1251);    // кодування виводу

    string text;
    cout << "Введіть рядок: ";
    getline(cin, text);

    bool found = false;
    string result;
    process(text, 0, found, result);

    cout << "1) Група з трьох зірочок підряд "
        << (found ? "зустрічається." : "не зустрічається.") << endl;
    cout << "2) Рядок після заміни: " << result << endl;

    return 0;
}
