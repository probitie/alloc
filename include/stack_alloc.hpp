#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include <cstddef>

/// @brief allocates memory on a preserved buffer
/// @details it is theoretically faster than malloc but it does not control alighnment, error handling, etc
class stack_allocator_t {
public:

    /// @brief preserves its buffer
    /// @param size max size the allocator should operate
    stack_allocator_t(size_t size);
    ~stack_allocator_t();

    /// @brief fast allocation
    /// @param size size of allocated space, should be less than max size
    /// @return pointer to allocated space
    void* allocate(size_t size);

    /// @brief cleans up the WHOLE buffer of this stack
    void deallocate();

private:
    char* start_;
    char* current_;
    size_t size_;
};

#endif
