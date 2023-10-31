#include <iostream>
#include <stdexcept>
#include "stack_c.h"
using namespace std;

Stack_C ::Stack_C()
{
    stk = new List();
};

Stack_C ::~Stack_C()
{
    delete stk;
};

void Stack_C ::push(int data)
{
    stk->insert(data);
};

int Stack_C ::pop()
{
    return stk->delete_tail();
};

int Stack_C ::get_element_from_top(int idx)
{
    if (idx >= stk->get_size())
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        Node *n = stk->get_head();
        for (int i = 0; i <= stk->get_size() - 1 - idx; i++)
        {
            n = n->next;
        }
        int result = n->get_value();
        return result;
    }
};

int Stack_C ::get_element_from_bottom(int idx)
{
    if (idx >= stk->get_size())
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        Node *n = stk->get_head();
        for (int i = 0; i <= idx; i++)
        {
            n = n->next;
        }
        int result = n->get_value();
        return result;
    }
};

void Stack_C ::print_stack(bool top_or_bottom)
{
    if (top_or_bottom == 0)
    {
        Node *n = stk->get_head()->next;
        for (int i = 0; i < stk->get_size(); i++)
        {
            cout << n->get_value() << endl;
            n = n->next;
        }
    }
    else if (top_or_bottom == 1)
    {
        Node *n = stk->get_head()->next;
        for (int i = stk->get_size() - 1; i >= 0; i--)
        {
            cout << n->get_value() << endl;
            n = n->next;
        }
    }
};
int Stack_C ::add()
{
    if ((stk->get_size() == 0) || (stk->get_size() == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk->delete_tail();
        int res2 = stk->delete_tail();
        int result = res1 + res2;
        stk->insert(result);
        return result;
    }
};

int Stack_C ::subtract()
{
    if ((stk->get_size() == 0) || (stk->get_size() == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk->delete_tail();
        int res2 = stk->delete_tail();
        int result = res2 - res1;
        stk->insert(result);
        return result;
    }
};

int Stack_C ::multiply()
{
    if ((stk->get_size() == 0) || (stk->get_size() == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk->delete_tail();
        int res2 = stk->delete_tail();
        int result = res1 * res2;
        stk->insert(result);
        return result;
    }
};

int Stack_C ::divide()
{
    if ((stk->get_size() == 0) || (stk->get_size() == 1))
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int res1 = stk->delete_tail();
        int res2 = stk->delete_tail();
        if (res1 == 0)
        {
            throw std::runtime_error("Divide by Zero Error");
        }
        else
        {
            if (res1 * res2 < 0)
            {
                int result = res2 / res1 - 1;
                stk->insert(result);
                return result;
            }
            else
            {
                int result = res2 / res1;
                stk->insert(result);
                return result;
            }
        }
    }
};

List *Stack_C ::get_stack()
{
    return stk;
}; // Get a pointer to the linked list representing the stack

int Stack_C ::get_size()
{
    return stk->get_size();
}; // Get the size of the stack
