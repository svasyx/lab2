#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "cstring"
#include "string.h"
class Node
{
    friend class List;

public:


    Node();
    Node(char* data);
    Node(Node* c, char* data);
    ~Node();
    void Print();
    int SetData(char* data);
    char* GetData(char* buff);
    int SetNext(Node* c);
    Node* GetNext();

private:
    Node* _next;
    char* _data;

};
