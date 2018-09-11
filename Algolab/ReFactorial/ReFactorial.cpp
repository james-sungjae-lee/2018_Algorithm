// 20180911
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int factorial(int);

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
    std::cout << factorial(num) << '\n';
  }
}

int factorial(int num){
  if (num <= 1){
    return 1;
  }else{
    return num*factorial(num-1);
  }
}
