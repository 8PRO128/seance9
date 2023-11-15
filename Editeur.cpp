#include <iostream>
using namespace std;

class ÉditeurDeTexte {
public:
    virtual string traiterTexte(const string& texte) {
        return "[TRAITÉ] : " + texte;
    }
};

class ÉditeurEnMinuscules : public ÉditeurDeTexte {
public:
    string traiterTexte(const string& texte) override {
        string texteDeBase = ÉditeurDeTexte::traiterTexte(texte); // Appelle la fonction de la superclasse
        transform(texteDeBase.begin(), texteDeBase.end(), texteDeBase.begin(), ::tolower);
        return texteDeBase;
    }
};

class ÉditeurEnMajuscules : public ÉditeurDeTexte {
public:
    string traiterTexte(const string& texte) override {
        string texteDeBase = ÉditeurDeTexte::traiterTexte(texte); // Appelle la fonction de la superclasse
        transform(texteDeBase.begin(), texteDeBase.end(), texteDeBase.begin(), ::tolower);
        return texteDeBase;
    }
};

class ÉditeurHTML : public ÉditeurDeTexte {
public:
    string traiterTexte(const string& texte) override {
        string texteDeBase = ÉditeurDeTexte::traiterTexte(texte); // Appelle la fonction de la superclasse
        return "<html><body>" + texteDeBase + "</body></html>";
    }
};