#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "cstring"
#include "string.h"
using namespace::std;

Node::Node()
{
    this->_data = new char[7];
    if (!this->_data)
    {
#ifdef FU
        cout << "INT PROBLEM" << endl;
#endif
        exit(1);
    }
    strcpy(this->_data, "empty");
    this->_next = NULL;
}


Node::Node(char* data)
{
    this->_data = new char[strlen(data) + 1];
    if (!this->_data)
    {
#ifdef FU
        cout << "INT PROBLEM" << endl;
#endif
        exit(1);
    }
    strcpy(this->_data, data);
    this->_next = NULL;
}

Node::Node(Node* c, char* data)
{
    this->_data = new char[strlen(data) + 1];
    if (!this->_data)
    {
#ifdef FU
        cout << "INT PROBLEM" << endl;
#endif
        exit(1);
    }
    strcpy(_data, data);
    this->_next = c;
}

Node::~Node()
{
    delete[]_data;

}

void Node::Print()
{
    cout << this->_data << ", next: " << this->_next << endl;
#ifdef FU
    cout << "next: " << this->_next << endl;
#endif
}

int Node::SetNext(Node* c)
{
    if (c == NULL)
    {
        this->_next = NULL;
    }
    else
    {
        this->_next = c; //0x0
    }
    return 0;
}


Node* Node::GetNext()
{
    return _next;
}

int Node::SetData(char* data)
{
    if (_data != NULL)
    {
        delete[]_data;
    }
    this->_data = new char[strlen(data) + 1];
    if (!this->_data)
    {
#ifdef FU
        cout << "memory wasn't allocated" << endl;
#endif
        return -3;
    }
    strcpy(this->_data, data);
    return 0;
}

