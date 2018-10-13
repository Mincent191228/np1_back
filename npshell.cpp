#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


int main()
{
string command;
cout<< "test command please\n";
while (command != "exit")
{
    if (command == "printenv")
        system("printenv");
    else if (command == "ls")
        system("ls");
    else if (command=="env")
        system("env");
cout<<"%";
cin>>command;
}
return 0;
}
