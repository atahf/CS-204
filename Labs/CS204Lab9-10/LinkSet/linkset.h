/*
Tapestry Class Code
Modified on 18.04.2012 by Albert Levi, Gizem Gezici

***Problem: Probably in old version of Visual Studio the code was working;
yet in Visual Studio 2012, Visual Studio 2010 and also 2008 it cannot be compiled. 

***Solution: If the node is declared inside of the LinkedList class
Then it is necessary to say that which class the node belongs to as:
LinkSet<T>::Node and you have to write 'typename' before this declaration.
Also in the member functions of the class you should do the same thing.
In this example findNode and clone member functions suit this case.
*/


#ifndef _LINKSET_H
#define _LINKSET_H

template <class T> class LinkSetIterator;

template <class T>
class LinkSet
{
  public:
    LinkSet();
    
    // methods for deep copy 
    LinkSet(const LinkSet& set);
    const LinkSet& operator =(const LinkSet& set);
    ~LinkSet();
    
    // accessors   
    bool contains(const T& s) const;  // true iff s in set
    int  size()               const;  // # elements in set
    
    // mutators    
    void insert(const T& s);  // add to set
    void erase(const T& s);   // remove from set
    void clear();            // delete all elements
    
    friend class LinkSetIterator<T>;
    
  private:
  
    struct Node
    {   T info;
        Node * next;
        Node(const T& s, Node * link)
          : info(s), next(link)
        { }
    };    
    Node * findNode(const T& s) const;  // helper
    void   reclaimNodes(Node * ptr);    // delete/reclaim
    Node * clone() const;               // copy list
    
    Node * myFirst;
    int    mySize;
};

template <class T>
class LinkSetIterator
{

  public:

    LinkSetIterator(const LinkSet<T>& lset)
      : mySet(lset),
        myCurrent(0)
     { }
     
     void Init()
     {  
		 myCurrent = mySet.myFirst->next;  // first node
     }

     bool HasMore() const
     {   
		 return myCurrent != 0;
     }

     T Current() const
     {  
		 return myCurrent->info;
     }

     void Next()
     {   
		 myCurrent = myCurrent->next;
     }

  private:
    typedef typename LinkSet<T>::Node Node;
    const LinkSet<T>& mySet;
    Node *         myCurrent;

};

#include "linkset.cpp" // cpp is included here

#endif