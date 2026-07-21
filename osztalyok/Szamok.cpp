#include "Szamok.h"
namespace Tarolo
{
    Szamok::Szamok(unsigned pmeret, double ertek) :
        meret(pmeret),
        tomb(new double[pmeret])
    {
        for(unsigned i = 0; i < meret; i++)
            tomb[i] = ertek;
    }

    Szamok::Szamok(const Szamok& masik) :
        meret(masik.meret),
        tomb(new double[meret])
    {
        for(unsigned i = 0; i < meret; i++)
            tomb[i] = masik.tomb[i];
    }

    Szamok::~Szamok()
    {
        delete[] tomb;
    }

    unsigned Szamok::darabLeker() const
    {
        return meret;
    }

    void Szamok::ertekBeallit(unsigned index, double ertek)
    {
        if (index < meret)
            tomb[index] = ertek;
    }

    double Szamok::ertekLeker(unsigned index) const
    {
        if(index < meret)
            return tomb[index];
        else
            return -1e8;
    }
}