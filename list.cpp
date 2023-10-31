#include <iostream>
#include <stdexcept>
#include "list.h"
using namespace std;

List::List()
{
    size=0;
    sentinel_head= new Node(true);
    sentinel_head->prev=nullptr;
    sentinel_tail= new Node(true);
    sentinel_tail->next=nullptr;
    sentinel_head->next=sentinel_tail;
    sentinel_tail->prev=sentinel_head;
};
List::~List()
{
    delete this;
}
void List::insert(int v)
{
    try{
    Node *n = new Node(v,sentinel_tail,sentinel_tail->prev);
    sentinel_tail->prev->next=n;
    sentinel_tail->prev=n;
    size=size+1;
    }
    catch(bad_alloc){
        throw runtime_error("Out of Memory");
    };

};

int List::delete_tail()
{
    Node*result = sentinel_tail->prev;
    if (result == sentinel_head)
    {
        throw std::runtime_error("Empty Stack");
    }
    else
    {
        int res = result->get_value();
        sentinel_tail->prev=result->prev;
        result->prev->next=sentinel_tail;
        size=size-1;
        return res;
        
    }
};

int List::get_size()
{
    return size;
};

Node *List::get_head()
{
    return sentinel_head;
};



