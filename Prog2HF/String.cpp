#include "String.h"

String::String(const String& r_str){
    *this = r_str;
}

String& String::operator=(const String& r_str){
    if(this != &r_str){
        str_data = r_str.str_data;
    }
    return *this;
}

void String::swap(){
    for(size_t i = 0; i < length()/2; ++i){
        char temp = str_data[i];
        str_data[i] = str_data[length()-1-i];
        str_data[length()-1-i] = temp;
    }
}

String& String::push_back(const char ch){
    str_data.pop_back();
    str_data.push_back(ch);
    str_data.push_back('\0');
    return *this;
}

void String::pop_back(){
    if(length() == 0) throw "String::pop_back() : Cannot delete from empty String";
    str_data.pop_back();
    str_data.pop_back();
    str_data.push_back('\0');
}

String& String::append( const char *str){
    str_data.pop_back();
    for(size_t i = 0; str[i] != '\0'; ++i){
        str_data.push_back(str[i]);
    }
    str_data.push_back('\0');
    return *this;
}

String& String::append( const String& r_str){
    size_t curr_size;
    if(this == &r_str)
        curr_size = length();
    else
        curr_size = r_str.length();

    str_data.pop_back();

    for(size_t i = 0; i < curr_size+1; ++i){
        str_data.push_back(r_str[i]);
    }

    return *this;
}

char& String::operator[](const size_t n){
    return str_data[n];
}

const char& String::operator[](const size_t n) const{
    return str_data[n];
}

bool String::operator==(const char ch) const{
    if(length() == 1 && str_data[0] == ch)
        return true;
    return false;
}

bool String::operator==(const char* c_str) const{
    size_t c_str_len;
    for(c_str_len = 0; c_str[c_str_len] != '\0'; ++c_str_len);

    bool match = true;
    if(c_str_len == length()){
        for(size_t i = 0; i < length(); ++i){
            if(c_str[i] != str_data[i]){
                match = false;
                break;
            }
        }
    }
    else {
        match = false;
    }

    return match;
}

bool String::operator==(const String& str) const{
    bool match = true;
    if(str.length() == length()){
        for(size_t i = 0; i < length(); ++i){
            if(str[i] != str_data[i]){
                match = false;
                break;
            }
        }
    }
    else {
        match = false;
    }

    return match;
}

std::ostream& operator<<(std::ostream& os, const String& str){
    for(size_t i = 0; i < str.length(); ++i){
        os << str[i];
    }
    return os;
}

