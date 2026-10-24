#include <iostream>

// READY is defined twice, but C++ enum class can handle those easily

enum class StatusA {
    READY, WORK, STOPPED 
};

enum class StatusB {
    READY, RUNNING, HALTED, FAILED
};

//  C-enum!
enum StatusC {
    A, B, C, D, E, F
};

int main() {
    StatusA status = StatusA::READY;

    // can't be used directly
    // => "How may lines of error do you want to read on console?" C++: "Yes."
    // std::cout << "status has value of: " << status << std::endl;
    // std::cout << "StatusA::READY = " << StatusA::READY << std::endl;

    // you can just compare the status with the set of states
    switch(status) {
        case StatusA::READY:
            std::cout << "This status is ready to use." << std::endl;
            break;
        case StatusA::WORK:
            std::cout << "The status is buisy for now." << std::endl;
            break;
        case StatusA::STOPPED:
            std::cout << "The status is not running." << std::endl;
            break;
    }

    //  iterate through each enumeration element => Works only with C-enumerations!
    std::initializer_list<StatusC> all_states = {A, B, C};
    for(StatusC s1 : all_states) {
        std::cout << s1 << std::endl;
    }

    return 0;
}