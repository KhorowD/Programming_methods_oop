#ifndef PROGRAM_H
#define PROGRAM_H
#include <fstream>
#include <string>
using namespace std;
namespace type_plants {

    // Общий класс растений
    class plant
    {
    public:
        enum location {TUNDRA, DESERT, STEPPE, TAIGA, MIXED_FOREST, MOUNTAINS};
        string name;
        location location_name;


        virtual ~plant() {};
        static plant *plant_input(ifstream &ifst);
        virtual void input(ifstream &ifst) = 0;
        virtual void output(ofstream &ofst) = 0;
        virtual void output_tree(ofstream &ofst);
        virtual int get_consonant(); //получение числа согласных в названии
        bool compare(plant *other);
        void outputCommon(ofstream &ofst);

    };

    //  Деревья
    class tree: public plant
    {
    public:
        long age;       //  возраст

        void input(ifstream &ifst);
        void output(ofstream &ofst);
        void output_tree(ofstream &ofst);
        ~tree();
    };

    //  Кустарники
    class bush: public plant
    {
        // Значение месяца цветения кустарников
        enum month {JAN, FEB, MAR, APR, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};
    public:
        month m;        //  Месяц цветения


        void input(ifstream &ifst);
        void output(ofstream &ofst);
        ~bush();
    };

    class flower: public plant
    {
        enum kind {DOMESTIC, GARDEN, WILD};
    public:
        kind flower_kind;

        void input(ifstream &ifst);
        void output(ofstream &ofst);
        ~flower();
    };

    //
    class node
    {
    public:
        plant *plt;
        node *next;
        node *prev;

        bool add_node(ifstream &ifst);
        bool output_node(ofstream &ofst);
        bool output_node_tree(ofstream &ofst);
        ~node();
    };

    struct container
    {
    public:
        long size;
        node *head;


        void fill_list(ifstream &ifst);
        void output_list(ofstream &ofst);
        void output_tree(ofstream &ofst);
        void clear_list();
        node *get_node(int index);
        void swap(int index_first, int index_second);
        void sort();    //сортировка

        container();
        ~container();
    };


}   // end type_plants namespace
#endif // PROGRAM_H
