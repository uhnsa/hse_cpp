#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> result;
    std::string directory;
    while (std::cin >> directory) {
        std::string now_directory;
        now_directory.reserve(directory.size());
        for (const auto& symbol : directory) {
            now_directory += symbol;
            if (symbol == '/') {
                result.insert(now_directory);
            }
        }
    }
    for (const auto& name : result) {
        std::cout << name << '\n';
    }
    return 0;
}
