//Username creation Dec 2 2020
#include <chrono>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
//#include
using namespace std;




uint32_t getTick() {
    struct timespec ts;
    unsigned theTick = 0U;
    clock_gettime( CLOCK_REALTIME, &ts );
    theTick  = ts.tv_nsec / 1000000;
    theTick += ts.tv_sec * 1000;
    return theTick;
}

string randomName(int length) {

  char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  char vowels[] = {'a','e','i','o','u','y'};

  string name = "";

  int random = rand() % 2;
  int count = 0;

  for(int i = 0; i < length; i++) {

    if(random < 2 && count < 2) {
      name = name + consonents[rand() % 19];
      count++;
    }
    else {
      name = name + vowels[rand() % 5];
      count = 0;
    }

    random = rand() % 2;

  }

  return name;

}

int main() {
    srand(getTick());
    int LENGTH = 25;
    cout << "Hello World!\n";
    cout << randomName(LENGTH) << endl;
    int k = 3;
    int a = 5;
    for (int i = 0; i < 99; i++){
       cout << randomName(LENGTH) << endl;
    }
    cout << "\nthe end!";
    return 0;
}
//testing
