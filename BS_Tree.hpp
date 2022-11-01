#pragma once
#include<iostream>

template<typename T>
class BS_Tree{
private:
    struct Node{
        T value;
        Node* left;
        Node* right;

        Node(const T& value) : value(value), left(nullptr), right(nullptr) {}
    };

    Node* _root;
    size_t _size;
    void (*_print)(T);
    bool (*_compare)(T&,T&);

private:
    void _insert(Node*& node, T value){
        if (node == nullptr) {
            node = new Node(value);
            return;
        }

        if (_compare(node->value, value)){
            _insert(node->left, value);
        }

        else{
            _insert(node->right, value);
        }
    }

    void _inOrder(Node* node){
        if (node == nullptr) return;
        _inOrder(node->left);
        _print(node->value);
        _inOrder(node->right);
    }

    void _preOrder(Node* node){
        if (node == nullptr) return;
        _print(node->value);
        _preOrder(node->left);
        _preOrder(node->right);
    }

public:
    BS_Tree(void (*print)(T), bool (*comparisonCriteria)(T&,T&) ) : _root(nullptr), _size(0ll), _print(print),
                                                                    _compare(comparisonCriteria) {}

    BS_Tree(bool (*comparisonCriteria)(T&,T&) ) : _root(nullptr), _size(0ll), _compare(comparisonCriteria) {}

    void insert(T value){
       _insert(_root, value);
    }

    void remove(T value){
        
    }

    void PreOrder(){
        _preOrder(_root);
    }

    void InOrder(){
        _inOrder(_root);
    }

    T Max(){
        Node* aux = _root;
        while(aux->right){
            aux = aux->right;
        }
        return aux->value;
    }

    T Min(){
        Node* aux = _root;
        while(aux->left){
            aux = aux->left;
        }
        return aux->value;
    }

};