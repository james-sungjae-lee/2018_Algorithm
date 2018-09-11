// 20180911
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int palindrome(string, int, int);

int main(int argc, char const *argv[]) {

  ifstream inStream;
  int numTestCases;
  inStream.open("input.txt");

  if (inStream.fail()) {
    std::cerr << "Input file opening failed." << '\n';
    exit(1);
  }

  inStream >> numTestCases;
  string check_string;
  for (size_t i = 0; i < numTestCases; i++) {
    inStream >> check_string;
    std::cout << palindrome(check_string, 0, check_string.length() - 1) << '\n';
  }
}

int palindrome(string str, int first, int last){
  if (last <= first) {
    return 1;
  }else if (str[first] != str[last]) {
    return 0;
  }else{
    return palindrome(str, first + 1, last - 1);
  }
}
