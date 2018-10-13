#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <string>
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


map<int,string> splited;


void split(string command){
    splited.clear();
    string reg;
    reg.clear();
    int j=0;
    for(int i = 0; i<command.size(); i++){
        if (command[i]!=' '){
            reg = reg+command[i];
        }
        else{
            splited[j]=reg;
            reg.clear();
            j++;
        }
    }
    splited[j]=reg;
}
int main()
{
string command;
cout<< "test command please\n";
while (command != "exit")
{  
    cout<<"%";
    getline(cin,command);
    split(command);
    for(int i= 0; i<splited.size(); i++)
        cout<<splited[i]<<"\n";
    initenv();
 
    if (command == "printenv")
        printenv();
    else if (command == "ls")
        system("ls");
    else if (command=="setenv")
        system("ls");
    else if (command == "cat")
        system("cat");
    else 
        cout<<"ERROR\n";
}
return 0;
}

