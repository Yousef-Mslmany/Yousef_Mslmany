#pragma once
using namespace std;

template <class T>
class clsDblLinkedList
{
private:
    int _Size = 0;

public:
    class Node
    {
    public:
        T Value;
        Node* Next;
        Node* Prev;
    };

    Node* Head = NULL;

    void InsertAtBeginning(T Value)
    {
        Node* New_Node = new Node();
        New_Node->Value = Value;
        New_Node->Next = Head;
        New_Node->Prev = NULL;

        if (Head != NULL)
        {
            Head->Prev = New_Node;
        }
        Head = New_Node;

        _Size++;
    }

    void PrintList()
    {
        Node* Current = Head;

        while (Current != NULL)
        {
            cout << Current->Value << " ";
            Current = Current->Next;
        }
        cout << "\n";

    }

    Node* Find(T Value)
    {
        Node* Current = Head;
        while (Current != NULL)
        {
            if (Current->Value == Value)
                return Current;

            Current = Current->Next;
        }

        return NULL;
    }

    void InsertAfter(Node*& Current, T Value)
    {
        Node* New_Node = new Node();
        New_Node->Value = Value;
        New_Node->Next = Current->Next;
        New_Node->Prev = Current;
        if (Current->Next != NULL)
            Current->Next->Prev = New_Node;
       
        Current->Next = New_Node;
        _Size++;
    }

    void InsertAtEnd(T Value)
    {
        Node* New_Node = new Node();
        New_Node->Value = Value;
        New_Node->Next == NULL;

        if (Head == NULL)
        {
            New_Node->Prev = NULL;
            Head = New_Node;
        }
        else
        {
            Node* Current = Head;
            while (Current->Next != NULL)
            {
                Current = Current->Next;
            }

            Current->Next = New_Node;
            New_Node->Prev = Current;
        }
        _Size++;
    }

    void DeleteNode(Node* NodeToDelete)
    {
        if (Head == NULL || NodeToDelete == NULL)
            return;

        if (Head == NodeToDelete)
            Head = NodeToDelete->Next;

        if (NodeToDelete->Next != NULL)
            NodeToDelete->Next->Prev = NodeToDelete->Prev;

        if (NodeToDelete->Prev != NULL)
            NodeToDelete->Prev->Next = NodeToDelete->Next;

        delete NodeToDelete;
        _Size--;
        return;
    }

    void DeleteFirstNode()
    {
        if (Head == NULL)
            return;

        Node* temp = Head;
        Head = Head->Next;


        if (Head != NULL)
            Head->Prev = NULL;

        delete temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (Head == NULL)
            return;

        if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
            return;
        }

        Node* Current_Node = Head;

        //We need find the node before last node.
        while (Current_Node->Next->Next != NULL)
        {
            Current_Node = Current_Node->Next;
        }

        Node* Temp = Current_Node->Next;

        Current_Node->Next = NULL;
        delete Temp;
        _Size--;
    }

    int Size()
    {
        if (_Size < 0)
            _Size = 0;

        return _Size;
    }

    bool IsEmpty()
    {
        return !_Size;
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {

        Node* Current = Head;
        Node* Temp = nullptr;
        while (Current != nullptr)
        {
            Temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = Temp;
            Current = Current->Prev;
        }
        if (Temp != nullptr)
        {
            Head = Temp->Prev;
        }
    }

    Node* GetNode(T Index)
    {
        int Counter = 0;

        if (Index > _Size - 1 || Index < 0)
            return NULL;

        Node* Current = Head;

        while (Current != NULL && (Current->Next != NULL))
        {
            if (Counter == Index)
                break;

            Current = Current->Next;
            Counter++;
        }

        return Current;
    }

    T GetItem(T Index)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->Value;
    }

    bool UpdateItem(T Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->Value = NewValue;
            return true;
        }
        else
            return false;
    }

    bool InsertAfter(T Index, T Value)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, Value);
            return true;
        }
        else
            return false;
        
    }


};