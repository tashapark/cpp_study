#include <iostream>
#include "header1.h"
#include "header2.h"

// 1. 네임스페이스 내 함수 정의
namespace header1 {
    int func() {
        foo();
        header2::foo();
        return 0; // return 추가
    }
}

// 2. 전역 범위에서의 호출 (함수 이름 중복 방지를 위해 func2로 변경)
int func2() {
    header1::foo();
    return 0; // return 추가
}

// 3. 이름 없는 네임스페이스 (이 파일 전용)
namespace {
    int OnlyInThisFile() { return 0; }
    int only_in_this_file = 0;
} 

// main 함수는 단 하나만!
int main() {
    // 예제 1: 직접 명시
    header1::foo();

    // 예제 2: using 선언
    using header1::foo;
    foo(); 

    // 예제 3: 이름 없는 네임스페이스 사용
    OnlyInThisFile();
    only_in_this_file = 3;

    std::cout << "성공적으로 실행되었습니다!" << std::endl;
    return 0;
}