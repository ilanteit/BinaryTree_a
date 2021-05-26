#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

namespace ariel
{

    template <typename T>
    class BinaryTree
    {
    private:
       
        struct Node
        {
        public:
            Node *pLeft;
            Node *pRight;
            Node *parent;
            T value;

            Node(T val)
            {
                this->val = val;
                pLeft = pRight = nullptr;
            }
        };
        Node *root;

    public:
      

        class Iterator
        {

        private:
            Node *current;

        public:
            Iterator(Node* ptr = nullptr) : current(ptr) {}

            T& operator*() const
            {
                //return *_current;
                return current->value;
            }

            T *operator->() const
            {
                return &(current->value);
            }
             

            // ++i;
            Iterator &operator++()
            {
                //++_current;
                current = current->pLeft;
                return *this;
            }

            // i++;
            const Iterator operator++(int)
            {
                Iterator tmp = *this;
                current = current->pLeft;
                return tmp;
            }

            bool operator==(const Iterator &it) const
            {
                return current == it.current;
            }

            bool operator!=(const Iterator &it) const
            {
                return current != it.current;
            }
        };
    public:
     BinaryTree():root(nullptr){}
    //  ~BinaryTree(){};

        BinaryTree<T> add_root(T val)
        {
            return *this;
        }

        BinaryTree<T> add_left(T val, T parent)
        {
            return *this;
        }

        BinaryTree<T> add_right(T val, T parent)
        {
            return *this;
        }

        // template <typename T>
        // BinaryTree<T>::BinaryTree()
        // {
        // }

        //  template <typename T>
        // BinaryTree<T>::BinaryTree(BinaryTree *bt)
        // {
        //     // this->root = copy_tree(bt->root);
        // }

        // template <typename T>
        // BinaryTree<T>::~BinaryTree()
        // {
        //     if (root != NULL)
        //     {
        //         clear(root);
        //     }
        //     // destroy_tree(this->root);
        // }

        Iterator begin_preorder()
        {
            return Iterator{root};
        }

        Iterator end_preorder()
        {
            return Iterator{root};
        }

        Iterator begin_inorder()
        {
            return Iterator{root};
        }

        Iterator end_inorder()
        {
            return Iterator{root};
        }

        Iterator begin_postorder()
        {
            return Iterator{root};
        }

        Iterator end_postorder()
        {
            return Iterator{root};
        }

        Iterator begin()
        {
            return Iterator{root};
        }

        Iterator end()
        {
            return Iterator{root};
        }

        friend ostream &operator<<(ostream &os, const BinaryTree<T> &binaryTree)
        {
            os << "....";
            return os;
        }
        // friend ostream &operator<<(ostream &out, const BinaryTree<T> &BT)
        // {
        //     return out;
        // }
    };

}
