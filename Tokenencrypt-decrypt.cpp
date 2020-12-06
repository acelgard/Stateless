#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;
int main(){
    int index = 2;
    int tkTTL = 3;

for (int i=0; i<1790; i++ ){
    for (int TTL=3; TTL!=0; TTL-- ){
        /*
        string encryptTK = "gpg -r Cryptoproject --encrypt tokens/token" + to_string(i) + to_string(TTL) + ".txt";
        system(encryptTK.c_str());
*/
        cout << "";
        
    }

}


string purge = "rm tokens/token" + to_string(index) + to_string(tkTTL) + ".txt";
system(purge.c_str());
}