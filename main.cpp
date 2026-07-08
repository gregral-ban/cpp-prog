#include <iostream>
using namespace std;

namespace doboz
{

struct Doboz
{
    string nev;
    unsigned szelesseg;
    unsigned magassag;
    unsigned hosszusag;
};
    // void kiirDobozok(Doboz* tomb, unsigned meret)
    void kiirDobozok(const Doboz* tomb, unsigned meret)
    {
        // tomb[0].nev = "at-irtam-a-tomb-elso-elemet";
        for (unsigned i = 0; i < meret; i++)
        {
            cout << tomb[i].nev << ": ";
            cout << tomb[i].szelesseg << "x";
            cout << tomb[i].magassag << "x";
            cout << tomb[i].hosszusag << endl;

        }
    }

    // Nem másolatot adunk át a dobozokról hanem referenciával
    // közvetlenül az EREDETI OBJEKTUMOT adjuk át neki.
    // Nem történik felesleges másolás.

    // Ha csak simán referencia lenne megadva akkor arra következtethetnénk
    // hogy a függvény vár egy dobozt amit módosíthat is.
    // Mivel nem ez a célunk ezért 'const' kulcsszóval levédjük a módosítás elől.
    // Tehát ez egy konstans referencia lesz.

    /**
     * Összetett adatott akarunk átadni:
     * - Ha akarjuk módosítani akkor sima 'referencia'.
     * - Ha nem akarjuk módosítani akkor 'konstans referencia'.
     */

    // void kiirFelszinTerfogat(Doboz d)
    void kiirFelszinTerfogat(const Doboz &d)
    {
        unsigned felszin = 2 * (d.szelesseg * d.magassag +
                                d.magassag * d.hosszusag +
                                d.hosszusag * d.szelesseg);
        unsigned terfogat = d.szelesseg * d.magassag * d.hosszusag;
        cout << "A(z) \"" << d.nev << "\" doboz felszine: " << felszin << "cm2" << endl;
        cout << "A(z) \"" << d.nev << "\" doboz terfogata: " << terfogat << "cm3" << endl;
        cout << endl;
    }

    // A Doboz tomb-re referencia ként kell hivatkozni, egyébként csak egy másolat lenne
    // Hasonló képpen a meret változoót is referencia ként kell átadni.
    void tombMeretMegnovel(Doboz* &tomb, unsigned &meret, unsigned megnovel)
    {
        // Lefoglalok egy új tömböt a megfelelő nagyobb mérettel.
        Doboz* ujtomb = new Doboz[meret + megnovel];
        // Átmásolok mindent a régiből az újba.
        for (unsigned i = 0; i < meret; i++)
        {
            ujtomb[i] = tomb[i];
        }
        // A régitől megszabadulok.
        delete[] tomb;
        // Majd átállítom a mutatót és a méretet.
        tomb = ujtomb;
        meret += megnovel;
    }
}

using namespace doboz;

int main()
{
    unsigned meret;
    cout << "Mennyi dobozra lesz szukseged?: ";
    cin >> meret;
    Doboz* tomb = new Doboz[meret];
    //Doboz pointerben tároljuk el,  dinamikusan fogalaunk le 'meret' mennyiségű 'Doboz'-t

    for (unsigned i = 0; i < meret; i++)
    {
        cout << i << ". doboz adatai [Nev, Szelesseg, Hosszusag, Magassag]: " << endl;
        cin >> tomb[i].nev >> tomb[i].szelesseg >> tomb[i].magassag >> tomb[i].hosszusag;
    }

    cout << endl;

    kiirDobozok(tomb, meret);

    cout << endl;

    for (unsigned i = 0; i < meret; i++)
        kiirFelszinTerfogat(tomb[i]);

    unsigned novel;

    cin >> novel;
    tombMeretMegnovel(tomb, meret, novel);

    delete[] tomb;
    // dinamikusan lefoglalt tömb felszabadítása.
    return 0;
}