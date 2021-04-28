#include <iostream>
#include <fstream>
#include "program.h"
#include <stdlib.h>
using namespace std;
namespace type_plants {

void tree::input(ifstream &ifst)
{

    string tmp_name = "";
    long tmp_age = 0;
    int place = 0;

    ifst >> tmp_name;
    if (ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);

    }
    name = tmp_name;

    ifst >> tmp_age;
    if (ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if (tmp_age < 0)
    {
        cout << "Error! Age cant be negative!" << endl;
        exit(1);
    }
    age = tmp_age;

    ifst >> place;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(place < 0 || place > 5)
    {
        cout << "Error! Location number should be value from range <0-5>!" << endl;
        exit(1);
    }
    location_name = location(place);

//    if (!(ifst >> tmp_name))
//    {
//        cout << "Error! Unexpected end of input!" << endl;

//    }
//    name = tmp_name;

//    ifst >> tmp_name >> tmp_age >> place;

}

void tree::output(ofstream &ofst)
{
    ofst << "It is tree named: " << name
         << " and it's age: " << age
         << ", and location name: "<< location_name + 1 << endl;
    outputCommon(ofst);
}

void tree::output_tree(ofstream &ofst)
{
    output(ofst);
//    outputCommon(ofst);
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
void tree::mm_flower(ofstream &ofst)
{
    cout << "Flower and tree" << endl;
    ofst << "Flower and tree" << endl;
}

void bush::input(ifstream &ifst)
{
    string tmp_name = "";
    int mnth = 0;
    int place = 0;

    ifst >> tmp_name;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }
    name = tmp_name;

    ifst >> mnth;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(mnth < 0 || mnth > 11)
    {
        cout << "Error! Month should be value from range <0-11>" << endl;
        exit(1);
    }
    m = month(mnth);

    ifst >> place;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(place < 0 || place > 5)
    {
        cout << "Error! Location number should be value from range <0-5>!";
        exit(1);
    }
    location_name = location(place);

//    ifst >> tmp_name >> mnth >> place;
//    name = tmp_name;
//    location_name = location(place);
}

void bush::output(ofstream &ofst)
{
//    cout << m + 1 << endl;
    ofst << "It is bush named: " << name
         << " and it's month flowering: " << m + 1
         << ", and location name: "<< location_name + 1<< endl;
    outputCommon(ofst);

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
void bush::mm_flower(ofstream &ofst)
{
    cout << "Flower and bush" << endl;
    ofst << "Flower and bush" << endl;
}

tree::~tree() {}
bush::~bush() {}
flower::~flower() {}

plant *plant::plant_input(ifstream &ifst)
{
    plant *plt_new;
    int k;
    ifst >> k;
    if(ifst.eof())
    {
        return 0;
    }
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }
    if(k < 1 || k > 3)
    {
        cout << "Error! Key should be value from range <1-3>!" << endl;
        exit(1);
    }
    switch (k)
    {
    case 1:
        plt_new = new tree;
        break;
    case 2:
        plt_new = new bush;
        break;
    case 3:
        plt_new = new flower;
        break;
    default:
//        cout << "Error! Invalid Key:" << k <<endl;
//        exit(1);
        return 0;
    }

    plt_new->input(ifst);
    return plt_new;
}


void plant::output_tree(ofstream &ofst)
{
    ofst << endl;
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

bool node::output_node_tree(ofstream &ofst)
{
    plt->output_tree(ofst);
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

void container::output_tree(ofstream &ofst)
{
    node *currentNode;
    if(size == 0)
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }

    ofst << "Only trees." << endl;
    for(int i = 0; i < size; i++)
    {
        currentNode = head;
        for(int j = 0; j < i; j++)
        {
            currentNode = currentNode->next;
        }
        currentNode->output_node_tree(ofst);
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
void flower::input(ifstream &ifst)
{
    string tmp_name = "";
    int type = 0;
    int place = 0;

    ifst >> tmp_name;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }
    name = tmp_name;

    ifst >> type;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(type < 0 || type > 2)
    {
        cout << "Error! Type of flower should be value in range <0-2>!" << endl;
        exit(1);
    }
    flower_kind = kind(type);

    ifst >> place;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(place < 0 || place > 5)
    {
        cout << "Error! Location number should be value from range <0-5>!";
        exit(1);
    }
    location_name = location(place);

//    ifst >> tmp_name >> type >> place;
//    name = tmp_name;
//    location_name = location(place);
}

void flower::output(ofstream &ofst)
{
//    cout << flower_kind + 1 << endl;
    ofst << "It is flower named: " << name
         << " and it's kind: " << flower_kind + 1
         << ", and location name: "<< location_name + 1 << endl;
    outputCommon(ofst);
}

void flower::multimethod(plant *other, ofstream &ofst)
{
    other->mm_flower(ofst);
}
void flower::mm_tree(ofstream &ofst)
{
    cout << "Tree and flower" << endl;
    ofst << "Tree and flower" << endl;
}
void flower::mm_bush(ofstream &ofst)
{
    cout << "Bush and flower" << endl;
    ofst << "Bush and flower" << endl;
}
void flower::mm_flower(ofstream &ofst)
{
    cout << "Flower and flower" << endl;
    ofst << "Flower and flower" << endl;
}

bool plant::compare(plant *other)
{
    return get_consonant() < other->get_consonant();
}

void plant::outputCommon(ofstream &ofst)
{
    ofst << ", Number of consonants: " << get_consonant() << endl;
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
