#include <iostream>

namespace Tarolo
{
    /* A struct és a class közötti különbség annyi,
     * hogy a struct alapértlemezetten 'public'-ként kezeli ami belekerül,
     * a class pedig alapértelmezetten 'private' minden ami belekerül.
    */
    // struct Szamok
    class Szamok
    {
        double* tomb;

        /*
     *private:
        //...
    public:
        //...
    */
        /* Ezek az adattagok bizosítják a hozzáférést.
         * Az osztályoknak nem csak adattagjaik vannak hanem metódusaik
         * Tagfüggvényeik is. Osztályon belül lehet függvényt(METÓDUS-t) írni.
         * Ezek bizostítják a publikus interfészt. Amin keresztül a külső kód
         * tudja használi az osztálynak a belső adatait. De csak olyan kontrollált módon,
         * ahogyan azt az osztály megengedi, tehát nem akárhogy.
         *
         * Ezeket akár lehet priváttá tenni,
        */
    public:
        unsigned meret;
        unsigned darabLeker()
        {
            return this->meret;
        }
    };

    // unsigned darabLeker(Szamok &s)
    // {
    //     //..
    // }
}

int main()
{
    Tarolo::Szamok s1;
    Tarolo::Szamok s2;
    s1.meret = 3;
    s2.meret = 8;
    std::cout << s1.darabLeker() << std::endl; // Visszaadja a 'meret'-et.
    std::cout << s2.darabLeker() << std::endl;
    // Tarolo::darabLeker(s);
    return 0;
}
