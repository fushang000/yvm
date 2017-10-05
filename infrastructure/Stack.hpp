#ifndef INFRASTRUCTURE_STACK_H
#define INFRASTRUCTURE_STACK_H

template <typename _ElemType>
class Stack {
public:
    explicit Stack() = default;

    void push(const _ElemType &  element);

    _ElemType pop();

    _ElemType peek() const;

    bool isEmpty() const;

private:
    Stack(const Stack &) = delete;
    Stack& operator= (const Stack&) = delete;

    struct Node {
        _ElemType elem;
        Node * next;
    };
    Node * top = nullptr;
};

template<typename _ElemType>
inline void Stack<_ElemType>::push(const _ElemType & element){
    Node *newNode = new Node();
    newNode->elem = element;
    newNode->next = top;
    top = newNode;
}

template<typename _ElemType>
inline _ElemType Stack<_ElemType>::pop(){
    _ElemType elem = top->elem;
    Node * tempTop = top;
    top = top->next;
    delete tempTop;
    return elem;

}

template<typename _ElemType>
inline _ElemType Stack<_ElemType>::peek() const{
    return top->elem;
}

template<typename _ElemType>
bool Stack<_ElemType>::isEmpty() const {
    return top==nullptr;
}


#endif //INFRASTRUCTURE_STACK_H
