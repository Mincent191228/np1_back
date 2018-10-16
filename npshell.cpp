#include <iostream>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <string>

using namespace std;


const char *path;//setenv
void initenv(int flag){
    //cout<<flag<<"\n";
    char buff[80];
    getcwd(buff,sizeof(buff));
    chroot(buff);
    chdir(buff);
    if (flag == 0)
        setenv("PATH","bin:.",1);
    
    if (flag == 1)
        setenv("PATH",path,1);
}

void printenv(){
    cout<<getenv("PATH")<<"\n";
}


//map<int,string> splited;
const char *splited[5];

int split(string command){
    //splited.clear();
    string reg;
    reg.clear();
    int j=0;
    int mean=0;
    for(int i = 0; i<command.size(); i++){
        if (command[i]!=' '){
            reg = reg+command[i];
            mean=1;
        }
        else if ((command[i]=='>'&&command[i-1]!=' ')||(command[i]=='<'&&command[i-1]!=' ')){
            splited[j]=reg.c_str();
            reg.clear();
            j++;
            if (command[i]=='>')
                splited[j]=">";
            if (command[i]=='<')
                splited[j]="<";
            j++;
        }
        else{
            if (mean==1){
                splited[j]=reg.c_str();
                reg.clear();
                j++;
            }
        }
    }
    cout<<"2";
    splited[j]=reg.c_str(); 
    return (j+1);
}

int sys(const char *name ,const char *arg,int flag) {
    int pid, status;
    //arg = "bin";
    string spa ;
    spa.clear();
    if(arg==spa)
        flag=0;    
    split(arg);
    for (int i=0;i<4;i++)
        cout<<splited[i];
    if (pid = fork()) {
        waitpid(pid, &status, 0);
    }
    else{
        if (flag==0)
            execlp(name,name, NULL);
        else if (flag==1)
            execlp(name,name,splited[0],NULL);
        else if (flag==2)
            execlp(name,name,splited[0],splited[1],NULL);
        else if (flag==3)
            execlp(name,name,splited[0],splited[1],splited[2],NULL);
        else if (flag==4)
            execlp(name,name,splited[0],splited[1],splited[2],splited[3],NULL);
    }
    return status;
}

int main()
{
int n=0;
string c;
string command;
initenv(0);
cout<< "test command please\n";
while (command != "exit")
{  
    c.clear();
    cout<<"%";
    getline(cin,command);
    cout<<"1";
    int f =split(command);
    cout<<"3";
    string s;
    //const char *first = splited[0].c_str;
    //string y = splited[0];
    //string x = splited[1];
    //const char *first = y.c_str();
    //const char *com = x.c_str();
    
    const char *first = splited[0];
    for (int i=0;i<f;i++){
        s.clear();
        s = splited[i+1];
        c=c+s;
    }
    cout<<"c is"<<c<<"\n";
    const char *com = c.c_str();
    cout<<"main first ="<<first<<"\n";
    cout<<"main com ="<<com<<"\n";
    if (splited[0] == "printenv")
        printenv();
    else if (splited[0] == "ls"){
        //const char *com = command.c_str();
        sys(first, com,f);
    }
    else if (splited[0]=="setenv"){
        path = splited[2];
        initenv(1);
    }
       
    else if (splited[0]=="removetag"){
        //const char *com = command.c_str();
        sys(first,com,f);
    }
    else if (splited[0]=="removetag0"){
        //const char *com = command.c_str();
        sys(first,com,f);
    }
    else if (splited[0]=="number"){
        //const char *com = command.c_str();
        sys(first,com,f);
    }
    else if (splited[0]=="noop"){
        //const char *com = command.c_str();
        sys(first,com,f);
    }
    else if (splited[0] == "cat"){
        //const char *com = command.c_str();
        sys(first,com,f);
    }
    else{
        if (splited[0] != "exit")
        cout<<"ERROR\n";
    }
}
return 0;
}

