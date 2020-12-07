//Driver for UserGen
//This is for the experimental group that we are testing 
//Average time to generate 358 encrypted tokens where each user/connection used 15 secure pages: 23 Minutes 15 seconds
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int purgeindex;
    int tkTTL = 3;
 //Experimental group algorithm 
 for (int i=0; i<1790; i++ ){

  
    //Client has signed in with propper credentials or their token is no longer valid and needs to be given a token with TTL = 3
    string encryptTK = "gpg -r Cryptoproject --encrypt tokens/token" + to_string(i) + to_string(tkTTL) + ".txt";
    system(encryptTK.c_str());
    

    for (int TTL=2; TTL!=0; TTL-- ){
        

        
        //After decrypting client sends a request for a new page. The server, being simulated by this program, will send the toke back with a the TTL decreased by one
        string decryptTK = ("gpg --passphrase Test --decrypt tokens/token" + to_string(i) + to_string(TTL+1) + ".txt.gpg");
        system(decryptTK.c_str());

        //Client now needs a new encrypted token
        string encryptTK = "gpg -r Cryptoproject --encrypt tokens/token" + to_string(i) + to_string(TTL) + ".txt";
        system(encryptTK.c_str());
         
     
        //Server now needs to destory the old token
        if (TTL == 2)
        {
            string purge = "rm tokens/token" + to_string(i) + to_string(tkTTL) + ".txt.gpg";
            system(purge.c_str()); 
        }
        else
        {
            purgeindex = TTL +1;
            string purge = "rm tokens/token" + to_string(i) + to_string(purgeindex) + ".txt.gpg";

            system(purge.c_str());
        }  
    }
    //destory the last token from the user and generate a new one for them
    purgeindex = 1;
    string purge = "rm tokens/token" + to_string(i) + to_string(purgeindex) + ".txt.gpg";
     system(purge.c_str());

    }
}


