#ifndef LIST_HPP
#define LIST_HPP
#include <iterator>
#include <stdexcept>
#include "node.hpp"

namespace smolyakov
{
  template<typename T>
  class List
  {
  public:
    class Iterator;
    class ConstIterator;

    List();
    List(const List<T>& other);
    List(List<T>&& other);
    ~List();

    T operator [] (const size_t index);
    void pushFront(const T& value);
    void pushBack(const T& value);
    void popFront(const T& value);
    void popBack(const T& value);
    void clear();
    void swap(size_t value1Index, size_t value2Index);

    Iterator begin();
    Iterator end();
    ConstIterator constBegin();
    ConstIterator constEnd();

  private:
    size_t size_;
    Node<T>* head_;
    Node<T>* tail_;
  };

  template<typename T>
  class List<T>::Iterator : public std::iterator<std::forward_iterator_tag, T>
  {
  public:
    Iterator();
    Iterator(const Iterator& other) = default;
    ~Iterator() = default;
  };

  template<typename T>
  class List<T>::ConstIterator : public std::iterator<std::forward_iterator_tag, T>
  {
  public:
    ConstIterator();
    ConstIterator(const ConstIterator& other) = default;
    ~ConstIterator() = default;
  };
}

template<typename T>
smolyakov::List<T>::List()
  : size_(0), head_(nullptr), tail_(nullptr) {}

template<typename T>
smolyakov::List<T>::List(const List<T>& other)
  : size_(other.size_), head_(other.head_), tail_(other.tail_)
{
  if (size_ > 0)
  {
    head_ = new Node<T>(other.head_->value);
    Node<T>* tmpNode = other.head_;
    tail_ = head_;
    while(tmpNode->next != nullptr)
    {
      tail_->next = new Node<T>(tmpNode->next->value);
      tail_ = tail_->next;
      tmpNode = tmpNode->next;
    }
  }
}

template<typename T>
smolyakov::List<T>::List(List<T>&& other)
  : size_(other.size_), head_(other.head_), tail_(other.tail_)
{
  other.size_ = 0;
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

template<typename T>
smolyakov::List<T>::~List<T>()
{
  clear();
}

template<typename T>
T smolyakov::List<T>::operator [] (const size_t index)
{
  Node<T>* node = head_;
  size_t i = 0;
  while (node != nullptr)
  {
    if (i == index)
    {
      return node->value;
    }
    node = node->next;
    i++;
  }
  throw std::out_of_range("Given index was out of the list's range");
}












#endif
