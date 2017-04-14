/**
 * bst.h
 *  Implements a(n unbalanced) BST storing Key,Value pairs
 */
#ifndef BST_H
#define BST_H
#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/* -----------------------------------------------------
 * Regular Binary Tree Nodes
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
  class Node {
 public:
  Node (const KeyType & k, const ValueType & v, Node<KeyType, ValueType> *p)
    : _item(k, v)
   // the default is to create new nodes as leaves
    { _parent = p; _left = _right = NULL; }
  
  virtual ~Node()
  { }
  
  std::pair<const KeyType, ValueType> const & getItem () const
    { return _item; }
  
  std::pair<const KeyType, ValueType> & getItem ()
    { return _item; }
  
  const KeyType & getKey () const
  { return _item.first; }
  
  const ValueType & getValue () const
  { return _item.second; }
  
  /* the next three functions are virtual because AVL-Trees use AVL nodes, and for those, the
     getParent, getLeft, and getRight functions should return 
     AVL nodes, not just ordinary nodes.
   */
  
  virtual Node<KeyType, ValueType> *getParent () const
    { return _parent; }
  
  virtual Node<KeyType, ValueType> *getLeft () const
    { return _left; }
  
  virtual Node<KeyType, ValueType> *getRight () const
    { return _right; }
  
  
  void setParent (Node<KeyType, ValueType> *p)
  { _parent = p; }
  
  void setLeft (Node<KeyType, ValueType> *l)
  { _left = l; }
  
  void setRight (Node<KeyType, ValueType> *r)
  { _right = r; }
  
  void setValue (const ValueType &v)
  { _item.second = v; }
  
 protected:
  std::pair<const KeyType, ValueType> _item;
  Node <KeyType, ValueType> *_left, *_right, *_parent;
};

/* -----------------------------------------------------
 * Regular Binary Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class BinarySearchTree {
 protected:
  // Main data member of the class
  Node<KeyType, ValueType> *root;

 public:
  /**
   * Constructor
   */
  BinarySearchTree () { root = NULL; }

  /**
   * Destructor
   */
  ~BinarySearchTree () { deleteAll (root); }

  /**
   * Prints the entire tree structure in a nice format 
   */  
  void print () const
  { 
    printRoot (root);
    std::cout << "\n";
  }
    
  /**
   * An In-Order iterator
   */
  class iterator {
  public:
    /**
     * Initialize the internal members of the iterator
     */
    iterator(Node<KeyType,ValueType>* ptr){curr = ptr;}
    
    std::pair<const KeyType,ValueType>& operator*()
      { return curr->getItem();  }
    
    std::pair<const KeyType,ValueType>* operator->() 
      { return &(curr->getItem()); }
    
    /**
     * Checks if 'this' iterator's internals have the same value
     *  as 'rhs'
     */
    bool operator==(const iterator& rhs) const
    {
      if (curr == NULL && rhs.curr != NULL) 
      {
        return false;
      }
      else if (curr != NULL && rhs.curr == NULL)
      {
        return false;
      }
      else if (curr == NULL && rhs.curr == NULL)
      {
        return true;
      }
      else if (curr->getItem() == rhs.curr->getItem())
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    
    /**
     * Checks if 'this' iterator's internals have a different value
     *  as 'rhs'
     */
    bool operator!=(const iterator& rhs) const
    {
      if (curr == NULL && rhs.curr != NULL) 
      {
        return true;
      }
      else if (curr != NULL && rhs.curr == NULL)
      {
        return true;
      }
      else if (curr == NULL && rhs.curr == NULL)
      {
        return false;
      }
      else if (curr->getItem() != rhs.curr->getItem())
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    
    /**
     * Advances the iterator's location using an in-order sequencing
     */
    iterator& operator++()
    {
      if (curr == NULL)
      {
        return *this;
      }
      else
      {
        succesor();
        return *this;
      }
    }
    
  protected:
    Node<KeyType, ValueType>* curr;

  private:
    void succesor() 
    {
      // If there is no right subtree look up for successor
      if (curr->getRight() == NULL)
      {
        // keep moving up until you move up a left child
        Node<KeyType, ValueType>* temp = curr->getParent();
        while (temp != NULL)
        {
          if (temp->getLeft() == curr)
          {
            curr = temp;
            return;
          }
          else
          {
            temp = temp->getParent();
          }
        }
        curr = NULL;
      }
      else
      {
        // otherwise move all the way to the left of the right subtree
        curr = curr->getRight();
        if (curr->getLeft() != NULL)
        {
          curr = curr->getLeft();
        }
      }
    }

  };
  
  /**
   * Returns an iterator to the "smallest" item in the tree
   */
  iterator begin()
  {
    Node<KeyType, ValueType>* temp = root;
    if (temp == NULL)
    {
      return iterator(NULL);
    } 
    while (temp->getLeft() != NULL)
    {
      temp = temp->getLeft();
    }
    return iterator(temp);
  }

  /**
   * Returns an iterator whose value means INVALID
   */
  iterator end()
  {
    return iterator(NULL);
  }
  
 protected:
  /**
   * Helper function to find a node with given key, k and 
   * return a pointer to it or NULL if no item with that key
   * exists
   */
  Node<KeyType, ValueType>* internalFind(const KeyType& k) const 
  {
    Node<KeyType, ValueType> *curr = root;
    while (curr) {
      if (curr->getKey() == k) {
	return curr;
      } else if (k < curr->getKey()) {
	curr = curr->getLeft();
      } else {
	curr = curr->getRight();
      }
    }
    return NULL;
  }
  
  /**
   * Helper function to print the tree's contents (recursive, in-order scan)
   */
  void printRoot (Node<KeyType, ValueType> *r, std::ostream& output) const
  {
    if (r != NULL)
      {
      	printRoot (r->getLeft(), output);
      	output << r->getKey() << " " << r->getValue() << std::endl;
      	printRoot (r->getRight(), output);
      }
  }
  
  /**
   * Helper function to delete all the items
   */
  void deleteAll (Node<KeyType, ValueType> *r)
  {
    if (r != NULL)
      {
	deleteAll (r->getLeft());
	deleteAll (r->getRight());
	delete r;
      }
  }
};


#endif
