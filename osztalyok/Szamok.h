// MS Visual Studio-ban header guard
#pragma once
// Más fordítók által használt header gurad
// #ifndef _SZAMOK_H
// #define _SZAMOK_H
// class Szamok
// {

// };

// #endif
namespace Tarolo
{
    class Szamok
    {
        unsigned meret = 0;
        double* tomb = nullptr;

        public:
            Szamok(unsigned pmeret, double ertek = 0.0);
            Szamok(const Szamok& masik);
            ~Szamok();

            unsigned darabLeker() const;
            void ertekBeallit(unsigned index, double ertek);
            double ertekLeker(unsigned index) const;
    };
}
