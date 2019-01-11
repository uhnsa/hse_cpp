#include <cmath>
#include <iostream>

using i32 = int32_t;

int main() {
    i32 x_1;
    i32 y_1;
    i32 x_2;
    i32 y_2;
    std::cin >> x_1 >> y_1 >> x_2 >> y_2;
    if (x_1 == x_2 || y_1 == y_2 ||
    std::abs(x_2 - x_1) == std::abs(y_2 - y_1)) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
    return 0;
}
