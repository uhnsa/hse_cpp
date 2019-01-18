#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using i32 = int32_t;

int main() {
    i32 current_day = 0;
    i32 current_hour = 0;
    i32 current_minute = 0;
    std::cin >> current_day >> current_hour >> current_minute;
    i32 current_time = current_day * 10000 +
            current_hour * 100 + current_minute;
    i32 count_alarms = 0;
    std::cin >> count_alarms;
    i32 day = 0;
    i32 hour = 0;
    i32 minute = 0;
    std::vector<i32> timetable(count_alarms);
    for (size_t i = 0; i < count_alarms; ++i) {
        std::cin >> day >> hour >> minute;
        if (day == 0) {
            timetable.push_back(current_day * 10000 + hour * 100 + minute);
            timetable.push_back((current_day + 1) * 10000 +
            hour * 100 + minute);
        } else {
            if (day < current_day) {
                timetable.push_back((day + 7) * 10000 + hour * 100 + minute);
            } else {
                timetable.push_back(day * 10000 + hour * 100 + minute);
            }
        }
    }
    i32 min_time = 1000000;
    for (auto day_time : timetable) {
        if (day_time >= current_time && day_time <= min_time) {
            min_time = day_time;
        }
    }
    i32 result_hour = min_time / 10000;
    if (result_hour > 7) {
        result_hour -= 7;
    }
    std::cout << result_hour << ' ' <<
    (min_time / 100) % 100 << ' ' <<
    min_time % 100 << '\n';

    return 0;
}
