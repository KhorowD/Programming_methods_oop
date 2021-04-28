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
        string name;

        virtual ~plant() {};
        static plant *plant_input(ifstream &ifst);
        virtual void input(ifstream &ifst) = 0;
        virtual void output(ofstream &ofst) = 0;
        virtual void multimethod(plant *other, ofstream &ofst) = 0;
        virtual void mm_tree(ofstream &ofst) = 0;
        virtual void mm_bush(ofstream &ofst) = 0;
    };

    //  Деревья
    class tree: public plant
    {
    public:
        long age;       //  возраст

        void input(ifstream &ifst);
        void output(ofstream &ofst);
        void multimethod(plant *other, ofstream &ofst);
        void mm_tree(ofstream &ofst);
        void mm_bush(ofstream &ofst);
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
        void multimethod(plant *other, ofstream &ofst);
        void mm_tree(ofstream &ofst);
        void mm_bush(ofstream &ofst);
        ~bush();
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

        ~node();
    };

    class container
    {
    public:
        long size;
        node *head;


        void fill_list(ifstream &ifst);
        void output_list(ofstream &ofst);
        void clear_list();
        void multimethod(ofstream &ofst);
        node *get_node(int index);

        container();
        ~container();
    };


}   // end type_plants namespace
#endif // PROGRAM_H
