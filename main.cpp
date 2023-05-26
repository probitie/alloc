#include "include/stack_alloc.hpp"
#include <iostream>

#define CA_CHECK_NULLPTR(mem, bytes)\
    do{\
        if((mem) != nullptr) {\
                std::cout << "allocated "<< (bytes) <<" bytes\n";\
            } else {\
                std::cout << "failed to allocate "<< (bytes)<<" bytes\n";\
            }\
    } while (0)

int main() {
    stack_allocator_t stack_alloc(1024);

    void* myMemory = stack_alloc.allocate(100);
    CA_CHECK_NULLPTR(myMemory, 100);

    myMemory = stack_alloc.allocate(2000);
    CA_CHECK_NULLPTR(myMemory, 2000);

    stack_alloc.deallocate();

    myMemory = stack_alloc.allocate(1000);
    CA_CHECK_NULLPTR(myMemory, 1000);

    return 0;
}
