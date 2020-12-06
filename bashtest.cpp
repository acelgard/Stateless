#include <stdio.h>
#include <stdlib.h>
#include <string>

// ....
using namespace std;
int main(){
    int index = 2;
system("./echotest.sh");
system("echo \"this is a test\"");
system("cat tokens/gen_test.txt");
string tester = "this a test" + to_string(index) + "rest";

string encryptTK = "gpg -r Cryptoproject --encrypt tokens/gen_test" + to_string(index) + ".txt";
system(encryptTK.c_str());
}
