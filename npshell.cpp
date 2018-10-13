#include <iostream>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void initenv(){
    char buff[80];
    getcwd(buff,sizeof(buff));
    chroot(buff);
    //chdir("/");
    setenv("PATH","bin:.",1);
    
}

void printenv(){
    cout<<getenv("PATH")<<"\n";
}
int main()
{
string command;
cout<< "test command please\n";
while (command != "exit")
{  
    cout<<"%";
    cin>>command;
    initenv();
 
    if (command == "printenv")
        printenv();
    else if (command == "ls")
        system("ls");
    else if (command=="env")
        system("env");
    else if (command == "cat")
        system("cat");
    else 
        cout<<"ERROR\n";
}
return 0;
}
