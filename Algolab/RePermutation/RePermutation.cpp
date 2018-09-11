#include <iostream>
#include <cstring>

using namespace std;

void permutation(string, int, int);

int main(int argc, char const *argv[]) {
  permutation("abcdef", 0, 5);
  return 0;
}

void permutation(string str, int begin, int end){

  int range = end - begin;

  if (range == 1) {
    std::cout << str << '\n';
  }else{
    for (size_t i = 0; i < range; i++) {
      swap(str[begin], str[begin + i]);
      permutation(str, begin + 1, end);
      swap(str[begin], str[begin + i]);
    }
  }
}
