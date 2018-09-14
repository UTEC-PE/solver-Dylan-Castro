#ifndef NODE_H
#define NODE_H
#include <stack>
using namespace std;
template <typename T>
struct Node {
    stack<char> operator_stack;
    stack<char> output_queue;
};

#endif
