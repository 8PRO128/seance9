#include <iostream>
using namespace std;

class Personne {
  private:
    int id;
    string nom;

  public:
    Personne();
    Personne(int id, string nom);

    virtual void afficher() const;
};

Personne::Personne() {}
Personne::Personne(int id, string nom) 
    : id(id), nom(nom) {}


void Personne::afficher() const{
  cout << id << " - " << nom << endl;
}

class Etudiant : public Personne {
  private:
    string cours;
  public:
    Etudiant(string cours);
    void afficher() const;
};

Etudiant::Etudiant(string cours): cours(cours) {}

void Etudiant::afficher() const {
  cout << cours << endl;
}

int main() {
  Personne p1(1, "Eduardo"); // liaison statique
  Etudiant p2("Informatique");
  Personne* p3 = new Personne(2, "Felipe"); // liaison dynamique
  Etudiant* p4 = new Etudiant("Jeu video"); // liaison dynamique
  Personne* p5 = new Etudiant("Jeu video"); // liaison dynamique

  p1.afficher();
  p2.afficher();
  p3->afficher();
  p4->afficher();
  p5->afficher();

  delete p3;
  delete p4;
  delete p5;
}