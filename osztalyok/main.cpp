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
        double* tomb = nullptr;

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
        unsigned meret = 0;

        public:
            // Szamok()
            // {
            //     std::cout << ">> Konstruktor letrejon <<" << std::endl;
            // }

            // Szamok(unsigned pmeret)
            // {
            //     meret = pmeret;
            //     tomb = new double[meret];
            // }

            Szamok(unsigned pmeret) :
                meret(pmeret),
                tomb(new double[pmeret])
            {
            }
            // Destruktor
            // ~[Osztály neve]
            // Paraméter nélküli függvény
            ~Szamok()
            {
                delete[] tomb;
            }

            unsigned darabLeker()
            {
                return meret;
            }

            void ertekBeallit(unsigned index, double ertek)
            {
                if (index < meret)
                    tomb[index] = ertek;
            }

            double ertekLeker(unsigned index)
            {
                if(index < meret)
                    return tomb[index];
            }
    };

    // unsigned darabLeker(Szamok &s)
    // {
    //     //..
    // }
}

int main()
{
    // Tarolo::Szamok s1;
    // Tarolo::Szamok s2;

    Tarolo::Szamok s1(4);
    Tarolo::Szamok s2(8);
    std::cout << s1.darabLeker() << std::endl; // Visszaadja a 'meret'-et.
    std::cout << s2.darabLeker() << std::endl;
    // Tarolo::darabLeker(s);

    // Tarolo::Szamok* p = new Tarolo::Szamok(10);
    // delete *p;
    return 0;
}
