#include "Node.h"
#include "List.h"

#define MAX 200
using namespace::std;

List::List()
{
    this->_first = NULL;
    this->_max = MAX;
    this->_current = 0;
}

List::List(int max)
{
    this->_first = NULL;
    this->_max = max;
    this->_current = 0;
}

List::List(Node* first)
{
    this->_first = first;
    this->_max = MAX;
    this->_current = 1;
}

List::List(const List& ds)
{
    this->_first = NULL;
    this->_max = ds._max;
    this->_current = ds._current;
}

List::~List()
{
    Node* ptr = _first;
    while (ptr != NULL)
    {
        Node* temp = ptr->_next;
        ptr = NULL;
        //delete ptr;
        ptr = temp;
        _current--;
    }
}

void List::PrintInfo()
{
    cout << "max: " << _max << " curr: " << _current << endl;
}
void List::Print()
{
    Node* ptr = _first;
    if (!ptr)
    {
        cout << "empty" << endl;
    }
    do
    {
        ptr->Print();
        ptr = ptr->_next;
    } while (ptr != NULL);
}


List& List::operator+(const List& c)
{
    List* Storage = new List(_current + c._current);

    if (!Storage)
    {
#ifdef FU
        cout << "can't create *storage*" << endl;
#endif
        //exit(1);
        return *this;
    }

    Node* ptr = this->_first;
    Node* temp = new Node;
    while (ptr != NULL)
    {
        Storage->SetNew(ptr->_data);
        ptr = ptr->_next;
    }
    ptr = c._first;
    while (ptr != NULL)
    {
        bool unique = false;
        temp = Storage->_first;
        while (temp != NULL)
        {
            if (ptr->_data != temp->_data)
            {
                unique = true;
                break;
            }
            temp = temp->_next;
        }
        if (unique)
        {
            this->SetNew(ptr->_data);
        }
        ptr = ptr->_next;
    }
    delete Storage;
    return *this;
}
List& List:: operator-()
{
    Node* ptr = _first->_next;
    //delete _first;
    _first = ptr;
    return *this;
}

List& List::operator=(const List& c)
{
    if (this == &c)
    {
        return *this;
    }
    while (GetSize() != 0)
    {
        Node* cur = _first;
        _first = _first->_next;
        delete cur;
    }
    _first = nullptr;
    Node* tmp = c._first;
    for (int i = 0; i < c.GetSize(); i++)
    {
        SetNew(tmp->_data);
        tmp = tmp->_next;
    }
    return *this;

    return *this;
}

bool List::operator==(const List& c)
{
    Node* ptr = _first;
    Node* temp = NULL;
    List* Storage = new List(_current + c._current);
    if (!Storage)
    {
#ifdef FU
        cout << "memory wasn't allocated" << endl;
#endif
        exit(1);
    }
    if (_current != c._current || _max != c._max)
    {
#ifdef FU
        cout << "not equal" << endl;
#endif
        return false;
    }
    this->Sort();
    Storage->Sort();
    temp = Storage->_first;

    while (ptr != NULL && temp != NULL)
    {
        if (ptr->_data != temp->_data)
        {
#ifdef FU
            cout << "not equal" << endl;
#endif
            return false;
        }

        temp = temp->_next;
        ptr = ptr->_next;
    }

#ifdef FU
    cout << "equal" << endl;
#endif
    delete Storage;
    return true;
}

void List::Sort()
{
    if (_current < 2)
        return;

    bool swapped;
    Node* ptr;
    Node* last = NULL;

    do
    {
        swapped = false;
        ptr = this->_first;

        while (ptr->_next != last)
        {
            if (strcmp(ptr->_data, ptr->_next->_data) > 0)
            {
                char* temp = ptr->_data;
                ptr->_data = ptr->_next->_data;
                ptr->_next->_data = temp;
                swapped = true;
            }
            ptr = ptr->_next;
        }

        last = ptr;
    } while (swapped);
}
int List::SetFirst(Node* c)
{
    Node* temp = new Node;
    temp = this->_first;
    this->_first = c;
    c->SetNext(NULL);
    delete[] temp;
    return 0;
}

int List::SetNew(char* data)
{
    Node* NewNode = new Node;
    Node* ptr = new Node;
    ptr = this->_first;
    if (NewNode == NULL)
    {
#ifdef FU
        cout << "memory wasn't allocated" << endl;
#endif
        return -3;
    }
    NewNode->SetData(data);
    NewNode->SetNext(NULL);
    if (this->_first == NULL)
    {
        this->_first = NewNode;
        _current++;
        return 1;
    }
    while (ptr->_next != NULL)
    {
        ptr = ptr->_next;
    }
    ptr->_next = NewNode;
    _current++;
    return 0;
}
int List::SetInput()
{
    char* buff = new char[255];
    if (!buff)
    {
#ifdef FU
        cout << "problem" << endl;
#endif
        return 1;
    }
    cout << "your input:" << endl;
    cin.getline(buff, 255);
    this->SetNew(buff);
    return 0;
}
int List::GetMax()
{
    return _max;
}

int List::GetCurr()
{
    return _current;
}

int List::GetSize() const
{
    Node* tmp = _first;
    int counter = 0;
    if (_first == nullptr)
    {
        return 0;
    }
    else
    {
        while (tmp != nullptr)
        {
            counter++;
            tmp = tmp->_next;
        }
    }
    return counter;
}