#ifndef LISTA_H
#define LISTA_H

template <typename  T>
class Lista
{
private:
    struct Nodo{
        T elem;
        Nodo*siguiente;
    };
    Nodo * primero;

public:
    Lista();
    ~Lista();
    void AgregarInicio(const T & elem);
    void AgregarFinal(const T & elem);
    bool AgregarArbitrario(const T & elem, const int & pos)const;
    int CantidadElementos()const;
    bool PerteneceLista(const T & elem) const;
    bool EliminarLista (const T & elem);
    T DevolverElemento(const int &pos)const;
};

#endif // LISTA_H
