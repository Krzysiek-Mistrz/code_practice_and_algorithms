#include "casts_exceptions.h"


namespace devices {
    void check_and_print(Device* u) {
        Printer* p = dynamic_cast<Printer*>(u);

        if (p) {
            p->print();
        } else {
            throw DeviceError();
        }
    }

    int main(int argc, char** argv) {
        Printer p;
        Device* d = new Scanner();

        try {
            check_and_print(d);
        } catch (const DeviceError& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        return EXIT_SUCCESS;
    }
}