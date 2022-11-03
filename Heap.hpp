#pragma once
#include <iostream>

template <typename T>
class Heap{
private:
    T* _arr;
    int _MAX_SIZE;
    size_t _size;
    bool (*_compare)(const T&, const T&);

    int _left(int i){
        return 2*i+1;
    }

    int _right(int i){
        return 2*i+2;
    }

    int _parent(int i){
        return (i-1)/2;
    }

    void _swap(T& a, T& b){
        T aux = a;
        a = b;
        b = aux;
    }
    
public:
    Heap(int _MAX_SIZE, bool (*compare)(const T&, const T&)) : _MAX_SIZE(_MAX_SIZE), _size(0), _arr(new T[_MAX_SIZE]), _compare(compare) {} //Heap myHeap = {1,2,3,4,5};

    ~Heap() {delete _arr;}

    T get_min(){
        return _arr[0];
    }

    void MinHeapify(int i){ // 0
        int left = _left(i); // 1
        int right = _right(i); // 2     
        int smaller = i; // 0

        if (left < _size && _compare(_arr[left], _arr[smaller])) //_arr[left] < _arr[smaller]
            smaller = left;

        if (right < _size && _compare(_arr[right], _arr[smaller])) // _arr[right] < _arr[smaller]
            smaller = right;
        
        if (smaller != i){
            _swap(_arr[smaller], _arr[i]);
            MinHeapify(smaller);
        }
    }

    void Traversing(){ //
        for(int i = 0; i < _size;i++ ){
            std::cout<<_arr[i]<<" ";
        }
        std::cout<<'\n';
    }

    void insert(const T& value){
        if (_size == _MAX_SIZE){
            std::cout<<"Overflow: Could not insert a key"<<std::endl;
            return;
        }

        _size++;
        int i = _size-1;
        _arr[i]= value;

        while(i != 0 && _compare(_arr[i],_arr[_parent(i)])){ //_arr[_parent(i)] > _arr[i]
            _swap(_arr[_parent(i)], _arr[i]);
            i = _parent(i);
        }
    }

    T extractMin(){ //Para retornar el minimo del arreglo y sacarlo

        if (_size == 0){
            std::cout<<"Underflow"<<std::endl;
            return T();
        }

        if (_size == 1){
            _size--;
            return _arr[0];
        }

        T min = _arr[0];
        _arr[0] = _arr[_size-1];
        _size--;
        MinHeapify(0);

        return min;
    }

};