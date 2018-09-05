// Trucks
// 20180830
// Sungjae Lee

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int truck_times(int truck_num, int bridge_w, int bridge_l);

int main(int argc, char const *argv[]) {
     int truck_num;
     int bridge_w;
     int bridge_l;
     cin >> truck_num >> bridge_w >> bridge_l;
     truck_times(truck_num, bridge_w, bridge_l);
   return 0;
}

int truck_times(int truck_num, int bridge_w, int bridge_l){

  // 트럭들의 하중을 순차적으로 저장하는 벡터의 생성
  std::vector<int> trucks;
  int one_truck;
  for (size_t i = 0; i < truck_num; i++) {
    std::cin >> one_truck;
    trucks.push_back(one_truck);
  }

  // 지나가는데 걸리는 시간 계산
  int check_time = 0;

  // 하중 체크, 트럭 대수 체크
  int check_weight = 0;
  int check_count = 0;

  // 다리 위에 존재하는 트럭의 하중을 계산하는 큐를 생성
  queue<int>on_the_bridge;

  for (size_t i = 0; i < truck_num; i++) {

    // 한대의 트럭 하중을 받아오며, 동시에 시간 증가
    int temp_truck;
    temp_truck = trucks[i];
    check_time++;

    while (1) {
      if (check_count == bridge_w) {
        check_count --;
        check_weight -= on_the_bridge.front();
        on_the_bridge.pop();
      }
      if (check_weight + temp_truck > bridge_l) {
        check_count ++;
        check_weight += 0;
        on_the_bridge.push(0);
      }else{
        check_count ++;
        check_weight += temp_truck;
        on_the_bridge.push(temp_truck);
        break;
      }
    }
  }
  std::cout << check_time + truck_num << '\n';
  return 0;
}


// 4 -> 트럭 개수
// 2 -> 다리의 길이 : 한 번 건널때 드는 시간
// 10 -> 다리의 하중 : 한 번에 버틸 최대 하중
//
// 7, 4, 5, 6 -> 각 트럭의 하중
//
// 1. 트럭을 배열 하나에 넣어둔다
// 2. 배열에서 하나의 트럭을 뺀다.
// 3. 해당 트럭이 전체 하중보다 작으면, 하나 더 뺀다
// 4. 둘의 합이 전체 하중보다 작으면 -> 반복
// 5. 둘의 합이 전체 하중보다 크면 -> 이전의 값까지만 한텀으로 친다
// 6. 최종적으로 반복 횟수 * 다리의 길이 = 걸린 시간 이다.
