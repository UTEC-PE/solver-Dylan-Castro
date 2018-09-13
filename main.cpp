#include <iostream>
#include <string.h>
#include <stack>
#include <ctype.h>
using namespace std;

void Topostfix(char* operation){
    stack<int> output;
    stack<char> operators;
    for(int x=0;x<strlen(operation);x++){
    }
    cout << output[0];
    cout << output[1];
}
void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      char str[]="7/4*((a+b)^4*a)+3";
      Topostfix(str);
}

int main(int argc, char const *argv[]) {
    menu();
    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}

