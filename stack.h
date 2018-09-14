#ifndef STACK_H
#define LIST_H
#include <iostream>
#include <string.h>
#include <ctype.h>
#include "node.h"
using namespace std;
template <typename T>
class Stack{
    private:
        Node<char>* top;
    public:
        Stack();
        void topostfix(char* operation);
        void stack_to_output(bool bracket);
        ~Stack();
};
template<class T> Stack<T>::Stack(){
    top= new Node<char>;
}
template<class T> Stack<T>::~Stack(){
    delete top;
}
template<class T> void Stack<T>::stack_to_output(bool bracket){
    do{
        if(top->operator_stack.top()=='('){
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
template<class T> void Stack<T> ::topostfix(char* operation){
   for(int x=0;x<strlen(operation);x++){
        if(isdigit(operation[x]) || (int(operation[x])>=97 && int(operation[x])<=122)){
            top->output_queue.push(operation[x]);
        }
        else if(operation[x]=='('){
            top->operator_stack.push(operation[x]);
        }
        else if(operation[x]==')'){
            stack_to_output(true);
        }
        else{
            if(operation[x]=='*'){
                if(top->operator_stack.top()=='/' || top->operator_stack.top()=='^'){
                    stack_to_output(false);
                }
            }
            else if(operation[x]=='-'){
                if(top->operator_stack.top()=='*' || top->operator_stack.top()=='^' || top->operator_stack.top()=='-' || top->operator_stack.top()=='/'){
                    stack_to_output(false);
                }
            }
            else if(operation[x]=='+'){
                if(top->operator_stack.top()=='-' || top->operator_stack.top()=='^' || top->operator_stack.top()=='*' || top->operator_stack.top()=='/'){
                    stack_to_output(false);
                }
            }
            top->operator_stack.push(operation[x]);
        }
        ////////////////////////
    }
    stack_to_output(false);
    stack<char> postfix;
    do{
        postfix.push(top->output_queue.top());
        top->output_queue.pop();
    }
    while(!top->output_queue.empty());
    /*double dig_1=postfix.top();
    postfix.pop();
    double dig_2=postfix.top();
    postfix.pop();
    do{
        postfix.pop();
    }
    while(!postfix.empty());*/
}
#endif
