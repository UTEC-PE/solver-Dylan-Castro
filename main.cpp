#include "stack.h"
void menu() {
    system("cls");
    cout<<"==========================================================="<<endl;
    cout<<"\t\tPractica Operaciones"<<endl;
    cout<<"==========================================================="<<endl;
    //char operation[]="7/4*((a+b)*a)+3";
    //char operation[]="7/4*((a+-+--b)*a)+3";
    //char operation[]="2+(3)";
    char operation[]="17/4*((a+b)^4*a)+3";
    Stack<char>* homework= new Stack<char>();
    homework->topostfix(operation);
}

int main(int argc, char const *argv[]) {
    menu();
    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}

