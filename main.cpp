#include "stack.h"
void menu() {
    system("cls");
    cout<<"==========================================================="<<endl;
    cout<<"\t\tPractica Operaciones"<<endl;
    cout<<"==========================================================="<<endl;
    //string operation="7/4*((a+b)*a)+3";
    //string operation="7/4*((a+-+--b)*a)+3";
    //string operation="2+(3)";
    string operation="17/4*((a+b)^4*a)+3";
    Stack<string>* homework= new Stack<string>();
    homework->topostfix(operation);
    //Topostfix(str);
}

int main(int argc, char const *argv[]) {
    menu();
    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}

