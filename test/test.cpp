#include "test.h"
#include <iostream>
#include <fstream>

void test_plant::test_io()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_input.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_output.txt");

    tree t;
    t.input(ifst);
    t.output(ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_output.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_example.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();

}

void test_plant::test_output_tree()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_oop/test/test_output_only_trees/only_trees_input.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_oop/test/test_output_only_trees/only_trees_output.txt");

    container c;
    c.fill_list(ifst);
    c.output_tree(ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_output_only_trees/only_trees_output.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_output_only_trees/only_trees_example.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();
}

void test_plant::test_get_consonant()
{
    tree tr;
    bush bh;
    flower fr;

    tr.name = "dub";
    QCOMPARE(tr.get_consonant(),2);
    tr.name = "db";
    QCOMPARE(tr.get_consonant(),2);
    tr.name = "aaa";
    QCOMPARE(tr.get_consonant(),0);

    bh.name = "kust";
    QCOMPARE(bh.get_consonant(),3);
    bh.name = "kkust";
    QCOMPARE(bh.get_consonant(),4);
    bh.name = "uuu";
    QCOMPARE(bh.get_consonant(),0);

    fr.name = "rose";
    QCOMPARE(fr.get_consonant(),2);
    fr.name = "rrose";
    QCOMPARE(fr.get_consonant(),3);
    fr.name = "oeo";
    QCOMPARE(fr.get_consonant(),0);

}

void test_plant::test_compare()
{
    tree t1;
    tree t2;

    t1.name = "topol";
    t2.name = "dub";

    QCOMPARE(t1.compare(&t2), false);

    bush b1;
    bush b2;

    b1.name = "malina";
    b2.name = "mozhevelnik";

    QCOMPARE(b1.compare(&b2), true);

    flower f1;
    flower f2;

    f1.name = "rose";
    f2.name = "fialka";

    QCOMPARE(f1.compare(&f2), true);

}

void test_plant::test_swap()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_oop/test/test_swap/swap_input.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_oop/test/test_swap/swap_output.txt");

    container c;
    c.fill_list(ifst);

    c.swap(0,2);
    c.swap(1,3);

    c.output_list(ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_swap/swap_output.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_swap/swap_example.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();

}

void test_plant::test_sort()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_oop/test/test_sort/sort_input.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_oop/test/test_sort/sort_output.txt");

    container c;
    c.fill_list(ifst);

    c.sort();

    c.output_list(ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_sort/sort_output.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_sort/sort_example.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();
}



#include "test.moc"
