// Data Race: Sytuacja, gdy dwa watki probuja jednoczesnie zapisac cos w tym samym miejscu w pamieci. Wynik? Totalny chaos.
// Mutex: Skrot od Mutual Exclusion. To "klucz", ktory moze miec tylko jeden watek na raz.
// lock_guard / unique_lock: "Straznicy", ktorzy pilnuja, zebys nie zapomnial oddac klucza (Mutexa), gdy wyjdziesz z funkcji.

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cstdlib>
#include <atomic>


// atomic gwarantuje (poprzez procesor), ze operacja bedzie niepodzielna, wykorzystywany tylko do prostych operacji do bardziej zaawansowanych wyk mutexy
std::atomic<int> global_transaction_count{0};

class BankingAccount {
private:
    int balance{};
    std::mutex mtx;

public:
    void pay(int amount);

    inline int get_balance() const { return balance; }
};