#include <iostream>
#include <stdexcept>
#include "stack_a.h"
using namespace std;
// YOU HAVE REMOVED PRAGMA ONCE SO IF ANY ERROR CHECK FOR THAT
/* PART A */
/* Stacks using Fixed Size Arrays */

Stack_A::Stack_A()
{
    size = 0;
}
void Stack_A::push(int data)
{
    if (size == 0)
    {
        stk[0] = data;
        size = size + 1;
    }
    else if (size >= 1024)
    {
        throw std::runtime_error("Stack Full");
    }
    else
    {
        stk[size] = data;
        size = size + 1;
    }
};

int Stack_A::pop()
{
    if (size == 0)
    {
        throw std::runtime_error("Empty Stack");
    }
    else
    {
        int result = stk[size - 1];
        int *p = &stk[size - 1];
        p = nullptr;
        size = size - 1;
        return result;
    }
};

int Stack_A::get_element_from_top(int idx)
{
    if (idx >= size)
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        int result = stk[size - 1 - idx];
        return result;
        ;
    }
};

int Stack_A::get_element_from_bottom(int idx)
{
    if (idx >= size)
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        int result = stk[idx];
        return result;
    }
};

void Stack_A::print_stack(bool top_or_bottom)
{
    if (top_or_bottom == 1)
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[size - 1 - i] << endl;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[i] << endl;
        }
    }
};

int Stack_A::add()
{
    if ((size == 0) || (size == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk[size - 1];
        int res2 = stk[size - 2];
        int *p1 = &stk[size - 1];
        int *p2 = &stk[size - 1];
        p1 = nullptr;
        p2 = nullptr;
        size = size - 2;
        int result = res1 + res2;
        stk[size] = result;
        size = size + 1;
        return result;
    }
};

int Stack_A::subtract()
{
    if ((size == 0) || (size == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk[size - 1];
        int res2 = stk[size - 2];
        int *p1 = &stk[size - 1];
        int *p2 = &stk[size - 1];
        p1 = nullptr;
        p2 = nullptr;
        size = size - 2;
        int result = res2 - res1;
        stk[size] = result;
        size = size + 1;
        return result;
    }
};

int Stack_A::multiply()
{
    if ((size == 0) || (size == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk[size - 1];
        int res2 = stk[size - 2];
        int *p1 = &stk[size - 1];
        int *p2 = &stk[size - 1];
        p1 = nullptr;
        p2 = nullptr;
        size = size - 2;
        int result = res1 * res2;
        stk[size] = result;
        size = size + 1;
        return result;
    }
};

int Stack_A::divide()
{
    if ((size == 0) || (size == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk[size - 1];
        int res2 = stk[size - 2];
        int *p1 = &stk[size - 1];
        int *p2 = &stk[size - 1];
        p1 = nullptr;
        p2 = nullptr;
        size = size - 2;
        if (res1 == 0)
        {
            throw std::runtime_error("Divide by Zero Error");
        }
        else
        {
            if (res1 * res2 < 0)
            {
                int result = res2 / res1 - 1;
                stk[size] = result;
                size = size + 1;
                return result;
            }
            else
            {
                int result = res2 / res1;
                stk[size] = result;
                size = size + 1;
                return result;
            }

            
        }
    }
};

int *Stack_A::get_stack()
{
    int *p;
    p = &stk[0];
    return p;
}; // Get a pointer to the array

int Stack_A::get_size()
{
    return size;
}; // Get the size of the stack
