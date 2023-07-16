#include <iostream>
#include <vector>

int fibonacci(int n) {
    std::vector<int> fib(n + 1);

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Число Фибоначчи = " << fibonacci(n);

    return 0;
}