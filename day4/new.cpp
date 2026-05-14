#include <iostream>

int main() {
    int* p = new int; // heap 에 메모리 할당하는 것 
    *p = 10;

    std::cout << *p << std::endl;

    delete p; // new로 할당할 때만 사용 가능, heap은 동적할당인 대신 반드시 사용후 비워줘야 메모리 누수가 안생김 
    return 0;
}