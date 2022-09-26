/*
Tapestry Class Code
Modified on 18.04.2012 by Albert Levi, Gizem Gezici
*/
#include "linkset.h"

template <class T>
LinkSet<T>::LinkSet()
  : myFirst(new Node(T(),0)),
    mySize(0)
{
   // header node created
}

template <class T>
bool LinkSet<T>::contains(const T& s) const
{
    Node * temp = findNode(s);
    return temp != 0;
}
template <class T>
int LinkSet<T>::size() const
{
    return mySize;
}
template <class T>
void LinkSet<T>::insert(const T& s)
{
    if (! contains(s))
    {   myFirst->next = new Node(s,myFirst->next);
        mySize++;
    }
}
template <class T>
void LinkSet<T>::erase(const T& s)
{
    Node * temp = findNode(s);
    if (temp != 0)
    {   Node * removal = temp->next;
        temp->next = removal->next;
        delete removal;    // can we reuse this?
        mySize--;
    }
}

template <class T>
void LinkSet<T>::reclaimNodes(Node * ptr)
{
    if (ptr != 0)
    {   reclaimNodes(ptr->next);
        delete ptr;
    }
}
template <class T>
void LinkSet<T>::clear()
{
    reclaimNodes(myFirst->next);
    myFirst->next = 0;           // nothing in the set
    mySize = 0;
}

template <class T>
typename LinkSet<T>::Node * LinkSet<T>::findNode(const T& s) const
// post: returns pointer to node before s or NULL/0 if !contains(s)
{
    Node * list = myFirst; // list non-zero
    
    while (list->next != 0 && list->next->info != s)
    {   list = list->next;
    }
    if (list->next == 0) return 0;
    return list;
}

template <class T>
LinkSet<T>::LinkSet(const LinkSet<T>& set)
  : myFirst(new Node(T(),set.clone())),
    mySize(set.size())
{
    // initializer list made deep copy
}
template <class T> const LinkSet<T>&
LinkSet<T>::operator = (const LinkSet<T>& set)
{
    if (this != &set)
    {   reclaimNodes(myFirst->next);
        myFirst->next = set.clone();
        mySize = set.size();
    }
    return *this;
}

template <class T>
LinkSet<T>::~LinkSet()
{
    reclaimNodes(myFirst);
    myFirst = 0;
}
template <class T>
typename LinkSet<T>::Node * LinkSet<T>::clone() const
{
    Node front(T(),0);   // node, not pointer, anchors copy
    Node * last = &front;    // be wary of using address of operator!
    
    Node * temp = myFirst->next;
    while (temp != 0)
    {   last->next = new Node(temp->info,0);
        last = last->next;
        temp = temp->next;
    }
    return front.next;
}
