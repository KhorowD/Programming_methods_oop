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
         << " and it's age: " << age
         << ", Number of consonants: " << get_consonant() << endl;
}

//int tree::get_consonant()
//{
//    int count = 0;
//    string vowels = "aeiouy";

//    for(unsigned int i = 0; i < vowels.size(); i++)
//    {
//        for(unsigned int j = 0; j < name.size(); j++)
//        {
//            if(vowels[i] == name[j])
//            {
//                count++;
//            }
//        }
//    }

//    return (name.size() - count); //возвращаем число (длина - гласные)
//}

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
         << " and it's month flowering: " << m + 1
         << ", Number of consonants: " << get_consonant() << endl;
}

//int bush::get_consonant()
//{
//    int count = 0;
//    string vowels = "aeiouy";

//    for(unsigned int i = 0; i < vowels.size(); i++)
//    {
//        for(unsigned int j = 0; j < name.size(); j++)
//        {
//            if(vowels[i] == name[j])
//            {
//                count++;
//            }
//        }
//    }

//    return (name.size() - count); //возвращаем число (длина - гласные)
//}

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

int plant::get_consonant()
{
    int count = 0;
    string vowels = "aeiouy";

    for(unsigned int i = 0; i < vowels.size(); i++)
    {
        for(unsigned int j = 0; j < name.size(); j++)
        {
            if(vowels[i] == name[j])
            {
                count++;
            }
        }
    }

    return (name.size() - count); //возвращаем число (длина - гласные)
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


bool plant::compare(plant *other)
{
    return get_consonant() < other->get_consonant();
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

void container::swap(int index_first, int index_second)
{
    node *temp = new node;

    temp->plt = get_node(index_first)->plt;
    get_node(index_first)->plt = get_node(index_second)->plt;
    get_node(index_second)->plt = temp->plt;

}

void container::sort()
{
    for(int i = 0; i < size -1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(get_node(i)->plt->compare(get_node(j)->plt))
            {
                swap(i,j);
            }
        }
    }
}

}   // end type_plants namespace
