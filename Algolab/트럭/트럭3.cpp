#include <iostream>
#include <cstring>
#include <fstream>
#pragma warning (disable : 4996)
using namespace std;

int main()
{
	int testCase;
	int numofTrucks = 0, length = 0, maxWeight = 0;

	while (testCase--) {
		std::cin >> numofTrucks >> length >> maxWeight;
		fscanf(fstream, "%d %d %d", &numofTrucks, &length, &maxWeight);
		int* truck = new int[numofTrucks];
		int* bridge = new int[length];
		memset(bridge, 0, sizeof(int)*length);

		for (int i = 0; i < numofTrucks; i++)
			fscanf(fstream, "%d", truck + i);

		int index = 0;
		int clock = 0;
		while (index < numofTrucks) {
			int sumofWeight = 0;
			clock++;

			for (int i = length - 1; i > 0; i--) {
				bridge[i] = bridge[i - 1];
				sumofWeight += bridge[i];
			}
			if (sumofWeight + truck[index] <= maxWeight && truck[index] != 0) {
				bridge[0] = truck[index];
				sumofWeight += bridge[0];
				truck[index] = 0;
				if (index == numofTrucks - 1) {
					clock += length;
					break;
				}
				index++;
			}
			else {
				bridge[0] = 0;
			}
		}
		cout << clock << endl;
		delete[]truck;
		delete[]bridge;
	}

	fclose(fstream);
	return 0;
}
