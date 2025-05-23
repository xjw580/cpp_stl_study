/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

class Defer {
private:
    std::function<void()> func;

public:
    explicit Defer(std::function<void()> func): func(std::move(func)) {
        std::cout << "constructor" << std::endl;
    }

    ~Defer() {
        std::cout << "destructor" << std::endl;
        func();
    }
};

int throw_exception(int i) noexcept(false) {
    if (i == 0) {
        throw std::runtime_error("dont zero");
    }
    return 10 / i;
}

void unique_ptr_demo() {
    try {
        Defer{
            [] {
                std::cout << "destroy" << std::endl;
            }
        };
        int res = throw_exception(0);
        std::cout << "res:" << res << std::endl;
    } catch (std::exception &e) {
        std::cout << "exception:" << e.what() << std::endl;
    }
}

struct MyException final : std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "C++ Exception";
    }
};

void main() {
    unique_ptr_demo();
    std::cout.flush();
}
