#include <iostream>
#include <iterator>

#ifndef DEQUE_H
#define DEQUE_H

#define MAX 100

template<typename Deque>
class DequeIterator {
public:
    using ValueType = typename Deque::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
private:
    PointerType ptr_;
public:
    DequeIterator(PointerType ptr)
        : ptr_(ptr) {}
    
    DequeIterator& operator++() { // Prefix increment
        ptr_++;
        return *this;
    }

    DequeIterator operator++(int) {
        DequeIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    DequeIterator& operator--() { // Prefix increment
        ptr_--;
        return *this;
    }

    DequeIterator operator--(int) {
        DequeIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index) {
        return *(ptr_ + index);
    }

    PointerType operator->() {
        return ptr_;
    }

    ReferenceType operator*() {
        return *ptr_;
    }

    bool operator==(const DequeIterator& other) const {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const DequeIterator& other) const {
        return !(*this == other);
    }
};

template<typename T>
class Deque {
public:
    using ValueType = T;
    using Iterator = DequeIterator<Deque<T>>;
private:
    T deque_[MAX] = {0};
    int front_;
    int rear_;
    int size_;
    void insertInto(const int& position, const T& key) {
        for (int i = size_ + 1; i > position; --i) {
            deque_[i] = deque_[i-1];
        }
        ++size_;
        deque_[position - 1] = key;
    }
public:
    Iterator begin() {
        return Iterator(&deque_[0]);
    }

    Iterator end() {
        return Iterator(&deque_[size_]);
    }

    Iterator set(int index) {
        return Iterator(&deque_[index -1]);
    }

    bool empty() {
        return (this->begin() == this->end());
    }

    Iterator insert(Iterator pos, const ValueType& key);
    Iterator erase(Iterator pos);
    Iterator erase(Iterator begin, Iterator end);

    void swap(Deque<ValueType>& deque2) {
        if (this->sizeGet() != deque2.sizeGet()) {
            std::cout << "Error";
        } else {
            Deque<ValueType> tmp(this->sizeGet());
            tmp = *this;
            int i = 0;
            for (Iterator it = deque2.begin(); it != deque2.end(); ++it) {
                deque_[i] = *it;
                ++i;
            }
            deque2 = tmp;
        }
    }
    
    Deque(const int& size) : size_(size), front_(-1), rear_(0) {}
    ~Deque() = default;

    friend std::ostream& operator<<(std::ostream& os, Deque<T>& deque) {
        if (!deque.isEmpty()) {
            for (int i = deque.size_ - 1; i >= 0; --i) {
                std::cout << deque.deque_[i] << std::endl;
            }
            std::cout << std::endl;
        }
        else {
            os << "Empty" << std::endl;
        }
        return os;
    }

    Deque<T>& operator=(const Deque<T>& deque) {
        if (this == &deque) {
            return *this;
        }
        front_ = deque.front_;
        rear_ = deque.rear_;
        size_ = deque.size_;
        for (int i = 0; i < size_; ++i) {
            deque_[i] = deque.deque_[i];
        }
        return *this;
    }

    void insertFront(const T& data);
    void inserRear(const T& data);
    void deleteFront();
    void deleteRear();
    bool isFull() const;
    bool isEmpty() const;
    T getFront() const;
    T getRear() const;
    T sizeGet() const;
};

template<typename T>
bool Deque<T>::isFull() const {
    return ((front_ == 0 && rear_ == size_ - 1) || front_ == rear_ + 1);
}

template<typename T>
bool Deque<T>::isEmpty() const {
    return (front_ == -1);
}

template<typename T>
void Deque<T>::insertFront(const T& data) {
    if (isFull()) {
        std::cout << "Error! Overflow.\n" << std::endl;
        return;
    }

    if (front_ == -1) {
        front_ = 0;
        rear_ = 0;
    }

    else if (front_ == 0)
        front_ = size_ - 1;

    else
        front_ = front_ - 1;

    deque_[front_] = data;
}

template<typename T>
void Deque<T>::inserRear(const T& data) {
    if (isFull()) {
        std::cout << "Error! Overflow.\n" << std::endl;
        return;
    }

    if (front_ == -1) {
        front_ = 0;
        rear_ = 0;
    }

    else if (rear_ == size_ - 1)
        rear_ = 0;

    else
        rear_ = rear_ + 1;

    deque_[rear_] = data;
}

template<typename T>
void Deque<T>::deleteFront() {
    if (isEmpty()) {
        std::cout << "Error! Underflow\n" << std::endl;
        return ;
    }

    if (front_ == rear_) {
        front_ = -1;
        rear_ = -1;
    }
    else {
        if (front_ == size_ -1)
            front_ = 0;
        else
            front_ = front_ + 1;
    }
}


template<typename T>
void Deque<T>::deleteRear() {
    if (isEmpty()) {
        std::cout << "Error! Underflow\n" << std::endl ;
        return ;
    }
  
    if (front_ == rear_) {
        front_ = -1;
        rear_ = -1;
    }
    else if (rear_ == 0)
        rear_ = size_ - 1;
    else
        rear_ = rear_ - 1;
}

template<typename T>
T Deque<T>::getFront() const {
    if (isEmpty()) {
        std::cout << "Error! Underflow\n" << std::endl;
        return -1 ;
    }
    return deque_[front_];
}

template<typename T>
T Deque<T>::getRear() const {
    if(isEmpty() || rear_ < 0) {
        std::cout << "Error! Underflow\n" << std::endl;
        return -1 ;
    }
    return deque_[rear_];
}

template<typename T>
T Deque<T>::sizeGet() const {
    return size_;
}

#endif 