//Username creation Dec 2 2020
//Easier to use this as a random token generator!!

#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
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

string randomToken(int length) {

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
// source: https://jesushilarioh.com/chapter-7-17-name-search-tony-gaddis-starting-out-with-c-plus-plus/
// allows a file to be read to a vector
void readFileContentsIntoVector(vector<string> &vector, const string file_name)
{
    ifstream inputFile;

    inputFile.open(file_name);

    if (inputFile.fail())
    {
        cout << "Error opening file." << endl; 
        exit(EXIT_SUCCESS);
    }
    else
    {
        string content;

        while (inputFile >> content)
            vector.push_back(content);
                
        inputFile.close();

    }
    
}

//print out vector information
void print(vector<string> const &a) {
   cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   cout << a.at(i) << ' ';
}

int main() {
     vector<string> names;
    readFileContentsIntoVector(names, "names");
    print(names);


    cout << "\nGenerating simulation traffic";
    srand(getTick());
    int LENGTH = 30;
    cout << "Creating random tokens...\n";
    /*for (int i = 0; i < 99; i++){
        string rndtk = randomToken(LENGTH);
        cout << "Ranoom part of session token " << i << " is: " 
        << rndtk << endl;
        cout << "Test to see same: " << rndtk << endl;
    }
    */
    cout << "\nthe end!";
    return 0;
}
//testing
