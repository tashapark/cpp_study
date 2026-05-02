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
void printNumber(int &n) { 
    std::cout << n; 
} // number는 넣을 수 있는데 10을 넣으면 에러 남 

// 2번: const 참조자 사용 (변수도 받고, 숫자 리터럴도 받음)
void printConstNumber(const int &n) { 
    std::cout << n; 
} // number나 숫자 전부 넣을 수 있음. 

// 코드 가독성도 올라감. 4 넣는 것보단 const int &LIMIT =4; 로 쓰면 직관적 


// 레퍼런스의 배열과 배열의 레퍼런스
//정의와 함께 초기화가 필요 

//int a, b;
// int& arr[2] = {a, b}; // 에러 남. 안됌
// 레퍼런스는 주소값이지만, 메모리상 공간을 일반적으로 차지하지 않기 때문에

int main() {
    int arr[3] = {1,2,3};
    int(&ref)[3] = arr; // 배열에 참조를 붙임. 해당 값을 수정하면 arr 수정이랑 동잃
    
    // 배열의 첫번째 칸을 가리키는 포인터와 달리, 배열 덩어리 전체 의미 
    // so, 원본 배열의 크기와 똑같아야 함.  

    ref[0]=2;
    ref[1]=3;
    ref[2]=1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}