#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int operacionBasica(int a, int b, string op) {
    if (op == "+")
        return b += a;
    if (op == "*")
        return b *= a;
    if (op == "-")
        return b -= a;
}

void operacionStack(stack<int> &iStack, string operacion) {
    int a = iStack.top();
    iStack.pop();
    int b = iStack.top();
    iStack.pop();
    b = operacionBasica(a, b, operacion);
    iStack.push(b);
}

void operacionQueue(queue<int> &iQueue, string operacion) {
    int a = iQueue.front();
    iQueue.pop();
    int b = iQueue.front();
    iQueue.pop();
    b = operacionBasica(a, b, operacion);
    iQueue.push(b);
}

void operacionPriority(priority_queue<int, vector<int>, greater<int> > &iPriority, string operacion) {
    int a = iPriority.top();
    iPriority.pop();
    int b = iPriority.top();
    iPriority.pop();
    b = operacionBasica(a, b, operacion);
    iPriority.push(b);
}

int main() {
    string d,data;
    stack<int> myStack;
    queue<int> myQueue;
    priority_queue<int, vector<int>, greater<int> > myPriority;

    getline(cin, data);
    while (data != "#"){
        stringstream ss;
        ss << data;
        while (ss >> d){
            if ((d == "+") || (d == "*") || (d == "-")) {
                operacionStack(myStack, d);
                operacionQueue(myQueue, d);
                operacionPriority(myPriority, d);
            }
            else {
                int b = atoi(d.c_str());
                myStack.push(b);
                myQueue.push(b);
                myPriority.push(b);
            }
        }
        cout << myStack.top() << " " << myQueue.front() << " " << myPriority.top() << endl;
        while (!myQueue.empty()) {
            myQueue.pop();
        }
         while (!myPriority.empty()) {
            myPriority.pop();
        }
         while (!myStack.empty()) {
            myStack.pop();
        }
        getline(cin, data);
    }

    return 0;
}
