//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
#include <queue>
#include <iostream>
using namespace std;
class MyStack {
public:
    queue<int> qw;
    MyStack() {

    }

    void push(int x) {
        qw.push(x);
    }

    int pop() {
        int len = qw.size();
        len--;
        while (len--) {
            qw.push(qw.front());
            qw.pop();
        }
        int result = qw.front();
        qw.pop();
        return result;

    }

    int top() {
        return qw.back();
    }

    bool empty() {
        return qw.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
	return 0;
}
