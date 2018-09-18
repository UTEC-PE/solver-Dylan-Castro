#ifndef NODE_H
#define NODE_H
#include <stack>
#include <string>
using namespace std;
template <typename T>
struct Node {
    stack<string> operator_stack;
    stack<string> output_queue;
    stack<double> calc_rpn;
};

#endif
