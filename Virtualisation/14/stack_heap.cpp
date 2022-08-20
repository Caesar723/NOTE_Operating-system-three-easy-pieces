#include <iostream>
using namespace std;





int* test1(){//stack
  int a[2]={2,2};
  return a;
}

int* test2(){//heap
  int *b =new int[2];
  b[0]=3,b[1]=4;
  return b;
}

int main() {
  int * afun=test1();
  printf("%d\n",* afun);
  int * bfun=test2();
  
  printf("%d\n",* bfun);
  return 0;
}
