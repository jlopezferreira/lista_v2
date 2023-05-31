#ifndef LISTA_H
#define LISTA_H

template <typename  T>
class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void AgregarInicio(const T & elem);
        void AgregarFinal(const T & elem);
        bool AgregarArbitrario(const T & elem, const int & pos)const;
        int CantidadElementos()const;
        bool PerteneceLista(const T & elem) const;
        void EliminarLista (const T & elem);
        int DevolverElemento(const int &pos)const;


    protected:

    private:
        struct Nodo{
            T elem;
            Nodo*siguiente
        }
        Nodo * primero;
        // Auxliares
        bool haySiguiente(T elem);
        T siguiente(T elem);
};

#endif // LISTA_H
