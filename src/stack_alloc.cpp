#include "stack_alloc.hpp"
#include <iostream>

stack_allocator_t::stack_allocator_t(size_t size) 
    : size_(size) 
{
    start_ = new char[size_];
    current_ = start_;
}

stack_allocator_t::~stack_allocator_t() {
    delete[] start_;
}

void* stack_allocator_t::allocate(size_t size) {
    if (current_ + size > start_ + size_) {

         // TODO this can lead to serious performance problems,
         // use buffered loging or error code instead
        std::cout << "allocator out of memory!\n";
        
        return nullptr;
    }

    void* result = current_;
    current_ += size;
    return result;
}

void stack_allocator_t::deallocate() {
    current_ = start_;
}
