// 20180905
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int multi_max(int card_number);

int main(int argc, char const *argv[]) {

  int numTestCases;
  int card_number;

  cin >> numTestCases;

  for (size_t i = 0; i < numTestCases; i++) {
    cin >> card_number;
    multi_max(card_number);
  }

  return 0;
}

int multi_max(int card_number){
  std::vector<int> numbers;
  std::vector<int> find_max;

  int one_card;

  for (size_t i = 0; i < card_number; i++) {
    std::cin >> one_card;
    numbers.push_back(one_card);
  }

  sort(numbers.begin(), numbers.end());

  find_max.push_back(numbers[0] * numbers[1]);
  find_max.push_back(numbers[numbers.size()-1] * numbers[numbers.size()-2]);
  find_max.push_back(numbers[0] * numbers[numbers.size()-1]);

  find_max.push_back(numbers[0] * numbers[1] * numbers[2]);
  find_max.push_back(numbers[0] * numbers[1] * numbers[numbers.size()-1]);
  find_max.push_back(numbers[numbers.size()-1] * numbers[numbers.size()-2] * numbers[0]);
  find_max.push_back(numbers[numbers.size()-1] * numbers[numbers.size()-2] * numbers[numbers.size()-3]);

  std::cout << *max_element(find_max.begin(), find_max.end()) << '\n';

  return 0;
}
