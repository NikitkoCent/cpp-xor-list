#ifndef XORLIST_XOR_LIST_H
#define XORLIST_XOR_LIST_H

#include <initializer_list> // ::std::initializer_list
#include <memory>           // ::std::allocator

template <typename T, class TAllocator = ::std::allocator<T>>
class LinkedList
{
public:
    LinkedList();

    explicit LinkedList(const allocator_type &alloc);

    LinkedList(::std::initializer_list<T> il, const TAllocator &alloc);

    explicit LinkedList(::std::size_t n, const allocator_type &alloc = TAllocator());

    LinkedList(::std::size_t n, const_reference val, const allocator_type &alloc = TAllocator());

    LinkedList(const LinkedList &other);
    LinkedList(LinkedList &&other);

    virtual ~LinkedList();

    LinkedList& operator=(const LinkedList &right);
    LinkedList& operator=(LinkedList &&right);

    void swap(LinkedList &other);

    void push_back(const_reference data);
    void push_back(T &&data);

    void push_front(const_reference data);
    void push_front(T &&data);

    template <typename... Args>
    void emplace_back(Args&&... data);

    template <typename... Args>
    void emplace_front(Args&&... data);

    void pop_front();
    void pop_back();

    size_type size() const noexcept;
    bool empty() const noexcept;

    void clear();

    T& back() noexcept;
    const T& back() const noexcept;

    T& front() noexcept;
    const T& front() const noexcept;

    // Iterators and such
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    void sort() noexcept;

    template <class Compare>
    void sort(Compare comp) noexcept;

    iterator insert(const_iterator position, const_reference val);

    template <class InputIterator>
    iterator insert(const_iterator position, InputIterator first, InputIterator last);

    void reverse() noexcept;

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void resize(size_type n);
    void resize(size_type n, const_reference val);

    template <typename InputIterator>
    void assign(InputIterator first, InputIterator last);

    void assign(size_type n, const_reference val);
    void assign(::std::initializer_list<T> il);

    void splice(const_iterator position, LinkedList &x) noexcept;
    void splice(const_iterator position, LinkedList &x, const_iterator i) noexcept;
    void splice(const_iterator position, LinkedList &x, const_iterator first, const_iterator last) noexcept;

    template <typename BinaryPredicate>
    void unique(BinaryPredicate binary_pred);
    void unique();

    template <typename Compare>
    void merge(LinkedList &x, Compare comp) noexcept;
    void merge(LinkedList &x) noexcept;
};


#endif //XORLIST_XOR_LIST_H
