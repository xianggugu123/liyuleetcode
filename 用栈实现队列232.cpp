//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false

#include <iostream>
#include <stack>

using namespace std;
class MyQueue {
public:
    stack<int>skin;
    stack<int>skout;
    MyQueue() {

    }

    void push(int x) {
        skin.push(x);
    }

    int pop() {
        if (skout.empty()) {
            while (!skin.empty()) {
                skout.push(skin.top());
                skin.pop();
            }
        }
        int resullt = skout.top();
        skout.pop();
        return resullt;
    }

    int peek() {
        int resullt = this->pop();
        skout.push(resullt);
        return resullt;
    }

    bool empty() {
        if (skin.empty() && skout.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

//int main()
//{
//   
//     MyQueue* obj = new MyQueue();
//     int x = 1;
//     obj->push(x);
//     int param_2 = obj->pop();
//     int param_3 = obj->peek();
//     bool param_4 = obj->empty();
//     
//	return 0;
//}
