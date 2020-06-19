#ifndef STRING_H
#define STRING_H

#include "List.h"

/** @brief String osztály, amely dinamikusan tárolja a benne lévő karaktereket. '\0' karakterrel van lezárva.
    Az osztálynak van iterátora. Többek között lehet belőle törölni, hozzáadni karaktereket,
    szövegeket hozzáfűzni, komparálni, indexelni.
    @author Réfi Nándor
    @date May 2019
*/
class String
{
    private:
        List str_data;/**<Itt tároljuk dinamikusan a karaktereket*/
    public:
        typedef List::iterator iterator;/**<A List osztályon belüli iterátort használja fel*/


        /**String elejére állít egy iterátort
            @return String elejére állított iterátor
        */
        iterator begin() {
            return str_data.begin();
        }

        /**
            @return String végére állított iterátor
        */
        iterator end() {
            return str_data.end();
        }

        /**Alapértelmezett konstruktor, amely létrehoz egy üres '\0'-val lezárt Stringet.
        */
        String() {
            str_data.push_back('\0');
        }

        String(const String&);

        String(const char* c_str){
            *this = c_str;
        }

        String(const char val){
            *this = val;
            str_data.push_back('\0');
        }

        virtual ~String() {}

        String& operator=(const String&);

        String& operator=(const char val){
            str_data = val;
            return *this;
        }

        String& operator=(const char* val){
            str_data = val;
            return *this;
        }

        /**
        @return String hossza (lezáró nulla nem számít bele a hosszba)
        */
        size_t size() const { return str_data.get_size()-1; }
        /**
        @return String hossza (lezáró nulla nem számít bele a hosszba)
        */
        size_t length() const { return size(); }
        /**
        Törli a String tartalmát, ezzel létrehozva egy üres Stringet.
        */
        void clear() { str_data.clear(); str_data.push_back('\0'); }
        /**
        @return üres-e a String
        */
        bool empty() const { return size() == 0; }

        /**
        Felcseréli a String tartalmát, pl.: "Alma" -> "amlA".
        */
        void swap();

        /**
        @return String első eleme
        */
        char& front() { return str_data[0]; }
        /**
        @return String első eleme
        */
        const char& front() const { return str_data[0]; }
        /**
        @return String utolsó eleme
        */
        char& back() { return str_data[size()-1]; }
        /**
        @return String utolsó eleme
        */
        const char& back() const { return str_data[size()-1]; }

        /**A String végére fűz egy karaktert.
            @param ch - a karakter
            @return referencia a megváltozott Stringre
        */
        String& push_back(const char ch);
        /**A String végéről töröl 1 karaktert.
        */
        void pop_back();

        /**Hozzáfűz a Stringhez egy c-típusú stringet
        */
        String& append( const char*);
        /**Hozzáfűz a Stringhez egy másik Stringet
        */
        String& append( const String& );

        /**Hozzáfűz a Stringhez egy c-típusú stringet
        */
        String& operator+=(const char* ch){
            return append(ch);
        }
        /**Hozzáfűz a Stringhez egy másik Stringet
        */
        String& operator+=(const String& str){
            return append(str);
        }

        char& operator[](const size_t n);
        const char& operator[](const size_t n) const;

        bool operator==(const char) const;
        bool operator!=(const char ch) const { return !(*this == ch); }

        bool operator==(const char*) const;
        bool operator!=(const char* c_str) const { return !(*this == c_str); }

        bool operator==(const String&) const;
        bool operator!=(const String& str) const { return !(*this == str); }
};

std::ostream& operator<<(std::ostream&, const String&);


#endif // STRING_H
