#include <iostream>
#include <cstddef>
#include <memory>

using namespace std;

struct node;
struct list;

node create_node(int value);
void push_front(list& list, shared_ptr<node> node);
void push_back(list& list, shared_ptr<node> node);
void insert(list& list, shared_ptr<node> insertionNode, size_t pos);
void erase(list& list, size_t pos);
void print_list(list& list);

struct node
{
    shared_ptr<int> value;
    shared_ptr<node> next;
};

struct list
{
    shared_ptr<node> head;
    shared_ptr<node> tail;
    size_t size;
};

node create_node(int value) {
    node node;

    node.value = make_shared<int>(value);
    node.next = nullptr;

    return node;
};

void push_front(list& list, shared_ptr<node> node) {
    insert(list, node, 0);
    return;
};

void push_back(list& list, shared_ptr<node> node) {
    insert(list, node, list.size);
    return;
};

void insert(list& list, shared_ptr<node> insertionNode, size_t pos) {
    // <pos> es el índice donde quedará el nodo a insertar.
    // Por ejemplo
    // lista = 1 -> 2 -> 3 -> 4
    // Si llamamos insert(lista, nodo_con_valor_5, 2), el resultado sería:
    // lista = 1 -> 2 -> 5 -> 3 -> 4
    // Donde el nodo con valor 5 se inserta en la posición 2 (índice base 0)
    // Por lo tanto insertar en la <pos> 0, inserta al comienzo de la lista, e insertar en la <pos> list.size, inserta al final de la lista.

    if (pos > list.size) {
        cout << "La posición (" << pos << ") en donde se desea insertar es mayor que el largo de la lista (" << list.size << "), se insertará el nodo al final de la lista." << endl;
        pos = list.size;
    };

    if (list.head == nullptr) {
        list.head = insertionNode;
        list.tail = insertionNode;
        list.size++;
        return;
    }

    if (pos == 0) {
        insertionNode->next = list.head;
        list.head = insertionNode;
        list.size++;
        return;
    }

    if (pos == list.size) {
        list.tail->next = insertionNode;
        list.tail = insertionNode;
        list.size++;
        return;
    }

    shared_ptr<node> iterNode = list.head;

    for (size_t i = 0; i < pos - 1; i++) {
        iterNode = iterNode->next;
    };
    
    list.size++;

    insertionNode->next = iterNode->next;
    iterNode->next = insertionNode;

    return;
};

void erase(list& list, size_t pos) {
    shared_ptr<node> auxNode, iterNode;

    if (pos > list.size) {
        cout << "La posición (" << pos << ") en donde se desea borrar es mayor que el largo de la lista (" << list.size << "), se borrará el nodo del final de la lista." << endl;
        pos = list.size - 1;
    };

    cout << "Se ha borrado el nodo en la posición " << pos << "." << endl;

    if (list.size == 1) {
        list.head = nullptr;
        list.tail = nullptr;
        list.size--;
        return;
    }

    if (pos == 0) {
        auxNode = list.head;

        list.head = list.head->next;
        auxNode->next = nullptr;
        list.size--;
        return;
    }

    if (pos == list.size - 1) {
        iterNode = list.head;

        while (iterNode->next != list.tail) {
            iterNode = iterNode->next;
        };

        iterNode->next = nullptr;
        list.tail = iterNode;
        list.size--;
        return;
    }

    iterNode = list.head;

    for (size_t i = 0; i < pos - 1; i++) {
        iterNode = iterNode->next;
    };
    
    auxNode = iterNode->next;
    iterNode->next = auxNode->next;

    auxNode->next = nullptr;
    list.size--;

    return;
};

void print_list(list& list) {
    if (list.size == 0) {
        cout << "Lista vacía." << endl;
        return;
    }
    
    cout << "Lista:" << endl;

    shared_ptr<node> actualNode = list.head;

    for (size_t i = 0; i < list.size; i++) {
        cout << *(actualNode->value) << ((i < list.size - 1) ? " -> " : "");
        actualNode = actualNode->next;
    };

    cout << endl;
};

int main() {
    list list = {nullptr, nullptr, 0};
    int choice = 0;
    int value;
    size_t position;

    while (true) {
        cout << endl << "----- Operaciones de Lista -----" << endl;
        cout << "1. Insertar al Principio" << endl;
        cout << "2. Insertar al Final" << endl;
        cout << "3. Insertar por índice" << endl;
        cout << "4. Borrar por índice" << endl;
        cout << "5. Mostrar Lista" << endl;
        cout << "6. Salir" << endl;
        cout << endl << "Ingrese su opción: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Ingrese un valor para insertar al principio: ";
                cin >> value;
                push_front(list, make_shared<node>(create_node(value)));
                cout << "El valor (" << value << ") se ha insertado al principio." << endl;
                break;
            
            case 2:
                cout << "Ingrese un valor para insertar al final: ";
                cin >> value;
                push_back(list, make_shared<node>(create_node(value)));
                cout << "El valor (" << value << ") se ha insertado al final." << endl;
                break;
            
            case 3:
                cout << "Ingrese un valor para insertar: ";
                cin >> value;
                cout << "Ingrese la posición: ";
                cin >> position;
                insert(list, make_shared<node>(create_node(value)), position);
                cout << "El valor (" << value << ") se ha insertado en la posición (" << ((position > list.size) ? list.size : position) << ")." << endl;
                break;

            case 4:
                if (!list.size) {
                    cout << "La lista está vacía, no se puede eliminar ningún nodo." << endl;
                    break;
                }

                cout << "Ingrese la posición del nodo a borrar: ";
                cin >> position;
                erase(list, position);
                break;
            
            case 5:
                print_list(list);
                break;
            
            case 6:
                cout << "Saliendo del programa." << endl;
                return 0;
            
            default:
                cout << "Opción incorrecta, intente nuevamente." << endl;
        }
    }
}