#include <iostream>

//  참조자는 주소니깐, 바꿀 수 없음. 
// 원본 보장용.. 포인터는 공간이자 변수이고, 찹조자는 값임
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

// 상수에 대한 참조자 
// 리터럴: 소스코드에 고정된 값 그 자체 
// 숫자에 주소값을 붙일 이유가 없으니깐 안 쓰는 건데 const 로 값을 고정하겠다고 선언하면 가능 
// int main() {
//     //int &ref = 4; //리터럴을 참조할 수 x. 임시 값으로 변수가 아니니깐 
//     const int &ref = 4; // 상수 참조를 하면 가능. 어차피 상수라 ref는 무조건 4임
//     int a = ref; // 상수 참조 시 리터럴도 참조가 가능
//     std::cout << ref << std::endl;
//     std::cout << a << std::endl;
// }


// 1번: 일반 참조자 사용 (상수 리터럴 못 받음)
// void printNumber(int &n) { 
//     std::cout << n; 
// } // number는 넣을 수 있는데 10을 넣으면 에러 남 

// // 2번: const 참조자 사용 (변수도 받고, 숫자 리터럴도 받음)
// void printConstNumber(const int &n) { 
//     std::cout << n; 
// } // number나 숫자 전부 넣을 수 있음. 

// // 코드 가독성도 올라감. 4 넣는 것보단 const int &LIMIT =4; 로 쓰면 직관적 


// 레퍼런스의 배열과 배열의 레퍼런스
//정의와 함께 초기화가 필요 

//int a, b;
// int& arr[2] = {a, b}; // 에러 남. 안됌
// 레퍼런스는 주소값이지만, 메모리상 공간을 일반적으로 차지하지 않기 때문에

// int main() {
//     int arr[3] = {1,2,3};
//     int(&ref)[3] = arr; // 배열에 참조를 붙임. 해당 값을 수정하면 arr 수정이랑 동잃
    
//     // 배열의 첫번째 칸을 가리키는 포인터와 달리, 배열 덩어리 전체 의미 
//     // so, 원본 배열의 크기와 똑같아야 함.  

//     ref[0]=2;
//     ref[1]=3;
//     ref[2]=1;

//     std::cout << arr[0] << arr[1] << arr[2] << std::endl;
//     return 0;
// }

//레퍼런스를 리턴하는 함수 
// int function() {
//     int a = 2;
//     return a; // return을 만나면 스택(메모리)에서 사라짐
// }

// int main() {
//     int b = function(); // 다만, 값을 복사했기에 유지. if, 주소를 복사했으면, 사라질 것을 복사한 셈.
//     return 0;
// }

//지역변수의 레퍼런스를 리턴하는 함수 
// Dangling Reference 댕글링 레퍼런스; 참조해야 할 변수가 사라져서 혼자 덩그러니 남아있는 상황과 유사 
// int& function1() {
//     int a = 2;
//     return a; // return을 만나면 스택(메모리)에서 사라짐
// }

// int main() {
//     int b = function1(); // if, 주소를 복사했으면, 사라질 것을 복사해서 에러 
//     b= 3;
//     return 0;
// }

//외부변수의 레퍼런스를 리턴하는 함수 
//결국 전체를 복사할 것이냐, 원하는 것만 복사할 것이냐로 결정됨 => 속도에 매우 중요
// int& function(int& a) {
//     a = 5; // 이건 값을 선언해서 공간을 할당하는 게 아니라 대입해서 값을 바꾸는 것
//     return a; // 외부의 b 값이 대치 되는 것이기 때문에 사라지지 x
// }

// int main() {
//     int b = 2;
//     int c = function(b); // c = 5가 되고 b의 값을 복사한 셈 
//     return 0;
// }

// // 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기 
// int function() {
//     int a = 5;
//     return a;
// }

// int main() {
//     int& c = function(); //레퍼런스가 함수의 리턴값 참조 불가 => 댕글링 레퍼런스로 사라져버림
//     return 0;
// }

// 근데 const 참조자...는 또 가능..
int function() {
    int a = 5;
    return a;
}

int main() {
    const int& c = function(); //상수 레퍼런스로 하면 또 가능함.. => 생명 연장.. main 끝나기 전까지는 된다네?
    std::cout << "c: " << c << std::endl;
    return 0;
}