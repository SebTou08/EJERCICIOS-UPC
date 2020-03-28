#include <iostream>
#include <string>
using namespace std;
template <typename G>
class node{
public:
    G data;
    node *next;
    node(){
        this->data = NULL;
        this->next = nullptr;
    }
    ~node(){}
};
template <typename T>
class List{
private:
    node<T> *head;
    int size;
    void DestroyNode(node<T> * nodo){
        delete nodo;
    }
    node<T>* createNode(T newData){
        node<T>* newNode = new node<T>();
        newNode->data = newData;
        newNode->next = nullptr;
        return newNode;
    }
    node<T>* GetNode(int position){
        node<T>*puntero = this->head;
        int pos = 0;
        while(pos < position && puntero->next){
            puntero = puntero->next;
            ++pos;
        }
        if(pos != position){
            return nullptr;
        }
        else{
            return puntero;
        }
    }
public:
    List(){
        head = nullptr;
        size = 0;
    }
    ~List(){
        while (this->head->next != nullptr){
            node<T> * first = this->head;
            this->head = this->head->next;
            this->DestroyNode(first);
            --this->size;
        }
        delete this->head;
    }
    bool isEmpty(){
        return (this->head == nullptr);
    }
    void InsertFirst(T newData){
        node<T> * insertedNode = createNode(newData);
        insertedNode->next = this->head;
        this->head = insertedNode;
        this->size++;
    }
    void InsertEnd(T newData){
        node<T>*insertedNode = createNode(newData);
        if(this->isEmpty()){
            this->head = insertedNode;
            ++this->size;
        }
        else{
            node<T> * puntero = this->GetNode(this->size - 1);
            puntero->next = insertedNode;
            ++this->size;
        }
    }
    void InsertInPosition(int position, T newData){
        node<T> * insertedNode = createNode(newData);
        if(this->isEmpty()){
            this->head = insertedNode;
            ++this->size;
        }
        else{
            node<T>*puntero = this->GetNode(position - 1);
            insertedNode->next = puntero->next;
            puntero->next = insertedNode;
            ++this->size;
        }
    }
    T GetData(int position){
        if(this->isEmpty()){
            return NULL;
        }
        else{
            node<T>*puntero = this->GetNode(position);
            if(puntero != nullptr){
                return puntero->data;
            } else{
                return NULL;
            }
        }
    }
    int Size(){
        return this->size;
    }
    void DeleteFirst(){
        if(!this->isEmpty()){
            node<T> * first = this->head;
            this->head = this->head->next;
            this->DestroyNode(first);
            --this->size;
        }
    }
    void DeleteEnd(){
        if(!this->isEmpty()){
            if(this->size > 1){
                node<T> * puntero = this->GetNode(this->size - 2);
                node<T> *eliminado = puntero->next;
                puntero->next = nullptr;
                DestroyNode(eliminado);
                --this->size;
            } else{
                node<T> * eliminado = this->head;
                this->head = nullptr;
                this->DestroyNode(eliminado);
                --this->size;
            }
        }
    }
    void DeleteInPosition(int position){
        if(!this->isEmpty()){
            if(position == 0){
                node<T> * eliminado = this->head;
                this->head = this->head->next;
                this->DestroyNode(eliminado);
                --this->size;
            } else if(position < this->size){
                node<T> * puntero = GetNode(position - 1);
                node<T> *eliminado = puntero->next;
                puntero->next = eliminado->next;
                this->DestroyNode(eliminado);
                --this->size;
            }
        }
    }
};
int main(){
    List<int>*numbers = new List<int>();
    for (int i = 0; i < 100; ++i) {
        numbers->InsertEnd(i + 2);
    }
    cout<<numbers->Size()<<endl;
    cout<<numbers->GetData(0)<<endl;
    numbers->InsertInPosition(5, 800);
    cout<<numbers->GetData(5)<<endl;
    delete numbers;
    return 0;
}
