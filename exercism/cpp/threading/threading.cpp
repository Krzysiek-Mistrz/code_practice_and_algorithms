#include "threading.h"


void BankingAccount::pay(int amount) {
    // mutex blocks other thread at the same time which also tries to do lock at this moment on this block :)
    {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
    }

    global_transaction_count++;
}

int main(int argc, char** argv) {
    BankingAccount my_account;
    std::vector<std::thread> threads;

    std::cout << "10 clients simultanously wants to pay into same account: ..." << std::endl;

    for (int i{0}; i < 10; ++i) {
        // we create thread which will do 1000 payins
        threads.emplace_back([&my_account]() { 
            for (int j{0}; j < 1000; ++j) {
                my_account.pay(1);
            }
        });
    }

    // we wait till every thread do his job = join() and joinable() = if the thread is even active :)
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    threads.clear();

    std::cout << "Koncowy stan konta: " << my_account.get_balance() << " amount :)\n";
    std::cout << "Laczna li operacji w systemie: " << global_transaction_count << std::endl;

    return EXIT_SUCCESS;
}
