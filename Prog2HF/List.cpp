#include "List.h"

void List::connect_nodes(Node *first_node, Node *next_node){
    first_node->set_next( next_node );
    next_node->set_prev( first_node );
}

void List::init_sentinels(){
    first = new Node;
    last = new Node;
    connect_nodes(first, last);
}

void List::delete_node(Node *target){
    connect_nodes(target->get_prev(), target->get_next());
    delete target;
}

List::List(){
    init_sentinels();
    size = 0;
}

List& List::operator=(const char ch){
    clear();
    push_back(ch);

    return *this;
}

List& List::operator=(const char* str){
    clear();
    for(size_t i = 0; str[i] != '\0'; ++i){
        push_back(str[i]);
    }
    push_back('\0');

    return *this;
}

List& List::operator=(const List& r_list){
    if(this != &r_list){
        clear();
        for(size_t i = 0; i < r_list.size; ++i){
            push_back(r_list[i]);
        }
    }
    return *this;
}

List::~List(){
    clear();
    delete first;
    delete last;
}



void List::clear(){
    if(size != 0){
        while(first->get_next() != last){
            delete_node(first->get_next());
        }

        size = 0;
    }

}

bool List::is_empty() const{
    return size == 0;
}

List& List::push_back(const char ch){
    if(size == 0 || last->get_prev()->is_full()){
        Node *new_node = new Node;
        connect_nodes(last->get_prev(), new_node);
        connect_nodes(new_node, last);
    }

    last->get_prev()->push_back(ch);
    size++;

    return *this;
}

void List::pop_back(){
    if(is_empty()){
        throw "List::pop_back() : Cannot delete from empty list";
    }

    last->get_prev()->pop_back();

    if(last->get_prev()->is_empty()){
        delete_node(last->get_prev());
    }

    size--;

}

char& List::operator[](const size_t n) {
    if(n >= size){
        throw "List::operator[] : Out of Range";
    }

    Node* iter;

    size_t node_i = n / 20;

    //Ha közelebb van az elejéhez
    if( node_i <= size/2 ){
        iter = first->get_next();
        for(size_t i = 0; i < node_i; ++i){
            iter = iter->get_next();
        }
    }
    //Ha közelebb van a végéhez
    else{
        iter = last->get_prev();
        for(size_t i = 0; i < size-1-node_i; ++i){
            iter = iter->get_prev();
        }
    }

    return (*iter)[n % 20];
}

const char& List::operator[](const size_t n) const{
    if(n >= size){
        throw "List::operator[] : Out of Range";
    }

    Node* iter;

    size_t node_i = n / 20;

    //Ha közelebb van az elejéhez
    if( node_i <= size/2 ){
        iter = first->get_next();
        for(size_t i = 0; i < node_i; ++i){
            iter = iter->get_next();
        }
    }
    //Ha közelebb van a végéhez
    else{
        iter = last->get_prev();
        for(size_t i = 0; i < size-1-node_i; ++i){
            iter = iter->get_prev();
        }
    }

    return (*iter)[n % 20];
}


///ITERATOR

List::iterator& List::iterator::operator=(const iterator& iter_r){
    if(this != &iter_r){
        ptr = iter_r.ptr;
        ptr_end = iter_r.ptr_end;
        curr_node = iter_r.curr_node;
    }
    return *this;
}



