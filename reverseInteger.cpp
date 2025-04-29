#include <iostream>
#include <climits>

int reverse(int x) {
    int result = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for overflow before adding the digit
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;

        result = result * 10 + digit;
    }

    return result;
}

int main() {
    int x;
    std::cout << "Enter a 32-bit signed integer: ";
    std::cin >> x;

    int reversed = reverse(x);
    std::cout << "Reversed integer: " << reversed << std::endl;

    return 0;
}
