#ifndef LIST_H_INCLUDED

#define LIST_H_INCLUDED
#include <iostream>

typedef struct node /*ñòðóêòóðà-óçåë*/
{
    int data; //ïîëå ñ äàííûìè
    struct node* next; //óêàçàòåëü íà ñëåäóþùèé
} node;

class single_linked_list
{
public:
    virtual int Push(const int e) = 0;
    virtual int Pop(int* e) = 0;
    virtual const int& GetFront() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual int Size() = 0;
    virtual single_linked_list& operator = (const single_linked_list& List) = 0;
    friend std::ostream& operator << (std::ostream& stream, single_linked_list& l)
    {
        l.Print(stream);
        return stream;
    }
    friend std::istream& operator >> (std::istream& stream, single_linked_list& l)
    {
        int e;
        stream >> e;
        l.Push(e);
        return stream;
    }

protected:
    virtual void Print(std::ostream& stream) const = 0;
    node* top; //óêàçàòåëü íà âåðøèíó ñòåêà
};

#endif // LIST_H_INCLUDED
#pragma once
