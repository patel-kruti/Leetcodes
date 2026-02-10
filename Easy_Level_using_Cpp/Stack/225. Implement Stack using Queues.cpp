/*
Problem: 225. Implement Stack using Queues
Link: https://leetcode.com/problems/contains-duplicate-ii/description/?envType=problem-list-v2&envId=wv5ww91e
Topics: Stack, Design, Queue
Level: Easy
*/

// Design Stack using Single Queue

class MyStack {
private: 
    queue<int> q; 
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);

        int qSize = q.size();

        for(int i = 0; i < qSize - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement =  q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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

// Stack using two Queues
// Two Approaches: 
// 1. Push -> O(n), Pop -> O(1), Top -> O(1) ---- Natural Stack usage
// 2. Push -> O(1), Pop -< O(n), Top -> O(n) 

// Aproach 1: Push -> O(n), Pop -> O(1), Top -> O(1) ---- Natural Stack usage
class MyStack {
private: 
    queue<int> q1, q2; 
public:
    MyStack() {}
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
         swap(q1, q2);
    }
    
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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

// Approach 2: Push -> O(1), Pop -< O(n), Top -> O(n) 
class MyStack {
private: 
    queue<int> q1, q2; 
public:
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {

        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q1.pop();

        swap(q1, q2);
        return topElement;
    }
    
    int top() {

        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();

        swap(q1, q2);

        return topElement;
    }
    
    bool empty() {
        return q1.empty();
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
