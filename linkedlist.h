#ifndef __LINKEDLIST_H__  
#define __LINKEDLIST_H__ 
#include <utility>
#include <algorithm>
#include <cassert>
#include <iostream> // Para operadores
#include "types.h"
using namespace std;

template <typename Node, typename MemberType>
void CreateBridge(Node *&rParent, Node *pNew, MemberType _pMember)
{
    Node *Node::*pMember = (Node *Node::*)_pMember;
    pNew->*pMember = rParent;
    rParent = pNew; 
}

template <typename T>
class NodeLinkedList
{
public:
  typedef T         Type;
private:
  typedef NodeLinkedList<T> Node;
  public:
  T       m_data;
  Node   *m_pNext;//
  public:
    NodeLinkedList(T data, Node *pNext = nullptr) 
        : m_data(data), m_pNext(pNext)
    {};

    T         getData()                {   return m_data;    }
    T        &getDataRef()             {   return m_data;    }

    void      setpNext(NodeLinkedList *pNext)  {   m_pNext = pNext;  }
    Node     *getpNext()               {   return getpNextRef();   }
    Node    *&getpNextRef()            {   return m_pNext;   }
};

// Iterador básico, sustituye a `general_iterator`
template <typename Container>
class forward_iterator {
public:
    using Node = typename Container::Node;

private:
    Container *m_pContainer;
    Node *m_pNode;

public:
    forward_iterator(Container *pContainer, Node *pNode) 
        : m_pContainer(pContainer), m_pNode(pNode) {}

    forward_iterator &operator++() {
        m_pNode = m_pNode ? m_pNode->getpNext() : nullptr;
        return *this;
    }

    bool operator!=(const forward_iterator &other) const {
        return m_pNode != other.m_pNode;
    }

    typename Node::Type &operator*() {
        return m_pNode->getDataRef();
    }
};

template <typename _T>
struct LLTraitAsc
{
    using  T         = _T;
    using  Node      = NodeLinkedList<T>;
    using  CompareFn = less<T>;
};

template <typename _T>
struct LLTraitDesc
{
    using  T         = _T;
    using  Node      = NodeLinkedList<T>;
    using  CompareFn = greater<T>;
};

template <typename Traits>
class LinkedList
{
public:
    using value_type = typename Traits::T;
    using Node       = typename Traits::Node;
    using CompareFn  = typename Traits::CompareFn;
    using iterator   = forward_iterator<LinkedList>;

protected:
    Node *m_pHead = nullptr, *m_pTail = nullptr;
    size_t m_size = 0;
    CompareFn Compfn;

public: 
    size_t size()  const       { return m_size;       }
    bool   empty() const       { return size() == 0;  }

    LinkedList() {}

    void insert(value_type &elem) { insert_forward(elem);  }

    value_type &operator[](size_t pos)
    {
        assert(pos < size());
        Node *pTmp = m_pHead;
        for (size_t i = 0; i < pos; ++i)
            pTmp = pTmp->getpNext();
        return pTmp->getDataRef();
    }

    iterator begin() { return iterator(this, m_pHead); }
    iterator end()   { return iterator(this, nullptr); }

    void push_front(value_type elem)
    {
        Node *pNew = CreateNode(elem);
        pNew->setpNext(m_pHead);
        m_pHead = pNew;
        ++m_size;
        if (m_size == 1)
            m_pTail = pNew;
    } 

    void push_back(value_type elem)
    {
        Node *pNew = CreateNode(elem, nullptr);
        if (m_pTail)
            m_pTail->setpNext(pNew);
        m_pTail = pNew;
        if (!m_pHead)
            m_pHead = pNew;
        ++m_size;
    }

    void print() const
    {
        Node *current = m_pHead;
        while (current)
        {
            cout << current->getData() << " ";
            current = current->getpNext();
        }
        cout << endl;
    }

protected:
    Node **findPrev(value_type &elem) { return findPrev(m_pHead, elem); }

    Node **findPrev(Node *&rpPrev, value_type &elem)
    {   
        if (!rpPrev || Compfn(elem, rpPrev->getData()))
            return &rpPrev; // Retorna la direccion del puntero que me apunta
        return findPrev((Node *&)rpPrev->getpNextRef(), elem);
    }

    Node *CreateNode(value_type &data, Node *pNext = nullptr) { return new Node(data, pNext); }

    Node **insert_forward(value_type &elem)
    {
        Node **pParent = findPrev(elem);
        Node *pNew = CreateNode(elem);
        ::CreateBridge(*pParent, pNew, &Node::m_pNext);
        if (!pNew->getpNext())
            m_pTail = pNew;
        return pParent;
    }

public:
    value_type PopHead()
    {
        if (m_pHead)
        {
            Node *pNode = m_pHead;
            value_type data = pNode->getData();
            m_pHead = m_pHead->getpNext();
            delete pNode;
            --m_size;
            if (!m_size) m_pTail = nullptr;
            return data;
        }
        throw runtime_error("La lista está vacía");
    }

    friend ostream &operator<<(ostream &os, const LinkedList &list)
    {
        Node *current = list.m_pHead;
        while (current)
        {
            os << current->getData() << " -> ";
            current = current->getpNext();
        }
        return os << "null";
    }
};

#endif
