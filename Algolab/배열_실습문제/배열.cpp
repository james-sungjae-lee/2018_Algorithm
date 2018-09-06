// 20180906
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int check_array(const vector<int>& arr, int M);

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
     std::vector<int> arr;
     int N;
     int M;
     int temp;

     inStream >> N >> M;

     vector<int> visit_check;
     for (size_t t = 0; t < N; t++) {
       visit_check[t] = 0;
     }

     for (size_t j = 0; j < N; j++) {
       inStream >> temp;
       arr.push_back(temp);
     }
     std::cout << check_array(arr, visit_check,N , M) << '\n';
   }
  inStream.close();
  return 0;
}

int check_array(const vector<int>& arr, const vector<int>& visit, int size, int M){

  visit_check[M] = 1;
  if (arr[M] == arr[arr.size() - 1]) {
    return 1;
  }else if (M < 0 || M >= arr.size()) {

  }else{
    check_array(arr, M + arr[M]);
  }

  return 0;
}
