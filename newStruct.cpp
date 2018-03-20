#include <iostream>

struct LinkNode
{
    LinkNode(char cData,LinkNode *pNext)
    {
       data = cData;
       next = pNext;
     }

    char data;
    LinkNode *next;
};

int main (int argc, char** argv) {
    LinkNode  *ptr = new LinkNode('c', 0 );
    std::cout<< ptr->data<< std::endl;
    delete ptr;

    return 0;

}
