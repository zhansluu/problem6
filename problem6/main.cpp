#include <iostream>
#include "list_b.h"
#include "stack_b.h"
#include "queue_b.h"


using namespace std;

int main()
{
    Stack <double> q;
    q.Push(8.2);
    q.Push(9);
    q.Push(10.01);
    q.Pop(nullptr);
    Stack<double> q2;
    Stack<double>& qq = q;
    q2 = qq;
    cout << q2;
    return 0;
}
