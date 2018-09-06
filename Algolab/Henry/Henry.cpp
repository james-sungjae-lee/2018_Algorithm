// 20180906
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int henry(int a, int b);

int main(int argc, char const *argv[]) {

  ifstream inStream;
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     int a;
     int b;
     inStream >> a >> b;
     henry(a, b);
   }
  inStream.close();
  return 0;
}

int henry(int a, int b){
  int temp = b;

  while (a != 0) {
    temp = (b - 1)/a + 1;
    a *= temp;
    a -= b;
    b *= temp;
  }
  std::cout << temp << '\n';
  return 0;
}
