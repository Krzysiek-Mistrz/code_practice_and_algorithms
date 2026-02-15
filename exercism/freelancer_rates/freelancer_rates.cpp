#include <cmath>


double daily_rate(double hourly_rate) {
    return hourly_rate * 8.0;
}

double apply_discount(double before_discount, double discount) {
    return before_discount - (discount / 100.0) * before_discount;
}

int monthly_rate(double hourly_rate, double discount) {
    double daily = daily_rate(hourly_rate);
    double discounted_daily = daily - (discount / 100.0) * daily;
    return (int)std::ceil(22 * discounted_daily);
}

int days_in_budget(int budget, double hourly_rate, double discount) {
    int daily = daily_rate(hourly_rate);
    int discounted_daily = daily - (discount / 100.0) * daily;
    int days = budget / discounted_daily;
    return days;
}
