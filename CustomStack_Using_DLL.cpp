// Design a stack that supports increment operations on its elements.

// Implement the CustomStack class:

// CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
// int pop() Pops and returns the top of the stack or -1 if the stack is empty.
// void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.

class Node{
    public:
    int val;
    Node* prev,*next;
    Node(int data){
        val=data;
        prev=next=NULL;
    }
} ;

class CustomStack {
public:
    Node* head=NULL,*tail=NULL;int m;
    CustomStack(int maxSize) {
        m=maxSize;
    }
    
    void push(int x) {
        if(m<=0)return;
        Node* n=new Node(x);
        if(!head || !tail){
            head=tail=n;
            m--;return;
        }
        // Node* k=tail;
        m--;
        tail->next=n;
        n->prev=tail;
        tail=n;
        return;

    }
    
    int pop() {
        if(!tail)return -1;
        m++;
        int k=tail->val;
        tail=tail->prev;
        if(tail)tail->next=NULL;
        return k;
    }
    
    void increment(int k, int val) {
        Node* t=head;
        while(k-- && t){
            t->val=t->val+val;
            t=t->next;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
