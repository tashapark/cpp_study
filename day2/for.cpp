#include <iostream>

int main() {
    int i;

    for ( i =0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    // 1부터 10까지 합 
    int m, sum  = 0;

    for (m = 1; m <=10; m++) {
        sum += m;
    }

    std::cout << "합은: " << sum << std::endl;
    
    //변수는 사용 직전에 선언해도 됌
    int s =0; 

    for(int n = 1; n<=10; n++){
        s +=n;
    }
    
    std::cout << "합은: " << sum << std::endl;
    
    return 0;


}

