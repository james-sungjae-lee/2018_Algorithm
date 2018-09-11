#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int i = 1;
  int triangle;
  while (true) {
    triangle = i * (i + 1) / 2;
    std::cout << triangle << '\n';
    if (triangle > 1000) {
      break;
    }
    i += 1;
  }
  std::cout << "end index is " << 45*45*45 << '\n';
  return 0;
}

// #include <stdio.h>
//
// int T,A[45],D[1001];
//
// int main()
// {
//     int i, j, k;
//     for (i=1;i<45;i++) A[i] = i*(i+1)/2;
//     for (i=1;i<45;i++) for (j=i;j<45;j++) for (k=j;k<45;k++) if (A[i]+A[j]+A[k] < 1001) D[A[i]+A[j]+A[k]] = 1;
//     for (scanf("%d", &T);T--;){
//         scanf("%d", &k); printf("%d\n", D[k]);
//     }
// }
