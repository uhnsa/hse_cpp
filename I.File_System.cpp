#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string>  result;
    std::string directory;
    while (std::cin >> directory) {
        std::string now_directory;
        for (const auto& symbol : directory) {
            if (symbol != '/') {
                now_directory += symbol;
            } else {
                now_directory += '/';
                result.insert(now_directory);
            }
        }
    }
    for (const auto& name : result) {
        std::cout << name << '\n';
    }
    return 0;
}
