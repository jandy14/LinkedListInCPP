# LinkedListInCPP
Linked List 구현

최대한 STL의 List와 비슷하게 구현하고자 하였습니다.

# 주요구현 기능
* Linked List
* Iterator
* template

# 인터페이스

## 값 접근
* T& Front()
*	T& Back()
*	int Size()

## Iterator
* Iterator Begin()
*	Iterator End()
*	Iterator RBegin()
*	Iterator REnd()

## 값 삽입/삭제
* void PushFront (const T& item);
* void PushBack (const T& item);
* T PopFront();
* T PopBack();
* void InsertRight(Iterator&, const T&);
* void InsertLeft(Iterator&, const T&);
* void Insert(Iterator&, const T&);
* T Erase(Iterator&);
* void Clear();
