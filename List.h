template <class T>
class List {
    class Node; //전방선언
public:
	class Iterator {
    public:
        Node* current;
	private:
		bool isReversed;
	public:
        Iterator():isReversed(false) {}
        Iterator(bool pIsReversed):isReversed(pIsReversed) {}
        Iterator(bool pIsReversed, Node* pCurrent):isReversed(pIsReversed), current(pCurrent) {}
        Iterator& operator++() { return isReversed? Prev() : Next(); }
        Iterator& operator--() { return isReversed? Next() : Prev(); }
        Iterator operator++(int) { return isReversed? Prev() : Next(); }
        Iterator operator--(int) { return isReversed? Next() : Prev(); }
        bool operator==(const Iterator& pIter) { return current == pIter.current; }
        bool operator!=(const Iterator& pIter) { return current != pIter.current; }
        T& operator*() { return current->item; }
    private:
        Iterator& Next();
        Iterator& Prev();
	};
private:
	class Node {
	public:
		T item;
        Node* prev;
		Node* next;
        Node(T pItem, Node* pPrev, Node* pNext):item(pItem), next(pNext), prev(pPrev) {}
        Node():next(nullptr), prev(nullptr) {}
	};
	Node begin;
	Node end;
	int size;
public:
	List();
	~List();

	T& Front();
	T& Back();
	int Size();

	Iterator Begin() { return Iterator(false, begin.next); }
	Iterator End() { return Iterator(false, &end); }
	Iterator RBegin() { return Iterator(true, end.prev); }
	Iterator REnd() { return Iterator(true, &begin); }

	void PushFront (const T& item);
	void PushBack (const T& item);
	T PopFront();
	T PopBack();
	void InsertRight(Iterator&, const T&);
	void InsertLeft(Iterator&, const T&);
	void Insert(Iterator&, const T&);
	T Erase(Iterator&);
    void Clear();
private:
    void RemoveNode(Node*);
    void LinkNode(Node*);
};
