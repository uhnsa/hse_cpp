#include <algorithm>
#include <cstdint>
#include <cctype>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using i32 = int32_t;

std::vector<i32> GetUnsolvedProblems(
    i32 problem_count,
    const std::vector<i32>& solved_problems
) {
    std::vector<i32> all_problems(problem_count);
    std::iota(all_problems.begin(), all_problems.end(), 0);
    std::vector<i32> result;
    std::set_difference(
        all_problems.begin(),
        all_problems.end(),
        solved_problems.begin(),
        solved_problems.end(),
        std::back_inserter(result));
    return result;
}

void PrintUnsolvedProblems(
    const std::vector<i32>& unsolved_problems,
    bool check_alpha
) {
    for (const auto task : unsolved_problems) {
        if (check_alpha) {
            char problem = task + 'A';
            std::cout << ' ' << problem;
        } else {
            std::cout << ' ' << task + 1;
        }
    }
    std::cout << '\n';
}

int main() {
    i32 contest_id = 0;
    while (std::cin >> contest_id) {
        i32 problem_count = 0;
        std::cin >> problem_count;
        std::vector<i32> solved_problems;
        bool check_alpha = false;
        for (auto x = std::getchar(); x == ' '; x = std::getchar()) {
            std::string number;
            std::cin >> number;
            if (std::isalpha(number.front())) {
                check_alpha = true;
                solved_problems.push_back(number.front() - 'A');
            } else {
                solved_problems.push_back(std::stoi(number) - 1);
            }
        }
        const auto unsolved_problems = GetUnsolvedProblems(
            problem_count,
            solved_problems);
        std::cout << contest_id;
        PrintUnsolvedProblems(unsolved_problems, check_alpha);
    }
    return 0;
}
