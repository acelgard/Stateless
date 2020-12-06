//Username creation Dec 2 2020
//Easier to use this as a random token generator!!

#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <string>

//#include
using namespace std;



//random seed gen
uint32_t getTick() {
    struct timespec ts;
    unsigned theTick = 0U;
    clock_gettime( CLOCK_REALTIME, &ts );
    theTick  = ts.tv_nsec / 1000000;
    theTick += ts.tv_sec * 1000;
    return theTick;
}


// creates random alphanumerical charaters, upper and lower with '-' and '_' are used totaling 64 charaters charaters
string randomToken(int length) {

  char alphanumchar[] = {'a','e','i','o','u','y','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z',
                        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                        '1','2','3','4','5','6','7','8','9','~','_'}; 

  string name = "";

  int random = rand() % 2;

  for(int i = 0; i < length; i++) {
      name = name + alphanumchar[rand() % 63];
    }
    random = rand() % 2;
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
   cout << "# " << i+1 << ": " << a.at(i) << ' ';
}

//generates a full token to be encrypted (name-sID-Date-TTL)
string fullToken(string name, string sID_Token, string TTL) {
   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);
string fullToken = name + "-" + sID_Token + "-" + dt + TTL;
return fullToken;
}
//START of main function
int main() {
  
    vector<string> names;
    vector<string> sessionID;
    readFileContentsIntoVector(names, "Names");



    
    //print(names);
    cout << "\nGenerating simulation traffic";
    srand(getTick());
    int LENGTH = 15;
    int tokenIndex = 0;
    int TTL = 3;
    cout << "Creating random tokens...\n";
    for (int i = 0; i < 2000; i++) {
        sessionID.push_back(randomToken(LENGTH));
        cout << "Random part of session token " << i << " is: " << sessionID.at(i) << endl;   
    } 




      for (int i=0; i < names.size(); i++){
        for (int j=0; j < 5; j++){
          for (int k=0; k < 3; k++){
            string TTLs = to_string(TTL);
            //Three tokens are made with only the TTL Changing 
            TTL--;
            cout << "TTL :" <<  TTLs << endl;
            string fullTK = fullToken(names.at(i), sessionID.at(tokenIndex), TTLs);
            cout << "This the full token before encryption: " << fullTK << endl;
            // create file for encryption
            /*
            string TKfilename = "tokens/token" + to_string(index) + ".txt";
            ofstream outfile (TKfilename);
            outfile << fullTK << endl;
            outfile.close();
            */
            //token index is used to keep track of what random tokens can still be used
            int leng = fullTK.length();
            cout << "Token index is: " << tokenIndex << endl << endl;
           }
          //go to next session id and rest TTL
          tokenIndex++;
          TTL = 3;
        }
     }   
    
   // concatinate the name, date, sessionID, and random data
   // push this data in a file by file bases so the gpg bash script can encrypt it
    return 0;
}
//testing
// current plan is to use a bash script to encrypt and decrypt with gpg
// 
