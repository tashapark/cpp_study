#include <iostream>

// int change_val(int *p) {
//     *p =3;

//     return 0;
// }
// int main() {
//     int number = 5;
    
//     std::cout << number << std::endl;
//     change_val(&number); // 포인터로 number 의 값을 변경
//     std::cout << number << std::endl;
// }

// int main() {
//     int a = 3;
//     int& another_a = a; // 참조자 선언.. ? a의 또 다른 이름이 됨
//     // 한 번 참조되면 다른 것으로 참조 x
//     // 포인터와 달리 공간을 차지 하지 않음..?

//     another_a = 5;
//     std::cout << "a : " << a << std::endl;
//     std::cout << "another_a : " << another_a << std::endl;

//     return 0; 
// }

int change_val(int &p) {
    p= 3;
    // 어려운데.. &p =number =3 이거래.... 
    return 0;
}
int main() {
    int number = 5;

    std::cout << number << std::endl;
    change_val(number);
    std::cout << number << std::endl;
}