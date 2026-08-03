#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <ctime>

using namespace std;
int j = 0;
int position = 0;
int i = 0;
string token[100];

string tokenizer(string text){
    int m = 0;
    do{
        if(text == ""){
            return "";
        }
        else{
        while(i < text.length() && text[i] != ' '){
            token[j] += text[i];
            i++;
        }
        i++;
        
    }
    j = j+1;    
    return token[j-1];
    }while(i < text.length());
}

/*==========================================================================================*/
/*==========================================================================================*/
/*==========================================================================================*/
int main(){

SetCurrentDirectoryA("C:\\");

char currentDir[MAX_PATH];
GetCurrentDirectoryA(MAX_PATH, currentDir);

int index = 0;
string folderName;
string path;
string text;
string gotoPath = "C:\\";
while(true){
    i = 0;
    j = 0;
    index = 0;
    for(int k = 0; k < 100; k++)
        token[k].clear();
    cout << "Work at " << gotoPath << ": ";
    getline(cin, text); /*Insert command*/
    do
{
    token[index] = tokenizer(text);

    if(token[index] == "")
        break;

    index++;

}while(true);

/*==========================================================================================*/
if(token[0]=="make"){
    folderName = token[1];
    path = token[3] + "\\" + folderName;
        if(token[2]=="at"){
            
            if(CreateDirectoryA(path.c_str(), NULL))
        {
            cout << "Folder created successfully!\n";
        }
        else{
            cout << "Could not create folder\n";
        }
        }
        else if(token[2].empty()){
            if(CreateDirectoryA(folderName.c_str(), NULL))
        {
            cout << "Folder created successfully!\n";
        }
            else{
                cout << "Could not create folder\n";
            }
        }
        else{
            printf("Error: Command followed by 'make' is invalid. Type 'help' for more details. \n");
        }
        
}
else if (token[0] == "add" ){
    float x, y, z;
    if(token[1].empty() || token[2].empty())
    {
    cout << "Usage: add <number1> <number2>\n";
    }
    else{
        x = stof(token[1]);
        y = stof(token[2]);
        z = x + y;
        cout << z << endl;
    }
}

else if (token[0] == "sub" ){
    float x, y, z;
    if(token[1].empty() || token[2].empty())
    {
    cout << "Usage: add <number1> <number2>\n";
    }
    else{
        x = stof(token[1]);
        y = stof(token[2]);
        z = x - y;
        cout << z << endl;
    }
}

else if (token[0] == "multiply" ){
    float x, y, z;
    if(token[1].empty() || token[2].empty())
    {
    cout << "Usage: add <number1> <number2>\n";
    }
    else{
        x = stof(token[1]);
        y = stof(token[2]);
        z = x * y;
        cout << z << endl;
    }
}

else if (token[0] == "divide" ){
    float x, y, z;
    if(token[1].empty() || token[2].empty())
    {
    cout << "Usage: add <number1> <number2>\n";
    }
    else{
        x = stof(token[1]);
        y = stof(token[2]);
        z = x / y;
        cout << z << endl;
    }
    }

else if (token[0] == "exit" || token[0] == "end" || token[0] == "close" ){
    printf("Terminated...");
    Sleep(1000);
    exit(1);
}
else if (token[0] =="what"){
    if(token[1]=="time"){
        time_t now = time(NULL);

    tm *local = localtime(&now);

    cout << "Hour   : " << local->tm_hour << endl;
    cout << "Minute : " << local->tm_min << endl;
    cout << "Second : " << local->tm_sec << endl;
    }
    else if(token[1]=="date"){
        time_t now = time(NULL);
    tm *local = localtime(&now);

    cout << local->tm_mday << "/"
         << local->tm_mon + 1 << "/"
         << local->tm_year + 1900 << endl;
    }
    else if(token[1]=="folder"){
        char currentDir[MAX_PATH];
        GetCurrentDirectoryA(MAX_PATH, currentDir);
        cout << currentDir << endl;
    }

}
else if(token[0]=="open"){
    gotoPath = token[1];
    SetCurrentDirectoryA(gotoPath.c_str());
}

else if(token[0]=="text"){
    if(token[1]=="create"){
        string textfileName;
        textfileName = token[2];
        FILE *textFile;
        string fullPath = string(currentDir) + "\\" + textfileName;
        textFile = fopen(fullPath.c_str(), "w");
    }
    else if(token[1]=="open"){
        string readFileName = token[2];
        FILE *textFile = fopen(readFileName.c_str(), "r");
    }
}
else if(token[0]=="play"){
string program;
program = token[1];
    ShellExecuteA(
    NULL,
    "open",
    program.c_str(),
    NULL,
    NULL,
    SW_SHOWNORMAL
);
    
}
else if(token[0]=="delete"){
    string fileName = token[1];
    remove(fileName.c_str());
}

else if(token[0]=="clear"){
    system("cls");
}
else if(token[0] == "rename")
{
    string oldName = token[1];
    string newName = token[2];

    if(rename(oldName.c_str(), newName.c_str()) == 0)
    {
        cout << "Renamed successfully!\n";
    }
    else
    {
        cout << "Failed to rename.\n";
    }
}
else if(token[0]=="credits"){
    printf("Developed by Arnish!\n");
}

/*==========================================================================================*/
else if(token[0]=="help" || token[0]=="helpme"){
    cout << R"(Simpell: A Shell by Arnish!

Available Commands:

add <a> <b>         //Adds two numbers
sub <a> <b>         //Subtracts two numbers
multiply <a> <b>    //Multiplies two numbers
divide <a> <b>     //Divides two numbers

make <folder>     //Create a folder in current directory
make <folder> at <path>     //Create a folder at path
rename <oldname> <newname>     //Rename a file
delete <file>     //Delete a file
open <path>     //Open the directory/path

what time     //Get current time
what date     //Get current date
what folder     //Get current directory

text create     //create a new text file
text open     //open a pre-existing text file

play <application>     //play an application

clear     //clear the terminal
exit    //Exit the terminal
)"<<endl;
}
/*==========================================================================================*/
else{
    printf("Error: This command does not exist. Type 'help' for more commands \n");
}
/*==========================================================================================*/
    }
}
