#ifndef STACK_H
#define LIST_H
#include <iostream>
#include <sstream>
#include <ctype.h>
#include "node.h"
#include <math.h>
#include <map>
using namespace std;
template <typename T>
class Stack{
    private:
        Node<string>* top;
        map<char,string> var;
    public:
        Stack();
        void topostfix(string operation);
        void stack_to_output(bool bracket);
        string tostr(auto);
        double calculator();
        ~Stack();
};
template<class T> Stack<T>::Stack(){
    top= new Node<string>;
}
template<class T> Stack<T>::~Stack(){
    delete top;
}
template<class T> double Stack<T>::calculator(){
    //Opera en notacion de postfix e imprime el resultado
    do{
        try
          {
            if(!isdigit(stoi(top->postfix.top()))){
                top->calc_rpn.push(stod(top->postfix.top()));
            }
            top->postfix.pop();
          }
          catch (...)
          {
            double num2= top->calc_rpn.top();
            top->calc_rpn.pop();
            double num1= top->calc_rpn.top();
            top->calc_rpn.pop();
            if(top->postfix.top()=="+"){
                top->calc_rpn.push(num1+num2);
            }
            else if(top->postfix.top()=="-"){
                top->calc_rpn.push(num1-num2);
            }
            else if(top->postfix.top()=="*"){
                top->calc_rpn.push(num1*num2);
            }
            else if(top->postfix.top()=="/"){
                top->calc_rpn.push(num1/num2);
            }
            else if(top->postfix.top()=="^"){
                top->calc_rpn.push(pow(num1,num2));
            }
            top->postfix.pop();
          }
    }
    while(!top->postfix.empty());
    cout << "La respuesta es: " <<top->calc_rpn.top() << endl;
    delete top;
}
template<class T> string Stack<T>::tostr(auto data){
    //Convierte los datos a string
    stringstream ss;
    ss << data;
    string s = ss.str();
    return s;
}

template<class T> void Stack<T>::stack_to_output(bool bracket){
    //Envia todos los datos del stack_operator al stack_output
    do{
        if(top->operator_stack.top()=="("){
           if(bracket){
            top->operator_stack.pop();
           }
           break;
        }
        top->output_queue.push(top->operator_stack.top());
        top->operator_stack.pop();
    }
    while(!top->operator_stack.empty());
}
template<class T> void Stack<T> ::topostfix(string operation){
   //Convierte de notacion infix a postfix
   bool next_num=false;
   for(int x=0;x<operation.length();x++){
        if(isdigit(operation[x])){
            if(next_num){
                top->output_queue.top()=tostr(top->output_queue.top())+tostr(operation[x]);
            }
            else{
                top->output_queue.push(tostr(operation[x]));
            }
            if(isdigit(operation[x+1])){

                next_num=true;
            }
            else{
                next_num=false;
            }
        }
        else if(operation[x]=='.'){
            top->output_queue.top()=tostr(top->output_queue.top())+tostr(operation[x]);
            next_num=true;
        }
        else if((int(operation[x])>=97 && int(operation[x])<=122)){
            if(var.find(operation[x])->first==operation[x]){
                top->output_queue.push(var.find(operation[x])->second);
            }
            else{
                string temp;
                cout << "Ingrese un valor para la variable "<< operation[x] << endl;
                getline (cin, temp);
                top->output_queue.push(temp);
                var[operation[x]]= temp;
            }
        }
        else if(operation[x]=='('){
            top->operator_stack.push(tostr(operation[x]));
        }
        else if(operation[x]==')'){
            stack_to_output(true);
        }
        else{
            if(operation[x]=='*'){
                if(!top->operator_stack.empty()){
                if(top->operator_stack.top()=="/" || top->operator_stack.top()=="^"){
                    stack_to_output(false);
                }
                }
            }
            else if(operation[x]=='-'){
                if(!top->operator_stack.empty()){
                if(top->operator_stack.top()=="*" || top->operator_stack.top()=="^" || top->operator_stack.top()=="-" || top->operator_stack.top()=="/"){
                    stack_to_output(false);
                }}
                if(operation[x+1]=='-'){
                    operation[x]='|';
                    operation[x+1]='+';
                }
                else if(operation[x+1]=='+'){
                    operation[x]='|';
                    operation[x+1]='-';
                }
            }
            else if(operation[x]=='+'){
                if(!top->operator_stack.empty()){
                if(top->operator_stack.top()=="-" || top->operator_stack.top()=="^" || top->operator_stack.top()=="*" || top->operator_stack.top()=="/"){
                    stack_to_output(false);
                }}
                if(operation[x+1]=='-'){
                    operation[x]='|';
                    operation[x+1]=='-';
                }
                else if(operation[x+1]=='+'){
                    operation[x]='|';
                }
            }
            if(operation[x]!='|'){
                top->operator_stack.push(tostr(operation[x]));
            }
        }
        ////////////////////////
    }
    stack_to_output(false);
    do{
        top->postfix.push(top->output_queue.top());
        top->output_queue.pop();
    }
    while(!top->output_queue.empty());
    /////////////////////////
    /*do{
        cout << top->postfix.top();
        top->postfix.pop();
    }
    while(!top->postfix.empty());*/
   calculator();
}
#endif
