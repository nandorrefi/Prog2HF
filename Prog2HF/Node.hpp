#ifndef NODE_H
#define NODE_H

#include "Container.h"

/** @brief A Node osztály a Container leszármazottja, ezáltal egy pointerekkel ellátott tárolóként tekinthetünk rá,
            amely 20 karakter tárolására alkalmas.
    @author Réfi Nándor
    @date May 2019
*/

///Tartalmazás!
class Node{
    private:
        Node * prev; /**>Az előtte lévő Node-ra mutató pointer*/
        Container data; /**>20-as karaktertömb*/
        Node * next; /**>Az utána lévő Node-ra mutató pointer*/

    public:

        /**Alapértelmezett konstruktor, amely beállítja a Node pointereit NULL-ra*/
        Node() {
            prev = NULL;
            next = NULL;
        }

        virtual ~Node() {}

        /**@return Következő Node pointere
        */
        Node* get_next() const { return next; }
        /**@return Előző Node pointere
        */
        Node* get_prev() const { return prev; }

        /**Következő Node-ra mutató pointer átállítása
        @param node - Node amelyre át akarjuk állítani
        */
        void set_next( Node *node ) { next = node; }
        /**Előző Node-ra mutató pointer átállítása
        @param node - Node amelyre át akarjuk állítani
        */
        void set_prev( Node *node ) { prev = node; }

        //Üres-e a data
        bool is_empty() { return data.is_empty(); }

        //Tele van-e a data
        bool is_full() { return data.is_full(); }

        //Tömb végéről töröl
        void pop_back() { data.pop_back(); }

        //Tömb végéhez hozzáad
        Container& push_back(const char ch) { return data.push_back(ch); }

        //Lekérdezi hány karaktert tárolunk
        size_t get_size() const { return data.get_size(); }

        //Lekérdezi, hogy maximum hány karaktert tárolhatunk.
        static size_t get_capacity() { return Container::get_capacity(); }

        //Visszatér az utolsó elem referenciájával
        char& get_last() { return data.get_last(); }
        const char& get_last() const { return data.get_last(); }

        //Visszatér az első elem referenciájával
        char& get_first() { return data.get_first(); }
        const char& get_first() const { return data.get_first(); }

        //Data indexelőoperátora
        char& operator[](const size_t n) { return data[n]; }
        const char& operator[](const size_t n) const { return data[n]; }

};

#endif // NODE_H
