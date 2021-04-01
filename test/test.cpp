#include "test.h"
#include <iostream>
#include <fstream>

void test_plant::test_io_tree()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_tree/io_input_tree.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_tree/io_output_tree.txt");

    tree t;
    t.input(ifst);
    t.output(ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_tree/io_output_tree.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_tree/io_example_tree.txt");

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

void test_plant::test_io_bush()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_bush/io_input_bush.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_bush/io_output_bush.txt");

    bush b;
    b.input(ifst);
    b.output(ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_bush/io_output_bush.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_bush/io_example_bush.txt");

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

void test_plant::test_io_flower()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_flower/io_input_flower.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_flower/io_output_flower.txt");

    flower f;
    f.input(ifst);
    f.output(ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_flower/io_output_flower.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_flower/io_example_flower.txt");

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

void test_plant::test_io_plant()
{
    ifstream ifst_1("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_input_tree.txt");
    ifstream ifst_2("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_input_bush.txt");
    ifstream ifst_3("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_input_flower.txt");

    if(!ifst_1.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }

    if(!ifst_2.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }

    if(!ifst_3.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }

    cout << "Files is open! " << endl;

    ofstream ofst_1("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_output_tree.txt");
    ofstream ofst_2("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_output_bush.txt");
    ofstream ofst_3("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_output_flower.txt");

    plant *p1;
    p1 = plant::plant_input(ifst_1);
    p1->output(ofst_1);

    plant *p2;
    p2 = plant::plant_input(ifst_2);
    p2->output(ofst_2);

    plant *p3;
    p3 = plant::plant_input(ifst_3);
    p3->output(ofst_3);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_output_tree.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_example_tree.txt");

    QFile file_in_3("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_output_bush.txt");
    QFile file_in_4("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_example_bush.txt");

    QFile file_in_5("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_output_flower.txt");
    QFile file_in_6("D:/Projects/Qt/Programming_methods_oop/test/test_io/io_plant/io_example_flower.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;
    if(!file_in_3.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_4.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;
    if(!file_in_5.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_6.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_1(&file_in_1);
    QTextStream s_2(&file_in_2);
    QTextStream s_3(&file_in_3);
    QTextStream s_4(&file_in_4);
    QTextStream s_5(&file_in_5);
    QTextStream s_6(&file_in_6);

    QString s1 = s_1.readAll();
    QString s2 = s_2.readAll();
    QString s3 = s_3.readAll();
    QString s4 = s_4.readAll();
    QString s5 = s_5.readAll();
    QString s6 = s_6.readAll();

    QCOMPARE(s1,s2);
    QCOMPARE(s3,s4);
    QCOMPARE(s5,s6);

    file_in_1.close();
    file_in_2.close();
    file_in_3.close();
    file_in_4.close();
    file_in_5.close();
    file_in_6.close();
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
