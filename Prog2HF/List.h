#ifndef LIST_H
#define LIST_H

#include "Node.hpp"

/** @brief A List osztály a Node osztály tagjaiból álló láncolt lista kezeléséért felelős.
    Egy-egy Node osztályban 20-20 db karaktert lehet eltárolni. A Node osztályok pointerekkel
    hivatkoznak az előttük és utánuk lévő Node-okra.
    @author Réfi Nándor
    @date May 2019
*/
class List
{
    private:
        Node *first;   /**>Első sentinel node*/
        Node *last;    /**>Utolsó sentinel node*/
        size_t size;   /**>Eltárolt karakterek száma*/

        /**Két Node összekapcsolása
        @param first_node - első Node
        @param next_node - következő Node, amit az első után kapcsolunk
        */
        void connect_nodes(Node *first_node, Node *next_node);
        /**Sentinelek beállítása. Csak egyszer szabad meghívni a konstruktorokban.
        */
        void init_sentinels();
        /**Node törlése a listából. Ez rendezi az előtte meg utána lévő Nodeok pointereit is.
        */
        void delete_node(Node *target);

    public:
        /**Alapértelmezett konstruktor. Létrehozza a sentineleket és összekapcsolja őket.
        Ezáltal egy üres listát készítve.
        */
        List();

        /**Másolókonstruktor. Létrehozza a sentineleket és összekapcsolja őket.
        Majd feltölti a paraméterül adott változó elemeivel.
        */

        List(const char val){
            init_sentinels();
            size = 0;

            *this = val;
        }

        List(const char* val){
            init_sentinels();
            size = 0;

            *this = val;
        }

        List(const List& val){
            init_sentinels();
            size = 0;

            *this = val;
        }

        virtual ~List();

        /**Visszaadja a lista elemeinek számát
        @return lista elemeinek száma
        */
        size_t get_size() const { return size; }
        /**Megnézi üres-e a lista
        @return üres-e a lista
        */
        bool is_empty() const;
        /**A lista végére fűz egy karaktert.
        @param ch - a karakter
        */
        List& push_back(const char ch);
        /**A lista végéről töröl egy karaktert.
        */
        void pop_back();

        /**Törli a lista tartalmát.
        */
        void clear();

        List& operator=(const char);

        List& operator=(const char*);

        List& operator=(const List&);

        char& operator[](const size_t n);           //Lista egyik adattagjának megindexelése

        const char& operator[](const size_t n) const;

        class iterator;

        /**A lista elejére állít egy iterátort.
        @return Lista elejére állított iterátor
        */
        iterator begin(){
            return iterator(*this);
        }
        /**A lista végére állít egy iterátort.
        @return Lista végére állított iterátor
        */
        iterator end(){
            return iterator(*this, size-1);
        }

        /**Az iterator osztály a listán belüli iterálást teszi lehetővé.
        */
        class iterator{
            Node *curr_node; /**<Jelenleg melyik Node-ban vagyunk*/
            char *ptr;       /**<Jelenleg kiválasztott elemre mutató pointer*/
            char *ptr_end;   /**<Utolsó elem után mutató pointer*/

            /**Megnézi a Node utolsó eleméhez értünk-e
            @return Vége van-e a Node-nak, az az a pointer a Node-on belül az utolsó elemen áll
            */
            bool node_ends(){
                if( &(curr_node->get_last()) == ptr )
                    return true;
                return false;
            }
            /**Megnézzük, hogy a Node első elemén áll-e a pointer.
            @return A Node kezdetén áll-e a pointer.
            */
            bool node_begins(){
                if( &(curr_node->get_first()) == ptr )
                    return true;
                return false;
            }
        public:
            /**Alapértelmezett konstruktor, üres iterator létrehozása
            */
            iterator() : ptr(0), ptr_end(0) {
                curr_node = 0;
            }

            /**Egy megadott listára ad egy iterátort.
            @param r_list - a kérdéses lista
            @param offset - hányadik elemre állítsuk az iterátort
            */
            iterator(List& r_list, size_t offset = 0)
            {
                if(r_list.get_size() == 0) throw "The list is empty";

                ptr = &(r_list[offset]);
                ptr_end = &(r_list[r_list.get_size()-1]);
                ptr_end += 1;

                curr_node = r_list.first->get_next();
                for(size_t i = 0; i < offset/20; ++i){
                    curr_node = curr_node->get_next();
                }
            }

            iterator(const iterator& iter_r){
                *this = iter_r;
            }

            virtual ~iterator() {}

            /**Visszaadja referenciaként az elemet, amelyre a poitner mutat
                @return referencia arra az elemre, amelyre a pointer mutat
            */
            char& operator*(){ return *ptr; }

            /**Visszaadja konstans referenciaként az elemet, amelyre a poitner mutat
                @return konstans referencia arra az elemre, amelyre a pointer mutat
            */
            const char& operator*() const { return *ptr;}

            iterator& operator=(const iterator& iter_r);

            bool operator==(const iterator& iter_r) const{
                return ptr == iter_r.ptr && ptr_end == iter_r.ptr_end;
            }

            bool operator!=(const iterator& iter_r) const{
                return !(*this == iter_r);
            }

            iterator& operator--(){
                if(node_begins()){
                    if( curr_node->get_prev()->get_prev() == NULL ) throw "Iterator::operator++ : Out_Of_Range";
                    curr_node = curr_node->get_prev();
                    ptr = &(curr_node->get_last());
                }
                else{
                    ptr--;
                }

                return *this;
            }

            iterator operator--(int){
                iterator res(*this);
                --(*this);
                return res;
            }

            iterator& operator++(){
                if(ptr == ptr_end) throw "Iterator::operator++ : Out_Of_Range";
                else if(node_ends()){
                    curr_node = curr_node->get_next();
                    ptr = &(curr_node->get_first());
                }
                else{
                    ptr++;
                }

                return *this;
            }

            iterator operator++(int){
                iterator res(*this);
                ++(*this);
                return res;
            }
        };



};



#endif
