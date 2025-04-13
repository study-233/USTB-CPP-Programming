#include<iostream>
#include"stdlib.h"
using namespace std;

const int length = 41;

class HugeInteger {
private:
    char number[length];
    int size;

    int my_strlen(const char* str) {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    void my_strcpy(char* dest, const char* src) {
        int i = 0;
        while ((dest[i] = src[i]) != '\0') {
            i++;
        }
    }

    void my_reverse(char* str, int len) {
        int start = 0;
        int end = len - 1;
        while (start < end) {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }

public:
    HugeInteger() {
        for (int i = 0; i < length; i++) {
            number[i] = '0';
        }
        number[40] = '\0';
        size = 0;
    }

    HugeInteger(char* num) {
        size = my_strlen(num);
        my_strcpy(number, num);
        my_reverse(number, size);
    }

    void input(char* num) {
        size = my_strlen(num);
        my_strcpy(number, num);
        my_reverse(number, size);
    }

    HugeInteger add(HugeInteger& hi) {
        int carry = 0;
        HugeInteger result;
        result.size = max(this->size, hi.size);

        for (int i = 0; i < result.size; i++) {
            if (i < this->size)
                carry += this->number[i] - '0';
            if (i < hi.size)
                carry += hi.number[i] - '0';

            result.number[i] = carry % 10 + '0';
            carry = carry / 10;
        }

        if (carry > 0) {
            if (result.size >= length - 1) {
                cout << "outrange";
                exit(0);
            } else {
                result.number[result.size++] = carry + '0';
            }
        }

        return result;
    }

    void output() {
        my_reverse(this->number, this->size);
        for (int i = 0; i < this->size; i++) {
            if (this->number[i] != '\0') {
                cout << (this->number[i]);
            }
        }
    }
};

int main() {
    HugeInteger hi1;
    char* c = new char[length];
    cin >> c;
    char* d = new char[length];
    cin >> d;
    hi1.input(c);
    HugeInteger hi2(d);
    (hi1.add(hi2)).output();

    return 0;
}