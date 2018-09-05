#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int sum_all(int start_num, int end_num);

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
     int start_num;
     int end_num;
     inStream >> start_num >> end_num;
     sum_all(start_num, end_num);
   }

  inStream.close();
  return 0;
}

int sum_all(int start_num, int end_num){

  int return_sum = 0;
  for (size_t i = start_num; i < end_num + 1; i++) {
    return_sum += i;
  }
  std::cout << return_sum << '\n';
  return 0;
}
