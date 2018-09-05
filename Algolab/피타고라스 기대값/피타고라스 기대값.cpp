// 20180905
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
ifstream inStream;

int pythagorean(int team_num, int play_num);

int main(int argc, char const *argv[]) {
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     int team_num;
     int play_num;
     inStream >> team_num >> play_num;
     pythagorean(team_num, play_num);
   }

  inStream.close();
  return 0;
}

int pythagorean(int team_num, int play_num){
  vector< vector<int> > team_scores (2);
  std::vector<int> Ws;

  float S_square;
  float A_square;
  int W;

  int team1_name;
  int team2_name;
  int team1_score;
  int team2_score;

  for (size_t i = 0; i < team_num; i++) {
    team_scores[0].push_back(0);
    team_scores[1].push_back(0);
  }

  for (size_t i = 0; i < play_num; i++) {
    inStream >> team1_name >> team2_name >> team1_score >> team2_score ;
    team_scores[0][team1_name - 1] += team1_score;
    team_scores[1][team1_name - 1] -= team2_score;
    team_scores[0][team2_name - 1] += team2_score;
    team_scores[1][team2_name - 1] -= team1_score;
  }

  for (size_t i = 0; i < team_num; i++) {
    S_square = team_scores[0][i] * team_scores[0][i];
    A_square = team_scores[1][i] * team_scores[1][i];
    if (S_square == 0 && A_square == 0) {
      W = 0;
    }else{
      W = floor((S_square / (S_square + A_square)) * 1000);
    }
    Ws.push_back(W);
  }

  std::cout << *max_element(Ws.begin(), Ws.end()) << '\n';
  std::cout << *min_element(Ws.begin(), Ws.end()) << '\n';
  return 0;
}
