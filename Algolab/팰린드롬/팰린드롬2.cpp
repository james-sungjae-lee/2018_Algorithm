// 20180905
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int palindromic_number(int checking_number);
int check_palindrom(int checking_number, int B);

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
     int checking_number;
     inStream >> checking_number;
     palindromic_number(checking_number);
   }
  inStream.close();
  return 0;
}

int palindromic_number(int checking_number){
  bool print_check = false;
  for (size_t i = 2; i <= 64; i++) {
    if (check_palindrom(checking_number, i) == 1) {
      std::cout << 1 << '\n';
      print_check = true;
      break;
    }
  }
  if (print_check == false) {
    std::cout << 0 << '\n';
  }
  return 0;
}

int check_palindrom(int checking_number, int B){
  int num_array [1000];
  int index = 0;

  while (checking_number >= B) {
    num_array[index] = checking_number % B;
    checking_number = checking_number / B;
    index ++;
  }
  num_array[index] = checking_number;

  for (size_t i = 0; i <= (index + 1)/2; i++) {
    if (num_array[i] != num_array[index - i]) {
      return 0;
    }
  }
  return 1;
}
