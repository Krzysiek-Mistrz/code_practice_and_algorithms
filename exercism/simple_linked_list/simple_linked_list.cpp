#include "simple_linked_list.h"
#include <stdexcept>


namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    Element* new_elem = new Element(entry);
    new_elem->next = head;
    head = new_elem;
    ++current_size;
}

int List::pop() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }

    int result = head->data;
    Element* old_head = head;
    head = head->next;
    delete old_head;
    --current_size;
    return result;
}

void List::reverse() {
    Element* prev{nullptr};
    Element* current{head};
    Element* next{nullptr};

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

List::~List() {
    while (head != nullptr) {
        auto next{head->next};
        delete head;
        head = next;
    }
}

}  // namespace simple_linked_list
