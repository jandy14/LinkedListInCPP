#include "List.h"

template <class T>
typename List<T>::Iterator& List<T>::Iterator::Next() {
    current = current->next;
    return *this;
}
template <class T>
typename List<T>::Iterator& List<T>::Iterator::Prev() {
    current = current->prev;
    return *this;
}

template <class T>
List<T>::List() {
    size = 0;
    begin.next = &end;
    end.prev = &begin;
}
template <class T>
List<T>::~List() {
    Clear();
}
template <class T>
T& List<T>::Front() {
    if(size != 0)
    {
        return (begin.next)->item;
    }
    return nullptr;
}
template <class T>
T& List<T>::Back() {
    if(size != 0)
    {
        return (end.prev)->item;
    }
    return nullptr;
}
template <class T>
inline int List<T>::Size() { return size; }

template <class T>
void List<T>::PushFront(const T& pItem) {
    Node* node = new Node(pItem, &begin, begin.next);
    LinkNode(node);
}
template <class T>
void List<T>::PushBack(const T& pItem) {
    Node* node = new Node(pItem, end.prev, &end);
    LinkNode(node);
}
template <class T>
T List<T>::PopFront() {
    Node* node = begin.next;
    T tmp = node->item;
    RemoveNode(node);
    return tmp;
}
template <class T>
T List<T>::PopBack() {
    Node* node = end.prev;
    T tmp = node->item;
    RemoveNode(node);
    return tmp;
}
template <class T>
void List<T>::InsertRight(List<T>::Iterator& pIter, const T& pItem) {
    Node* node = new Node(pItem, pIter.current, (pIter.current)->next);
    LinkNode(node);
}
template <class T>
void List<T>::InsertLeft(List<T>::Iterator& pIter, const T& pItem) {
    Node* node = new Node(pItem, (pIter.current)->prev, pIter.current);
    LinkNode(node);
}
template <class T>
void List<T>::Insert(List<T>::Iterator& pIter, const T& pItem) {
    InsertLeft(pIter, pItem);
}
template <class T>
T List<T>::Erase(List<T>::Iterator& pIter) {
    Node* node = pIter.current;
    pIter.current = (pIter.current)->prev; //for Convenience
    T tmp = node->item;
    RemoveNode(node);
    return tmp;
}
template <class T>
void List<T>::Clear() {
    Node* node = begin.next;
    while(node != &end)
    {
        RemoveNode(node);
        node = begin.next;
    }
}
template <class T>
void List<T>::RemoveNode(Node* pNode) {
    pNode->prev->next = pNode->next;
    pNode->next->prev = pNode->prev;
    --size;
    delete pNode;
}
template <class T>
void List<T>::LinkNode(Node* pNode){
    pNode->prev->next = pNode;
    pNode->next->prev = pNode;
    ++size;
}
