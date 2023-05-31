#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista<int> lista;
    // Carga datos
    lista.AgregarInicio(30);
    lista.AgregarInicio(20);
    lista.AgregarInicio(10);

    // Recorre, muestra
    int index = 0;
    cout << "Lista: " << endl;
    while (lista.CantidadElementos() > 0 && index <= lista.CantidadElementos()) {
        cout << "Elemento " << index + 1 << ": " << lista.DevolverElemento(index) << endl;
        index++;
    }

    // Elimina elemento de la lista
    int toBeDeleted = 20;
    bool deleted = lista.EliminarLista(toBeDeleted);
    if (deleted)
        cout << "Se ha borrado el elemento: " << toBeDeleted << endl;

    // Recorre, muestra lista actualizada
    index = 0;
    cout << "Lista actualizada: " << endl;
    while (lista.CantidadElementos() > 0 && index <= lista.CantidadElementos()) {
        cout << "Elemento " << index + 1 << ": " << lista.DevolverElemento(index) << endl;
        index++;
    }
    return 0;
}
