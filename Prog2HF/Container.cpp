#include "Container.h"

const size_t Container::capacity = 20;

size_t Container::get_capacity() { return capacity; }

Container& Container::push_back( const char ch) {
    if(is_full()) throw "Container: is full";
    data[size++] = ch;

    return *this;
}

void Container::pop_back(){
    if(is_empty()) throw "Container: is empty";
    size--;
}

char& Container::operator[](const size_t n){
    if(n >= size) throw "Container: out of range";
    return data[n];
}
const char& Container::operator[](const size_t n) const{
    if(n >= size) throw "Container: out of range";
    return data[n];
}

