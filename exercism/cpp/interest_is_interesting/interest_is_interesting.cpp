#include <iostream>


double interest_rate(double balance) {
    if (balance < 0)
        return 3.213;
    else if (balance >= 0 && balance < 1000)
        return 0.5;
    else if (balance >= 1000 and balance < 5000)
        return 1.621;
    else
        return 2.475;
}

double yearly_interest(double balance) {
    return balance * interest_rate(balance) / 100.0;
}

double annual_balance_update(double balance) {
    return balance + yearly_interest(balance);
}

int years_until_desired_balance(double balance, double target_balance) {
    int counter{0};

    while (balance < target_balance) {
        balance = annual_balance_update(balance);
        ++counter;
    }

    return counter;
}