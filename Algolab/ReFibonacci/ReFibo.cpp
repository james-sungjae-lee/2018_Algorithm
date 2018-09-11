// 20180911
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int fib(int n);

int main(int argc, char const *argv[]) {

  ifstream inStream;
  int numTestCases;
  inStream.open("input.txt");

  if (inStream.fail()) {
    std::cerr << "Input file opening failed." << '\n';
    exit(1);
  }

  inStream >> numTestCases;
  int num;
  for (size_t i = 0; i < numTestCases; i++) {
    inStream >> num;
    std::cout << fib(num) << '\n';
  }
}

int fib(int n){
  if (n <= 1) {
    return n;
  }else{
    return fib(n-1) + fib(n-2);
  }
}
