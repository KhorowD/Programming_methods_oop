#include <iostream>
#include <fstream>
#include <QTest>
#include "test/test.cpp"
#include "program.h"
using namespace std;
using namespace type_plants;

int main(int argc, char const *argv[])
{

    QTest::qExec(new test_plant);

//    if (argc != 3)
//    {
//        cout << "incorrect command line!"
//               << "Waited: command infile outfile" << endl;
//        exit(1);
//    }
//    cout << argv[1] <<endl;
//    cout << argv[2] << endl;
//    ifstream ifst(argv[1]);

//    if(!ifst.is_open())
//    {
//        cout << "file is not open!" << endl;
//        return 1;
//    }
//    ofstream ofst(argv[2]);
//    if(!ofst.is_open())
//    {
//        cout << "file is not open!" << endl;
//        return 1;
//    }

//    cout << "Start" << endl;
//    container c;
//    c.fill_list(ifst);
//    ofst << "Filled container. " << endl;
//    c.output_list(ofst);
//    ofst << "sorted container" << endl;
//    c.sort();
//    c.output_list(ofst);
//    ofst << "filtered" << endl;
//    c.output_tree(ofst);
//    c.clear_list();
//    cout << "Empty container. " << endl;
//    c.output_list(ofst);
//    cout << "Stop" << endl;


    return 0;
}
