#include <iostream>

template <class T>
struct BiList
{
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

template <class T>
BiList<T>* add(BiList<T>* ps, const T& d)
{
  BiList<T>* l = new BiList<T>{d, ps -> next, ps}; 
  if (ps -> next)
  {
    ps -> next -> prev = l;
  }
  ps -> next = l;
  return ps;
}

template <class T>
BiList<T>* insert(BiList<T>* node, const T& d)
{
  BiList<T>* l = new BiList<T>{d, node -> next, node}; 
  if (node -> next)
  {
    node -> next -> prev = l;
  }
  node -> next = l;
  return l;
}

template <class T>
BiList<T>* cut (BiList<T>* ps) noexcept
{
  BiList<T>* curr = ps -> next;
  ps -> next = curr -> next;
  if (curr -> next)
  {
    curr -> next -> prev = ps;
  }
  delete curr; 
  return ps;
}

template <class T>
BiList<T>* erase(BiList<T>* h) noexcept
{
  return cut(h);
}

template <class T>
BiList<T>* clear(BiList<T>* ps) noexcept
{
  while (ps -> next)
  {
    erase(ps);
  }
  return ps;
}

template <class T, class F>
F traverse(F f, BiList<T>* ps, BiList<T>* e)
{
  BiList<T>* curr = ps -> next;
  while (curr != nullptr && curr != e)
  {
    f(curr -> val);
    curr = curr -> next;
  }
  return f;
}

template <class T>
BiList<T>* convert(T* arr, size_t s)
{
  BiList<T>* ps = new BiList<T>{T(), nullptr, nullptr};
  try
  {
    BiList<T>* curr = add(ps, arr[0]);
  }
  catch(...)
  {
    delete ps;
    throw;
  }
  for (size_t i = 1; i < s; i++)
  {
    try
    {
      BiList<T>* curr = add(curr, arr[i]);
    }
    catch(...)
    {
      clear(ps);
      delete ps;
      throw;
    }
  }
  delete[] arr;
  return ps;
}
