#ifndef STACK_B_H_INCLUDED
#define STACK_B_H_INCLUDED
#include "list_b.h"

template <class T>
class Stack : public single_linked_list<T>
{
public:
    Stack() : top(nullptr) {};          // ����������� �� ���������

    Stack(Stack&& s) : top(s.top) { s.top = nullptr; }  //����������� �����������

    Stack(const Stack& s) : top(new node<T>) //����������� �����������
    {
        node<T>* t = s.top;
        node<T>** n = &top;

        while (t != nullptr)
        {
            *n = new node<T>;

            (*n)->data = t->data;
            (*n)->next = nullptr;
            n = &((*n)->next);
            t = t->next;
        }
    }

    ~Stack()
    {
        while (!this->Pop(nullptr));
    }

    void Free()
    {
        while (!this->Pop(nullptr));
    }

    Stack& operator = (const Stack& s)
    {
        if (this == &s) return *this;

        Free(); //�������� ���� ��� ��������

        node<T>* t = s.top;
        node<T>** n = &top;

        while (t != nullptr)
        {
            *n = new node<T>;

            (*n)->data = t->data;
            (*n)->next = nullptr;
            n = &((*n)->next);
            t = t->next;
        }
        return *this;
    }

    Stack& operator = (Stack&& s)
    {
        node<T>* t = s.top;
        node<T>** n = &top;

        while (t != nullptr)
        {
            *n = new node<T>;

            (*n)->data = t->data;
            (*n)->next = nullptr;
            n = &((*n)->next);
            t = t->next;
        }
        return *this;
    }

    single_linked_list<T>& operator = (const single_linked_list<T>& s) override
    {
        if (&s == this) return *this;
        const Stack& stackk = dynamic_cast<const Stack&>(s);
        node<T>* t = stackk.top;
        node<T>** n = &top;

        while (t != nullptr)
        {
            *n = new node<T>;

            (*n)->data = t->data;
            (*n)->next = nullptr;
            n = &((*n)->next);
            t = t->next;
        }
        return *this;
    }

    int Push(const T e) override
    {
        node<T>* n = new node<T>;//��������� ������ �� ����� ����

        n->data = e; //���������� ����
        n->next = top; //� ����� ���� ��������� �� ������ ��������������� �� ���� � ������ � ������
        top = n; //��������� �� ������� ����������� �� ����� �������

        return 0;
    }

    int Pop(T* e) override
    {
        struct node<T>* t = top; //���������� ��������� �� ���� � �������
        if (!t) return 1;

        if (e)
            *e = t->data; //����������� ������ �� �������, ���� ��������� � �� nullptr
        top = top->next; // ��������� ������� ����������� �� ��������� �������, ������ ������� �� ������

        delete t;
        return 0;
    }

    bool IsEmpty() const override
    {
        return top == nullptr;
    }

    enum ERR_CODE { OUT_OF_RANGE };

    const T& GetFront() const override
    {
        if (this->IsEmpty())
            throw OUT_OF_RANGE;
        return top->data;
    }

    int Size() override
    {
        int s_size = 0;
        if (top == nullptr)
            return 0;
        struct node<T>* tmp = top;
        s_size++;

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            s_size++;
        }
        return s_size;
    }
protected:
    void Print(std::ostream& stream) const override
    {
        struct node<T>* tmp = top;
        stream << tmp->data << ' ';

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            stream << tmp->data << ' ';
        }
        stream << std::endl;
    }
private:
    node<T>* top; //��������� �� ������� �����
};

#endif // STACK_B_H_INCLUDED
#pragma once
