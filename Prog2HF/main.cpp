#include <iostream>
#include <stdexcept>
#include "String.h"
#include <string>

/** @brief Itt találhatóak a tesztesetek, melyeket a programon
            belül a sorszámaikkal lehet meghívni a standard bemeneten.
    @author Réfi Nándor
    @date May 2019
*/

using namespace std;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

/**Konstruktorok működése
*/
void test_1(){

    String str1('a');
    String str2("hello world");
    String str3 = str1;
    str1 = str2;
    cout << str1 << endl << str2 << endl << str3 << endl;
}

/**Indexelő operátor működése
*/
void test_2(){
    String str1("Megszentesgtelenithetetlensegeskedeseitekert");
    for(size_t i = 0; i < str1.length(); ++i)
        cout << str1[i];

    for(size_t i = 0; i < str1.length(); ++i)
        str1[i] = 'a';

    cout << endl;

    for(size_t i = 0; i < str1.size(); ++i)
        cout << str1[i];

    cout << endl;
}

/**100 elemű dinamikus tömb
*/
void test_3(){
    String * strs = new String[100];

    for(size_t i = 0; i < 100; ++i){
        strs[i] = "test_3_test_3_test_3";
        cout << i << " " << strs[i] << endl;
    }

    delete[] strs;
}

/**Append, push_back, pop_back és += operátor
*/
void test_4(){
    String str1 = "First";
    str1.push_back(' ');
    str1.append("Second");

    String str2 = str1;
    str2 += str2 += str2;

    cout << "Str1: " << str1 << endl;
    cout << "Str2: " << str2 << endl;
}

/** Clear, empty és swap*/
void test_5(){
    String str;

    cout << "Empty str: " << str << ", empty: " << str.empty() << endl;

    str = "test_string";

    cout << "Not empty str: " << str << ", empty: " << str.empty() << endl;

    str.clear();

    cout << "Cleared str: " << str << ", empty: " << str.empty() << endl;

    str += "appended_str";

    cout << "Filled str: " << str << ", empty: " << str.empty() << endl;

    str.swap();

    cout << "After swap: " << str << ", empty: " << str.empty() << endl;

}

/** Túlindexelés és üres listából törlés*/
void test_6(){
    String str1 = "asd";

    try{
        str1[6] = 'd';
    }
    catch (const char* c_str){
        cout << c_str << endl;
    }

    try{
        size_t len = str1.length();
        for(size_t i = 0; i < len+1; ++i){

            cout << "LENGTH: " << str1.length() << endl;
            str1.pop_back();
        }
    }
    catch (const char* c_str){
        cout << c_str << endl;
    }
}

/** Iterátorkezelés*/
void test_7(){

    String str2 = "Tesztelesre szant sztring";
    String str = str2;

    cout << "Elorefele" << endl;

    String::iterator iter;
    for(iter = str.begin(); iter != str.end(); ++iter){
        cout << *iter << endl;
    }

    cout << "\nVisszafele" << endl;
    for(; iter != str.begin(); --iter){
        cout << *iter << endl;
    }

}

/** Logikai egyenlőség operátorok.*/
void test_8(){
    String str1 = "a";

    String str2 = "Testing";

    cout << str1 << " != " << "T : " << (str1 != 'T') << endl;

    cout << str1 << " == " << "a : " << (str1 == 'a') << endl;

    cout << str2 << " == " << "Testinga : " << (str2 == "Testinga") << endl;

    cout << str2 << " != " << "Testing : " << (str2 != "Testing") << endl;

    str1 = "Testing0";
    cout << str2 << " == " << str1 << " : " << (str2 == str1) << endl;

    str1 = "Testing";
    cout << str2 << " != " << str1 << " : " << (str2 != str1) << endl;
}

int main(){
    try {
        cout << "Adja meg melyik tesztesetet szeretne futtatni (1-8)" << endl;
        int nr;
        cin >> nr;
        while( nr != 0){
            cout << "---TESZTESET---" << endl;
            switch (nr) {
                case 1:
                    cout << "Konstruktorok:" << endl;
                    test_1();   // konstruktorok működése
                break;

                case 2:
                    cout << "Indexelo operator:" << endl;
                    test_2();   // indexelő operátor működése
                break;

                case 3:
                    cout << "100 elemu dinamikus tomb:" << endl;
                    test_3();   // 100 elemű dinamikus tömb
                break;

                case 4:
                    cout << "Append, push_back, pop_back es += operator:" << endl;
                    test_4();   // append, push_back, pop_back és += operátor
                break;

                case 5:
                    cout << "Clear, empty es swap:" << endl;
                    test_5();   // clear, empty, swap
                break;

                case 6:
                    cout << "Tulindexeles es ures listabol torles" << endl;
                    test_6();   // túlindexelés és üres listából törlés
                break;

                case 7:
                    cout << "Iteratorkezeles" << endl;
                    test_7();   // iterátorkezelés
                break;

                case 8:
                    cout << "Logikai egyenloseg" << endl;
                    test_8();   // logikai egyenlőség operátorok
                break;

                default:
                    cout << "Hiba: Nincs ilyen teszteset" << endl;
                break;
            }
            cout << "---TESZTESET VEGE---" << endl;
            cin >> nr;
        }

        // kivétel elkapása
        } catch (std::exception& e) {
            cerr << "\nVaratlan hiba: " << e.what() << endl;
        } catch(const char * str){
            cerr << "\nVaratlan hiba: " << str << endl;
        } catch (...) {
            cerr << "\nIsmeretlen varatlan hiba" << endl;
        }

    cout << ">KILEPES<" << endl;
    return 0;
}
