// cppreference source
#include <iostream>
#include <cstdarg>

void simple_printf(const char* fmt...) {
    va_list args;
    va_start(args, fmt);

    while(*fmt != '\0') {
        if(*fmt == 'd') {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        } else (*fmt == 'c') {
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        ++fmt;
    }
    va_end(args);
}

int main() {
    simple_printf("dcff", 3, 'a', 1.999, 42.5);
    return 0;
}