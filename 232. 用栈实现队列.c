// 232. 用栈实现队列
// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
// 实现 MyQueue 类：
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
// 说明
// 你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
// 进阶：
// 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
// 示例：
// 输入：
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// 输出：
// [null, null, null, 1, 1, false]
// 解释：
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false
// 提示：
// 1 <= x <= 9
// 最多调用 100 次 push、pop、peek 和 empty
// 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
#include<stdio.h>
 typedef struct stack{
    int* stk;
    int stklen;
 }stack;

stack* creatStack(int n){
    stack* this=malloc(sizeof(stack));
    this->stk=malloc(sizeof(stack)*n);
    this->stklen=0;
    return this;
}
void stackpush(stack*s,int x){
    s->stk[s->stklen++]=x;
}
int stacktop(stack*s){
    return s->stk[s->stklen-1];
}
void stackpop(stack*s){
    s->stklen--;
}
bool stackempty(stack* s){
    return s->stklen==0;
}

void stackfree(stack* s){
    free(s->stk);
}

typedef struct MyQueue{
    stack* in;
    stack* out;
}MyQueue;

MyQueue* myQueueCreat(void){
    MyQueue* this=malloc(sizeof(MyQueue));
    this->in=stackcreat(100);
    this->out=stackcreat(100);
    return this;
}
void myQueuePush(MyQueue* obj,int x){
    stackpush(obj->in,x);
}
int  myQueuePop(MyQueue* obj){
    if(stackempty(obj->out)){
        while(!stackempty(obj->in)){
            stackpush(obj->out,stacktop(obj->in));
            stackpop(obj->in);
        }
    }
    int t = satcktop(obj->out);
    stackpop(obj->out);
    return t;
}
int myQueuePeek(MyQueue* obj){
    if(stackempty(obj->out)){
        while(!stackempty(obj->in)){
            stackpush(obj->out,stacktop(obj->in));
            satckpop(obj->in);
        }
    }
    return stacktop(obj->out);
}
bool myQueueEmpty(MyQueue* obj){
    return stackempty(obj->in)&&stackempty(obj->out);
}
void MyQueueFree(MyQueue* obj){
    stackfree(obj->in);
    stackfree(obj->out);
}