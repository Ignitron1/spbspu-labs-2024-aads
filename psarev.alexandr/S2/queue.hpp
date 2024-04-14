#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace psarev
{
  template < typename T >
  class Queue
  {
  public:
    Queue();
    Queue(const Queue& other);
    explicit Queue(const List< T >& dep);
    ~Queue() = default;

    Queue< T >& operator=(const Queue& other);

    T& getFront() const;
    T& getBack() const;

    void push(const T& data);
    void push(T&& data);
    void pop();

    size_t getSize();
    bool empty() const noexcept;
  private:
    List< T > depot;
  };
}

template < typename T >
void psarev::Queue< T >::Queue()
{
  depot(List< T >());
}

template < typename T >
void psarev::Queue< T >::Queue(const Queue& other)
{
  depot = other.depot;
}

template < typename T >
void psarev::Queue< T >::Queue(const List< T >& dep)
{
  depot(dep);
}

template < typename T >
psarev::Queue< T >& psarev::Queue< T >::operator=(const Queue& other)
{
  depot = other.dep;
}

template < typename T >
T& psarev::Queue< T >::getFront() const
{
  return depot.getFront();
}

template < typename T >
T& psarev::Queue< T >::getBack() const
{
  return depot.getBack();
}

template < typename T >
void psarev::Queue< T >::push(const T& data)
{
  depot.pushBack(data);
}

template < typename T >
void psarev::Queue< T >::push(T&& data)
{
  depot.pushBack(data);
}

template < typename T >
void psarev::Queue< T >::pop()
{
  depot.popFront(data);
}

template<typename T>
size_t psarev::Queue<T>::getSize()
{
  return depot.getSize();
}

template < typename T >
bool psarev::Queue< T >::empty() const noexcept
{
  return depot.empty();
}

#endif