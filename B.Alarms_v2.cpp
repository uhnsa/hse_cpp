#include <cstdint>
#include <iostream>
#include <tuple>

using i32 = int32_t;
using tuple_i32 = std::tuple<i32, i32, i32>;

tuple_i32 ReadTime() {
    i32 day = 0;
    i32 hour = 0;
    i32 minute = 0;
    std::cin >> day >> hour >> minute;
    tuple_i32 time = {day, hour, minute};
    return time;
}

tuple_i32 GetNextSignalTime(const tuple_i32& alarm, const tuple_i32& now_time) {
    auto [alarm_day, alarm_hour, alarm_minute] = alarm;
    auto [now_day, now_hour, now_minute] = now_time;
    tuple_i32 next_time;
    if (alarm_day == 0) {
        if (tuple_i32 {now_day, alarm_hour, alarm_minute} < now_time) {
            next_time = {now_day + 1, alarm_hour, alarm_minute};
        } else {
            next_time = {now_day, alarm_hour, alarm_minute};
        }
    } else if (alarm < now_time) {
        next_time = {alarm_day + 7, alarm_hour, alarm_minute};
    } else {
        next_time = alarm;
    }
    return next_time;
}

int main() {
    tuple_i32 current_time = ReadTime();
    i32 count_alarms = 0;
    std::cin >> count_alarms;
    tuple_i32 nearest_alarm = {14, 24, 60};
    while (count_alarms) {
        tuple_i32 alarm_time = ReadTime();
        tuple_i32 next_alarm_time = GetNextSignalTime(alarm_time, current_time);
        nearest_alarm = std::min(nearest_alarm, next_alarm_time);
        count_alarms -= 1;
    }
    i32 result_day = std::get<0>(nearest_alarm);
    if (result_day > 7) {
        result_day -= 7;
    }
    std::cout << result_day << ' ' <<
        std::get<1>(nearest_alarm) << ' ' <<
            std::get<2>(nearest_alarm) << '\n';
    return 0;
}
