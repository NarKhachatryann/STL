#include <iterator>

template <typename T>
class iterator {
public:
    iterator(node* ptr) : current(ptr) {}
    
    T& operator*() const {
        return current->data;
    }

    T* operator->() const {
        return &(current->data);
    }

    bool operator!=(const iterator& other) const {
        return current != other.current;
    }

    bool operator==(const iterator& other) const {
        return current == other.current;
    }

    iterator& operator++() {
        current = current->next;
        return *this;
    }

    iterator operator++(int) {
        iterator temp = *this;
        current = current->next;
        return temp;
    }

private:
    node* current;
};