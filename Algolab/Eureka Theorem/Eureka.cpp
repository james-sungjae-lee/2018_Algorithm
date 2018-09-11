// 20180911
// Sungjae Lee

// 문제 해석
// 삼각수는 그림과 같은 것
// 가우스는 모든 양의 정수가, 3개 이하의 삼각수로 표현 가능하다는 것을 증명
// 우리는 한 숫자가 정확히 3개의 삼각수로 표현 가능한지 알고싶다.
// 5와 10은 가능하지만, 4나 6은 불가능하다.
// 3 ~ 1000 의 양의 정수 K 에 대해 이를 판별하여라.

// 방법 1 : 모든 세 삼각수의 합의 경우들을 구하여 저장. 확인한다.

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int eureka(int, int[]);
int numbers[45];
int triangle_check[1001];

int main(int argc, char const *argv[]) {

  ifstream inStream;
  int numTestCases;
  inStream.open("input.txt");

  if (inStream.fail()) {
    std::cerr << "Input file opening failed." << '\n';
    exit(1);
  }

  for (size_t i = 1; i < 45; i++) {
    numbers[i] = i*(i+1) / 2;
  }
  for (size_t i = 1; i < 45; i++) {
    for (size_t j = i; j < 45; j++) {
      for (size_t k = j; k < 45; k++) {
        if(numbers[i] + numbers[j] + numbers[k] < 1001){
          triangle_check[numbers[i] + numbers[j] + numbers[k]] = 1;
        }
      }
    }
  }

  inStream >> numTestCases;
  int num;
  for (size_t i = 0; i < numTestCases; i++) {
    inStream >> num;
    eureka(num, triangle_check);
  }
}

int eureka(int num, int triangle_check[]){
  std::cout << triangle_check[num] << '\n';
  return 0;
}








//
