#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;
int main(){
    int i = 0;
    const int TTL = 3;
    
//
while (i<1790)
{
  
    //Client has signed in with propper credentials and needs a token
    string encryptTK = "gpg -r Cryptoproject --encrypt tokens/token" + to_string(i) + to_string(TTL) + ".txt";
    system(encryptTK.c_str());
    for (int j=0;j<10;j++){
        //After client sends a request for a new page. The server, being simulated by this program, will decrypt the token and verify it (15 secure pages simulated)
      

        string decryptTK = ("gpg --passphrase Test --decrypt tokens/token" + to_string(i) + to_string(TTL) + ".txt.gpg");
        system(decryptTK.c_str());
    }
    //after the conection is dropped the server deletes the old token
    string purge = "rm tokens/token" + to_string(i) + to_string(TTL) + ".txt.gpg";
    system(purge.c_str());

    //increase the counter to the next user
    i += 5;
}

}

//----helpful debug commands
         //string debug = "ls tokens/token" + to_string(i) + to_string(tkTTL) + ".txt.gpg";
            //cout << "current purge request: " <<purge << endl;
            //system(debug.c_str());
