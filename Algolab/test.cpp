#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<int> test;
  for (size_t i = 1; i <= 10; i++) {
    test.push_back(100 * i);
  }
  std::cout << test.size() << '\n';
  std::cout << test[test.size() - 2] << '\n';
  std::cout << test.front() << '\n';
  return 0;
}
