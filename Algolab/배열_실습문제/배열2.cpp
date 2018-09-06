// 20180906
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int check_array(const vector<int>& arr, vector<int>&check, int N, int M, int &mycheck);

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

    int mycheck = 0;

    inStream >> N >> M;

    std::vector<int> check;
    for (size_t j = 0; j < N; j++) {
      check.push_back(0);
    }
    for (size_t j = 0; j < N; j++) {
      check[j] = 0;
    }
    for (size_t j = 0; j < N; j++) {
      inStream >> temp;
      arr.push_back(temp);
    }
    check_array(arr, check, N, M, mycheck);
    std::cout << mycheck << '\n';
  }
  return 0;
}

int check_array(const vector<int>& arr, vector<int>&check, int N, int M, int &mycheck){

  check[M] = 1;

  if (M == N - 1) {
    mycheck = 1;
    return 1;
  }else{
    if (M < 0 || M >= N) {
    }else if(check[M + arr[M]] != 1 && check[M + arr[M]] < N){
      check_array(arr, check, N, M + arr[M], mycheck);
    }else if(check[M - arr[M] != 1] && check[M - arr[M]] > 0){
      check_array(arr, check, N, M - arr[M], mycheck);
    }
  }
  return 0;
}
