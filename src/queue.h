#ifndef QUEUE_H
#define QUEUE_H

// 1. using array with time complicity O(n)
// template<class T>
// class Queue{
// public:
//   Queue(){
//     _queue = nullptr;
//     _size = 0;
//   }
//   ~Queue(){
//     delete [] _queue;
//   }
//   void push(T element){
//     if(_size==0){
//       _queue = new T[1];
//       _queue[0] = element;
//       _size = 1;
//       return;
//     }
//     T temp[_size];
//     for(int i=0 ; i<_size ; i++){
//       temp[i] = _queue[i];    // copy what in it
//     }
//     delete [] _queue;
//     _size++;
//     _queue = new T[_size];
//     for(int i=0 ; i<_size-1 ; i++){
//       _queue[i] = temp[i];
//     }
//     _queue[_size-1] = element;
//   }
//   T pop(){
//     if(_size == 0){
//       throw std::string("Is empty");
//     }
//     T result = _queue[0];
//     T temp[_size];
//     for(int i=1 ; i<_size ; i++){
//       temp[i-1] = _queue[i];
//     }
//     delete [] _queue;
//     _size--;
//     _queue = new T[_size];
//     for(int i=0 ; i<_size ; i++){
//       _queue[i] = temp[i];
//     }
//     return result;
//   }
//   T at(int index){
//     if(index < 0 || index >= _size){
//       throw std::string("Undefined");
//     }
//     return _queue[index];
//   }
//   int size(){
//     return _size;
//   }
//   void clear(){
//     delete [] _queue;
//     _queue = nullptr;
//     _size = 0;
//   }
//
// private:
//   T *_queue;
//   int _size;
// };

// using linklist with time complixity O(1)
template<class T>
struct node{
  T data;
  struct node *next;
};

template<class T>
class Queue{
public:
  Queue(){
    _front = nullptr;
    _back = nullptr;
    _size = 0;
  };
  ~Queue(){
    struct node<T> *temp;
    while(_front != _back){
      temp = _front;
      _front = _front->next;
      delete temp;
    }
    delete _front;
  }
  void push(T element){
    struct node<T> *newNode = new node<T>;
    newNode -> data = element;
    newNode -> next = nullptr;
    if (_size == 0) {
        _front = _back = newNode;
        _size++;
        return;
    }
    else {
      _back -> next = newNode;
      _back = newNode;
      _size++;
    }
  }
  T pop(){
    std::cout << "1 ";
    struct node<T> *deleteNode;
    T result;
    if (_size==0)
        throw  std::string("Queue is empty");
    std::cout << "2 ";
    result =  _front -> data;
    std::cout << "3 ";
    std::cout << result;
    deleteNode = _front;
    _front = _front -> next;
    deleteNode -> next = nullptr;
    // delete deleteNode->next;
    delete deleteNode;
    // free(deleteNode);
    _size--;
    return result;
  }
  T at(int index){
    T result;
    struct node<T> *temp = _front;
    for(int i=0 ; i<=index ; i++){
      result = temp->data;
      temp = temp->next;
    }
    return result;
  }
  int size(){
      return _size;
  }
  void clear(){
    struct node<T> *temp;
    while(_front != _back){
      temp = _front;
      _front = _front->next;
      delete temp;
    }
    delete _front;
    _front = _back = nullptr;
    _size = 0;
  }
private:
  struct node<T> *_front;
  struct node<T> *_back;
  int _size;
};

#endif
