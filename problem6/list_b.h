#ifndef LIST_B_H_INCLUDED
#define LIST_B_H_INCLUDED

template <class T>
struct node /*структура-узел*/
{
    T data; //поле с данными
    struct node<T>* next; //указатель на следующий
};

template <class T>
class single_linked_list
{
public:
    virtual int Push(const T e) = 0;
    virtual int Pop(T* e) = 0;
    virtual const T& GetFront() const = 0;
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
        T e;
        stream >> e;
        l.Push(e);
        return stream;
    }

protected:
    virtual void Print(std::ostream& stream) const = 0;
    node<T>* top; //указатель на вершину стека
};


#endif // LIST_B_H_INCLUDED
#pragma once
