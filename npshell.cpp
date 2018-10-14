#include <iostream>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <string>

using namespace std;


const char *path;
void initenv(int flag){
    cout<<flag<<"\n";
    char buff[80];
    getcwd(buff,sizeof(buff));
    chroot(buff);
    //chdir("/");
    if (flag == 0)
        setenv("PATH","bin:.",1);
    
    if (flag == 1)
        setenv("PATH",path,1);
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
initenv(0);
cout<< "test command please\n";
while (command != "exit")
{  
    cout<<"%";
    getline(cin,command);
    split(command);
    
 
    if (splited[0] == "printenv")
        printenv();
    else if (splited[0] == "ls"){
        const char *com = command.c_str();
        system(com);
    }
    else if (splited[0]=="setenv"){
        path = splited[2].c_str();
        initenv(1);
    }
       
    else if (splited[0]=="removetag"){
        const char *com = command.c_str();
        system(com);
    }
    else if (splited[0]=="removetag0"){
        const char *com = command.c_str();
        system(com);
    }
    else if (splited[0]=="number"){
        const char *com = command.c_str();
        system(com);
    }
    else if (splited[0]=="noop"){
        const char *com = command.c_str();
        system(com);
    }
    else if (splited[0] == "cat"){
        const char *com = command.c_str();
        system(com);
    }
    else 
        cout<<"ERROR\n";
}
return 0;
}

