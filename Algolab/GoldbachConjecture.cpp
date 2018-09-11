// 20180911
// Sungjae Lee

// 문제 해석
// 골드바흐의 추측
// 2보다 큰 짝수는 모두 두 소수의 합으로 표현 가능하다.
// 4 <= n <= 1000 인 n 이 주어질 때,
// 골드바흐의 추측을 만족하는 두 소수를 출력하시오

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int goldbach(int, int[]);
int check_prime(int);
int primes[1000];
int check_goldbach[1000];

int main(int argc, char const *argv[]) {

  ifstream inStream;
  int numTestCases;
  inStream.open("input.txt");

  if (inStream.fail()) {
    std::cerr << "Input file opening failed." << '\n';
    exit(1);
  }

  for (size_t i = 2; i < 1000; i++) {
    if (check_prime(i)) {
      primes[i] = i;
    }else{
      primes[i] = 0;
    }
  }

  inStream >> numTestCases;
  int num;
  for (size_t i = 0; i < numTestCases; i++) {
    inStream >> num;
    goldbach(num, primes);
  }
}

int goldbach(int n, int primes[]){
  for (size_t i = n/2; i < 1000; i++) {
    if (primes[i] != 0) {
      if (check_prime(n - primes[i])) {
        if (primes[i] <= n - primes[i]) {
          std::cout << primes[i] << " " << n - primes[i] << '\n';
        }else{
          std::cout << n - primes[i] << " " << primes[i] << '\n';
        }
        break;
      }
    }
  }
  return 0;
}

int check_prime(int n){
  if (n < 2) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  int x = int(sqrt(n)) + 1;
  for (size_t i = 3; i < x; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
