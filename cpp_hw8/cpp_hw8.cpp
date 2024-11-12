#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    size_t length;

public:
    String(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    ~String() {
        delete[] str;
    }

    char& operator[](size_t index) {
        if (index >= length) {
            throw out_of_range("Индекс вне границ строки");
        }
        return str[index];
    }

    int operator()(char ch) const {
        for (size_t i = 0; i < length; ++i) {
            if (str[i] == ch) {
                return i;
            }
        }
        return -1; 
    }

    operator int() const {
        return static_cast<int>(length);
    }

    void print() const {
        cout << str << endl;
    }
};

int main() {
    String myStr("Hello, World!");

    cout << "Третий символ строки: " << myStr[2] << endl;

    char searchChar = 'o';
    int index = myStr(searchChar);
    if (index != -1) {
        cout << "Символ '" << searchChar << "' найден на позиции: " << index << endl;
    }
    else {
        cout << "Символ '" << searchChar << "' не найден" << endl;
    }

    int length = myStr;
    cout << "Длина строки: " << length << endl;

    return 0;
}
