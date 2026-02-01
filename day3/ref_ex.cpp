#include <iostream>

// 참조자는 불필요한 *와 &을 사용하지 않을 수 있음.
// int main() {
//     int x;
//     int& y = x;
//     int& z = y;

//     x= 1;
//     std:: cout << "x : " << x << " y :" << y << " z :" << z << std::endl;
    
//     y= 2;
//     std:: cout << "x : " << x << " y :" << y << " z :" << z << std::endl;

//     z= 3;
//     std:: cout << "x : " << x << " y :" << y << " z :" << z << std::endl;
// }

int main() {
    //int &ref = 4; //리터럴을 참조할 수 x. 임시 값으로 변수가 아니니깐 
    const int &ref = 4; // 상수 참조를 하면 가능. 어차피 상수라 ref는 무조건 4임
    int a = ref; // 상수 참조 시 리터럴도 참조가 가능
    std::cout << ref << std::endl;
    std::cout << a << std::endl;
}