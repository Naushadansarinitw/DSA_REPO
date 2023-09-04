
// T.C O(n^2);
// S.C O(n)

void insertAtBottom(stack<int>& s,int element){
    if(s.empty()){
        s.push(element);
    }

    int num = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, element);
    s.push(num);
}

void reverseStack(stack<int>& stack){
    // base case 
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack,num);
}