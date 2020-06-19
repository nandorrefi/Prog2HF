#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

/** @brief A Container osztály 20 db karakter tárolására alkalmas és ezt a tárolót kezeli.
    @author Réfi Nándor
    @date May 2019
*/

class Container
{
    private:
        char data[20]; /**>A 20 db karakter, melyet eltárolunk*/
        size_t size;    /**>Eltárolt karakterek száma*/
        static const size_t capacity; /**>Maximálisan eltárolható karakterek száma*/

    public:
        /**Alapértelmezett konstruktor. Létrehoz egy üres Containert.
        */
        Container() : size(0) { }
        virtual ~Container() { }

        /**Eltárolt karakterek számát adja vissza
            @return Eltárolt karakterek száma
        */
        size_t get_size() const { return size; }
        /**Maximálisan eltárolható karakterek számát adja vissza
            @return Maximálisan eltárolható karakterek száma
        */
        static size_t get_capacity();

        /**Megnézi üres-e a tároló
        @return Üres-e a tároló
        */
        bool is_empty() { return size == 0; }
        /**Megnézi, hogy tele van-e a tároló
        @return Tele van-e a tároló
        */
        bool is_full() { return size == capacity; }
        /**Visszaadja az utolsó elemét a tárolónak
        @return Utolsó eleme
        */
        char& get_last() { return data[size-1]; }
        /**Visszaadja az első elemét a tárolónak
        @return Első eleme
        */
        char& get_first() { return data[0]; }
        /**Visszaadja az utolsó elemét a tárolónak
        @return Utolsó eleme
        */
        const char& get_last() const { return data[size-1]; }
        /**Visszaadja az első elemét a tárolónak
        @return Első eleme
        */
        const char& get_first() const { return data[0]; }

        char& operator[](const size_t n);
        const char& operator[](const size_t n) const;

        /**A tároló végére fűz egy karaktert.
        @param ch - a karakter
        */
        Container& push_back(const char ch);
        /**A tároló végéről töröl egy karaktert.
        */
        void pop_back();

};

#endif // CONTAINER_H
