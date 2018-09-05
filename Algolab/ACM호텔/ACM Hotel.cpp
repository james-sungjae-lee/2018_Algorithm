// 20180830
// Sungjae Lee

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int hotel_number(int hotel_height, int hotel_width, int nth_customer);

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
     int hotel_height;
     int hotel_width;
     int nth_customer;
     inStream >> hotel_height >> hotel_width >> nth_customer ;
       hotel_number(hotel_height, hotel_width, nth_customer);
   }

  inStream.close();
  return 0;
}

int hotel_number(int hotel_height, int hotel_width, int nth_customer){
  std::cout << ((nth_customer-1)%hotel_height+1)*100 + ((nth_customer-1)/hotel_height+1)  << '\n';
  return 0;
}
