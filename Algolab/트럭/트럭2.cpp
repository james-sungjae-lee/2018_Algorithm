// Trucks 2nd
// 20180902
// Sungjae Lee

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {

  int truck_num;
  int bridge_w;
  int bridge_l;

  int check_count = 0;
  int check_weight = 0;
  int check_time = 0;

  std::cin >> truck_num >> bridge_w >> bridge_l;
  queue <int> on_the_bridge;

  for (size_t i = 0; i < truck_num; i++) {
    int one_truck;
    std::cin >> one_truck;
    for(;;){
      check_time++;
      if (check_count == bridge_w) {
        check_count--;
        check_weight = check_weight - on_the_bridge.front();
        on_the_bridge.pop();
      }
      if (check_weight + one_truck > bridge_l) {
        check_count++;
        check_weight = check_weight + 0;
        on_the_bridge.push(0);
      }else{
        check_count++;
        check_weight = check_weight + one_truck;
        on_the_bridge.push(one_truck);
        break;
      }
    }
  }
  std::cout << check_time + bridge_w << '\n';
  return 0;
}
