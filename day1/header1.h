#include <iostream>

namespace header1 {
    int foo() {
        std::cout << "header1의 foo 실행!" << std::endl;
        return 0;
    }
    // 만약 bar()도 쓰신다면 이것도 추가
    void bar() {
        std::cout << "header1의 bar 실행!" << std::endl;
    }
}