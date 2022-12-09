#ifndef LIST_H_INCLUDED
/*Создать абстрактный базовый класс "односвязный список" ((a) - целых чисел, (б) - шаблонный), имеющий абстрактные методы
1) Push
2) Pop
3) GetFront
4) IsEmpty
5) Size
6) Print (защищенный)
7) Операцию присваивания из ссылки на "список"
и внутренний тип node (защищенный), реализовать перегрузку операции вывода (<< - через Print) и ввода (>> - через Push).

Реализовать конкретные классы Стек и Очередь, имеющие необходимые конструкторы пустого списка, копирования, перемещения,
операции присваивания и присваивания по перемещению из ссылки на себя *и ссылки на фигуру
(копирование должно работать за O(1) и один проход списка, IsEmpty - за O(1)), реализацию абстрактных методов.*/

#define LIST_H_INCLUDED
#include <iostream>

typedef struct node /*структура-узел*/
{
    int data; //поле с данными
    struct node* next; //указатель на следующий
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
    node* top; //указатель на вершину стека
};

#endif // LIST_H_INCLUDED
#pragma once
