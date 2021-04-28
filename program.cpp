#include <iostream>
#include <fstream>
#include "program.h"
using namespace std;
namespace type_plants {

void tree::input(ifstream &ifst)
{

    string tmp_name = "";
    long tmp_age = 0;
    ifst >> tmp_name >> tmp_age;
    name = tmp_name;
    age = tmp_age;
}

void tree::output(ofstream &ofst)
{
    ofst << "It is tree named: " << name
         << " and it's age: " << age << endl;
}

void tree::multimethod(plant *other, ofstream &ofst)
{
    other->mm_tree(ofst);
}
void tree::mm_tree(ofstream &ofst)
{
    cout << "Tree and tree" << endl;
    ofst << "Tree and tree" << endl;
}
void tree::mm_bush(ofstream &ofst)
{
    cout << "Bush and tree" << endl;
    ofst << "Bush and tree" << endl;
}

void bush::input(ifstream &ifst)
{
    string tmp_name = "";
    int mnth = 0;
    ifst >> tmp_name >> mnth;
    m = month(mnth);
    name = tmp_name;
}

void bush::output(ofstream &ofst)
{
    cout << m + 1 << endl;
    ofst << "It is bush named: " << name
         << " and it's month flowering: " << m + 1 << endl;
}

void bush::multimethod(plant *other, ofstream &ofst)
{
    other->mm_bush(ofst);
}
void bush::mm_tree(ofstream &ofst)
{
    cout << "Tree and bush" << endl;
    ofst << "Tree and bush" << endl;
}
void bush::mm_bush(ofstream &ofst)
{
    cout << "Bush and bush" << endl;
    ofst << "Bush and bush" << endl;
}

tree::~tree() {}
bush::~bush() {}

plant *plant::plant_input(ifstream &ifst)
{
    plant *plt_new;
    int k;
    ifst >> k;
    switch (k)
    {
    case 1:
        plt_new = new tree;
        break;
    case 2:
        plt_new = new bush;
        break;
    default:
        return 0;
    }

    plt_new->input(ifst);
    return plt_new;
}

node::~node() {}

bool node::add_node(ifstream &ifst)
{

    plt = plant::plant_input(ifst);

    if (plt == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void container::fill_list(ifstream &ifst)
{
    if (head != NULL)
    {
        cout << "LIST IS NOT EMPTY!" << endl;
        return;
    }

    node *tmpNode = new node;

    if(tmpNode->add_node(ifst))
    {
        head = tmpNode;
        tmpNode->next = tmpNode;
        tmpNode->prev = tmpNode;
        size++;
        tmpNode = NULL;
        tmpNode = new node;
    }

    while (tmpNode->add_node(ifst))
    {
        tmpNode->prev = head->prev;
        head->prev->next = tmpNode;
        head->prev = tmpNode;
        tmpNode->next = head;

        size++;
        tmpNode = NULL;
        tmpNode = new node;
    }
    delete(tmpNode);
}


node *container::get_node(int index)
{
    node *returnNode = head;

    for(int i = 0; i < index; i++)
    {
        returnNode = returnNode->next;
    }

    return returnNode;
}

bool node::output_node(ofstream &ofst)
{
    plt->output(ofst);
    return true;

}

void container::output_list(ofstream &ofst)
{
    node *currentNode;
    if(size == 0)
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }

    ofst << "Container contains " << size << " elements. "<<endl;
    for(int i = 0; i < size; i++)
    {
        currentNode = head;
        for(int j = 0; j < i; j++)
        {
            currentNode = currentNode->next;
        }
        currentNode->output_node(ofst);
    }
}

void container::clear_list()
{
    node *currentNode;

    for(int i = size - 1; i > 0; i--)
    {
        currentNode = head;
        for(int j = 0; j < i; j++)
        {
            currentNode = currentNode->next;
        }
        currentNode->~node();
    }
    size = 0;
    head = NULL;
}

container::container()
    {
        size = 0;
        head = NULL;
}

container::~container()
{
    clear_list();
}

void container::multimethod(ofstream &ofst)
{
    ofst << "Multimethod" << endl;

    for(int i = 0; i < size -1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            get_node(i)->plt->multimethod(get_node(j)->plt, ofst);
            get_node(i)->output_node(ofst);
            get_node(j)->output_node(ofst);
        }
    }
}

}   // end type_plants namespace
