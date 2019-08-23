#include "node_list.h"
#include <iostream>

template <typename T>
ListNode<T>::ListNode() : prev_(this), next_(this) {
  std::cout << "ListNode()..." << '\n';
}

template <typename T>
ListNode<T>::~ListNode() {
  std::cout << "~ListNode()..." << '\n';
  Remove();
}

template <typename T>
void ListNode<T>::Remove() {
  prev_->next_ = next_;
  next_->prev_ = prev_;
  prev_ = this;
  next_ = this;
}

template <typename T>
bool ListNode<T>::IsEmpty() const {
  return prev_ == this;
}

template <typename T, ListNode<T> (T::*M)>
ListHead<T, M>::Iterator::Iterator(ListNode<T>* node) : node_(node) {}

template <typename T, ListNode<T> (T::*M)>
T* ListHead<T, M>::Iterator::operator*() const {
  return ContainerOf(M, node_);
}

template <typename T, ListNode<T> (T::*M)>
const typename ListHead<T, M>::Iterator&
ListHead<T, M>::Iterator::operator++() {
  node_ = node_->next_;
  return *this;
}

template <typename T, ListNode<T> (T::*M)>
bool ListHead<T, M>::Iterator::operator!=(const Iterator& that) const {
  return node_ != that.node_;
}

template <typename T, ListNode<T> (T::*M)>
ListHead<T, M>::~ListHead() {
  while (IsEmpty() == false)
    head_.next_->Remove();
}

template <typename T, ListNode<T> (T::*M)>
void ListHead<T, M>::PushBack(T* element) {
  ListNode<T>* that = &(element->*M);
  head_.prev_->next_ = that;
  that->prev_ = head_.prev_;
  that->next_ = &head_;
  head_.prev_ = that;
}

template <typename T, ListNode<T> (T::*M)>
void ListHead<T, M>::PushFront(T* element) {
  ListNode<T>* that = &(element->*M);
  head_.next_->prev_ = that;
  that->prev_ = &head_;
  that->next_ = head_.next_;
  head_.next_ = that;
}

template <typename T, ListNode<T> (T::*M)>
bool ListHead<T, M>::IsEmpty() const {
  return head_.IsEmpty();
}

template <typename T, ListNode<T> (T::*M)>
T* ListHead<T, M>::PopFront() {
  if (IsEmpty())
    return nullptr;
  ListNode<T>* node = head_.next_;
  node->Remove();
  return ContainerOf(M, node);
}

template <typename T, ListNode<T> (T::*M)>
typename ListHead<T, M>::Iterator ListHead<T, M>::begin() const {
  return Iterator(head_.next_);
}

template <typename T, ListNode<T> (T::*M)>
typename ListHead<T, M>::Iterator ListHead<T, M>::end() const {
  return Iterator(const_cast<ListNode<T>*>(&head_));
}

template <typename Inner, typename Outer>
constexpr uintptr_t OffsetOf(Inner Outer::*field) {
  return reinterpret_cast<uintptr_t>(&(static_cast<Outer*>(0)->*field));
}

template <typename Inner, typename Outer>
ContainerOfHelper<Inner, Outer>::ContainerOfHelper(Inner Outer::*field,
                                                   Inner* pointer)
    : pointer_(
        reinterpret_cast<Outer*>(
            reinterpret_cast<uintptr_t>(pointer) - OffsetOf(field))) {}

template <typename Inner, typename Outer>
template <typename TypeName>
ContainerOfHelper<Inner, Outer>::operator TypeName*() const {
  return static_cast<TypeName*>(pointer_);
}

template <typename Inner, typename Outer>
inline ContainerOfHelper<Inner, Outer> ContainerOf(Inner Outer::*field,
                                                   Inner* pointer) {
  return ContainerOfHelper<Inner, Outer>(field, pointer);
}
