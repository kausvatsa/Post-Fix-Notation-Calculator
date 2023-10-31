#include <iostream>
#include <stdexcept>
#include "node.h"
using namespace std;

Node::Node(bool sentinel)
{
    if (sentinel = true)
    {
        is_sentinel = true;
    }
    else
    {
        is_sentinel = false;
    }
};
Node::Node(int v, Node *nxt, Node *prv)
{
    value = v;
    next = nxt;
    prev = prv;
};
bool Node::is_sentinel_node()
{
    return is_sentinel;
};
int Node::get_value()
{
    return value;
};
