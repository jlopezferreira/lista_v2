#include "Lista.h"
#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
Lista<T>::Lista()
{
    primero = nullptr;
}

template <typename T>
Lista<T>::~Lista()
{
    primero = nullptr;
}

template <typename T>
void Lista<T>::AgregarInicio(const T &e){
    Nodo*Crear_Nodo= new Nodo();
    Crear_Nodo ->elem = e;
    Crear_Nodo ->siguiente= primero;
    primero = Crear_Nodo;
}

template <typename T>
void Lista<T>::AgregarFinal(const T &e){
    Nodo*cursor=primero;
    Nodo*Crear_Nodo=new Nodo();
    if (primero != nullptr){
        while(cursor -> siguiente != nullptr) {
            cursor = cursor -> siguiente;
            cursor->siguiente = Crear_Nodo;
            cursor->elem = e;
            cursor = Crear_Nodo;
            Crear_Nodo -> siguiente = nullptr;
        }
    }
    else {
        primero = Crear_Nodo;
        Crear_Nodo ->elem = e;
        Crear_Nodo ->siguiente= nullptr;}
    }

//template <typename T>
//bool Lista<T>::AgregarArbitrario(const T &elem, const int &pos) const {
//    if (primero != nullptr){ //Lista no vacía
//        if(pos == 0){ //Posición ingresada = 0, llama a AgregarInicio
//            AgregarInicio(elem);
//            return 0;
//        }
//        else{
//            int i = 0; //Si posición ingresada <> 0, recorre la lista con ayuda del cursor hasta el lugar indicado e inserta el elemento
//            Nodo* cursor = primero;
//            while ((i < pos-1) && (cursor -> siguiente != nullptr)){
//                i++;
//                cursor = cursor -> siguiente;
//            }
//            if (cursor -> siguiente == nullptr){
//                AgregarFinal(elem);
//                return true;
//            }
//            else if (i == pos - 1){ //Llegó a la posición anterior a la ingresada
//                    Nodo * Crear_Nodo = new Nodo();
//                    Crear_Nodo -> siguiente = cursor -> siguiente;
//                    cursor -> siguiente = Crear_Nodo;
//                    return true;
//                }
//                else {
//                    return false;
//                }
//            }
//        }
//    else if (pos==0){
//        AgregarInicio(elem);
//        return true;
//    }
//    else {
//        return false; //Si sale de la función poder agregar el elemento ingresado en la posicón indicada
//    }
//}

template <typename T>
int Lista<T>::CantidadElementos() const {
    int i= 0;
    Nodo*cursor = primero;
    while (cursor->siguiente != nullptr){
        i++;
        cursor=cursor->siguiente;
    }
    return i;
}

template <typename T>
bool Lista<T>::PerteneceLista(const T &elem)const {
    Nodo*cursor = primero;
    while (cursor->siguiente != nullptr && cursor->elem != elem){
        cursor = cursor->siguiente;
    }
    if (cursor ->elem == elem){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
bool Lista<T>::EliminarLista(const T&elem){
    Nodo*cursor= primero;
    if (primero== nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else if (primero->elem == elem){ //El elemento se encuentra al principio
        primero = cursor -> siguiente;
        delete(cursor);
    }
    else if (PerteneceLista(elem)){
        while (cursor->siguiente->elem != elem && cursor->siguiente !=nullptr){ //Va a cortar cuando el siguiente nodo contenga el elemento a eliminar ó cuando llegue al final de la lista
            cursor = cursor -> siguiente;
        }
        if (cursor->siguiente != nullptr) {
            Nodo*temporal= cursor->siguiente;//Temporal una posición adelante de cursor
            cursor->siguiente  = temporal->siguiente; //El cursor va a apuntar al siguiente de temporal, para luego eliminar este último
            delete temporal;
        }
    }
    else
        cout <<"El elemento ingresado no pertenece a la lista"<<endl;
}

template <typename T>
T Lista<T>::DevolverElemento(const int & pos) const {
    int cont = 0;
    Nodo * cursor = primero;
    while (cursor ->siguiente != nullptr && cont < pos){
        cursor = cursor -> siguiente;
        cont++;
    }
    if(cont==pos){ //El bucle terminó cuando se llegó a la posición ingresada (guardando el nodo cursor que corresponde a esta posición)
        return cursor ->elem;
    }
    else {
        cout <<"La posición ingresada no es válida"<<endl;
    }
}

template class Lista<int>;
