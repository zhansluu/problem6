#ifndef QUEUE_B_H_INCLUDED
#define QUEUE_B_H_INCLUDED
#include "list_b.h"

template <class T>
class Queue: public single_linked_list<T>
{
public:
    Queue () : top(nullptr), tail(nullptr) {};          // Конструктор по умолчанию

    Queue (Queue&& q) : top(q.top), tail(q.tail) {}  //Конструктор перемещения

    Queue (const Queue& q) : top (nullptr), tail (nullptr) //Конструктор копирования
    {
        node<T> *t = q.top;
        while (t != nullptr)
        {
            node<T> *n = new node<T>;

            n->data = t->data;
            n->next = nullptr;
            if (top == nullptr)
                top = n;
            else tail->next = n;
            tail = n;
            t = t->next;
        }
    }

    ~Queue()
    {
        while(!IsEmpty())
            Pop(nullptr);
    }

    void Free()
    {
        while(!this->Pop(nullptr));
    }

    Queue& operator = (const Queue& s)
    {
        if (this == &s) return *this;

        (*this).Free(); //<=> Free();

        node<T> *t = s.top;

        while (t != nullptr)
        {
            (*this).Push(t->data);
            t = t->next;
        }
        return *this;
    }

    Queue& operator = (const Queue&& q)
    {
        node<T> *t = q.top;

        while (t != nullptr)
        {
            (*this).Push(t->data);
            t = t->next;
        }

        return *this;
    }

    single_linked_list<T>& operator = (const single_linked_list<T>& q) override
    {
        if (&q == this) return *this;
        const Queue& queu = dynamic_cast<const Queue&>(q);
        node<T> *t = queu.top;
        while (t != nullptr)
        {
            node<T> *n = new node<T>;

            n->data = t->data;
            n->next = nullptr;
            if (queu.top == nullptr)
            {
                top = n;
            }
            else tail->next = n;
            tail = n;
            t = t->next;
        }
        return *this;
    }

    int Push (const T e) override
    {
        node<T>* n = new node<T>; //выделение памяти на новый узел

        n->data = e; //заполнение узла
        n->next = nullptr; //в новом узле указатель на соседа устанавливается на nullptr
        if (top == nullptr)
            top = n; //указатель на вершину переносится на новый элемент
        else
            tail->next = n; //указатель на соседа хвоста устанавливается на новый элемент

        tail = n;

        return 0;
    }

    int Pop(T *e) override
    {
        struct node<T> *t = top; //запоминаем указатель на узел в вершине
        if (!t) return 1;

        top = t->next;
        if (e)
            *e = t->data; //прочитываем данные из вершины, если указатель е не nullptr
        delete t;

        if (top == nullptr)
            tail = nullptr;
        return 0;
    }

    bool IsEmpty() const override
    {
        return top == nullptr;
    }

    enum ERR_CODE {OUT_OF_RANGE};

    const T& GetFront() const override
    {
        if (this->IsEmpty())
            throw OUT_OF_RANGE;
        return top->data;
    }

    int Size() override
    {
        int q_size = 0;
        if (top == nullptr)
            return 0;
        struct node<T> *tmp = top;
        q_size++;

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            q_size++;
        }
        return q_size;
    }
protected:
    void Print(std::ostream &stream) const override
    {
        struct node<T> *tmp = top;
        stream << tmp->data << ' ';

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            stream << tmp->data << ' ';
        }
        stream << std::endl;
    }

private:
    node<T>* top; //указатель на голову очереди
    node<T>* tail; //указатель на хвост очереди

};

#endif // QUEUE_B_H_INCLUDED
