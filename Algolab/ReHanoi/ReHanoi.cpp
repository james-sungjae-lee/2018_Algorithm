// 20180911
// Sungjae Lee

#include <iostream>

using namespace std;

int hanoi(int, int, int, int);

int main(int argc, char const *argv[]) {
  hanoi(2, 1, 2, 3);
  return 0;
}

int hanoi(int n, int a, int b, int c){
  if (n > 0) {
    hanoi(n-1, a, c, b);
    std::cout << a << " -> " << c << '\n';
    hanoi(n-1, b, a, c);
  }
  return 0;
}
