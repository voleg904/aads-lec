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
  ps -> next = ps -> next -> next;
  if (ps -> next -> next)
  {
    ps -> next -> next -> prev = ps;
  }
  delete ps -> next;
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
    f(curr->val);
    curr = curr->next;
  }
  f(curr -> val);
}

