#include "doctest.h"
#include "BinaryTree.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <random>

using namespace ariel;
using namespace std;

TEST_CASE("BinaryTree int") // 3 tests
{
    srand(time(0));
    int st[10];
    CHECK_NOTHROW(BinaryTree<int> tree_int);

    BinaryTree<int> tree_int;

    int left = 5;
    int right = 10;
    int parent = 1;
    CHECK_NOTHROW(tree_int.add_root(parent));
    CHECK_NOTHROW(tree_int.add_right(parent, right));
    CHECK_NOTHROW(tree_int.add_left(parent, left));
    CHECK_NOTHROW(tree_int.add_right(right, rand()));
    CHECK_NOTHROW(tree_int.add_left(right, rand()));
    CHECK_NOTHROW(tree_int.add_root(rand()));
}
TEST_CASE("BinaryTree double")
{
    CHECK_NOTHROW(BinaryTree<double> tree_double);
    BinaryTree<double> tree_double;
    double left = 3.4;
    double right = 8.0;
    double parent = 1.5;
    CHECK_NOTHROW(tree_double.add_root(parent));
    CHECK_NOTHROW(tree_double.add_right(parent, right));
    CHECK_NOTHROW(tree_double.add_left(parent, left));
    CHECK_NOTHROW(tree_double.add_right(right, rand()));
    CHECK_NOTHROW(tree_double.add_left(right, rand()));
    CHECK_NOTHROW(tree_double.add_root(rand()));
}

TEST_CASE("BinaryTree string")
{
    CHECK_NOTHROW(BinaryTree<string> tree_string);
    BinaryTree<string> tree_string;

    string left = "name is";
    string right = "ilan teitelbaum";
    string parent = "hi my";
    string is = "is";
    string myname = "myname";
    CHECK_NOTHROW(tree_string.add_root(parent));
    CHECK_NOTHROW(tree_string.add_right(parent, right));
    CHECK_NOTHROW(tree_string.add_left(parent, left));
    CHECK_NOTHROW(tree_string.add_right(right, is));
    CHECK_NOTHROW(tree_string.add_right(right, myname));
}

TEST_CASE("Checking the demo works as expected")
{
    ostringstream stream;
    string str;
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(10)
        .add_left(10, 2)
        .add_left(2, 3)
        .add_right(10, 5)
        .add_right(5, 6)
        .add_left(5, 4);
    cout << tree_of_ints << endl; /* Prints the tree i
        10
        |--------|
        2        5
        |---|    |---|
        3       4   6
  */

    stream.str("");
    stream.clear();
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it)
    {
        stream << (*it) << " ";
    } // prints: 10 2 3 5 4 6
    str = stream.str();
    CHECK_EQ(str, "10 2 3 5 4 6");

    stream.str("");
    stream.clear();
    for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it)
    {
        stream << (*it) << " ";
    } // prints: 3 2 10 4 5 6
    str = stream.str();
    CHECK_EQ(str, "3 2 10 4 5 6");

    stream.str("");
    stream.clear();
    for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it)
    {
        stream << (*it) << " ";
    } // prints: 3 2 4 6 5 10
    str = stream.str();
    CHECK_EQ(str, "3 2 4 6 5 10");
}