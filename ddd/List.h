#include "Node.h"

class List
{
public:
    List();
    List(int max);
    List(Node* first);
    List(const List& ds);
    ~List();
    List& operator+(const List& c);
    bool operator== (const List& c);
    List& operator=(const List& c);
    List& operator-();
    void Print();
    void PrintInfo();
    void Sort();
    int SetFirst(Node* c);
    int SetNew(char* data);
    int SetInput();
    int GetCurr();
    int GetMax();
    int GetSize() const;

private:
    Node* _first;
    int _current;
    int _max;

};
