#include "../include/stack_alloc.hpp"
#include <gtest/gtest.h>

TEST(StackAllocatorTest, SuccessfulAllocation) {
    stack_allocator_t allocator(1024);

    void* memory = allocator.allocate(100);
    EXPECT_NE(memory, nullptr);
}

TEST(StackAllocatorTest, FailedAllocation) {
    stack_allocator_t allocator(1024);

    void* memory = allocator.allocate(2000);
    EXPECT_EQ(memory, nullptr);
}

TEST(StackAllocatorTest, DeallocateAndSuccessfulAllocation) {
    stack_allocator_t allocator(1024);

    void* memory = allocator.allocate(100);
    allocator.deallocate();
    memory = allocator.allocate(1000);

    EXPECT_NE(memory, nullptr);
}
