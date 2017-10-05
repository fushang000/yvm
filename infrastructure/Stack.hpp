#ifndef INFRASTRUCTURE_STACK_H
#define INFRASTRUCTURE_STACK_H

template <typename _ElemType>
class Stack {
public:
    explicit Stack() = default;

    void push(const _ElemType &  element);

    _ElemType pop();

    _ElemType peek();

private:
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
inline _ElemType Stack<_ElemType>::peek(){
    if (top != nullptr) {
        return top->elem;
    }
    return _ElemType(0);
}


#endif //INFRASTRUCTURE_STACK_H
