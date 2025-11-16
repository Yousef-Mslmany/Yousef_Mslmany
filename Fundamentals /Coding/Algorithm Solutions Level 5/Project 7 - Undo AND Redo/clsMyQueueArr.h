#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
    clsDynamicArray <T> _MyList;

public:

    void push(T Item)
    {
        _MyList.InsertAtEnd(Item);
    }

    int Size()
    {
        return _MyList.Size();
    }

    T front()
    {
        return _MyList.GetItem(0);
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }

    T back()
    {
        return _MyList.GetItem((Size() - 1));
    }

    void pop()
    {
        _MyList.DeleteFirstItem();
    }

    void Print()
    {
        _MyList.PrintList();
    }

    T GetItem(int Index)
    {
        return _MyList.GetItem(Index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    void UpdateItem(int Index, T NewValue)
    {
        _MyList.SetItem(Index, NewValue);
    }

    void InsertAfter(int Index, T Value)
    {
        _MyList.InsertAfter(Index, Value);
    }

    void InsertAtFront(T Value)
    {
        _MyList.InsertAtBeginning(Value);
    }

    void InsertAtBack(T Value)
    {
        _MyList.InsertAtEnd(Value);
    }

    void Clear()
    {
        _MyList.Clear();
    }
};

