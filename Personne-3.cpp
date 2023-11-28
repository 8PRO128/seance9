#include <iostream>
using namespace std;

class Personne {
  private:
    int id;
    string nom;

  public:
    Personne(int id, string nom);
    string get_data() const;
    void afficher() const;
};

Personne::Personne(int id, string nom) 
    : id(id), nom(nom) {}

string Personne::get_data() const {
  return to_string(id) + " - " + nom;
}

void Personne::afficher() const {
  cout << get_data() << endl;
}

class Etudiant : public Personne {
  private:
    string cours;
  public:
    Etudiant(int id, string nom, string cours);
    string get_data() const;
};

Etudiant::Etudiant(int id, string nom, string cours)
  : Personne(id, nom), cours(cours) {}

string Etudiant::get_data() const {
  return cours;
}


int main() {
  Personne p1(1, "Eduardo"); // liaison statique
  Etudiant p2(2, "Mathieu", "Informatique"); // liaison statique
  Personne* p3 = new Personne(3, "Felipe"); // liaison dynamique
  Etudiant* p4 = new Etudiant(4, "Maria", "Jeu video"); // liaison dynamique
  Personne* p5 = new Etudiant(5, "Vera", "Jeu video"); // liaison dynamique

  p1.afficher();
  p2.afficher();
  p3->afficher();
  p4->afficher();
  p5->afficher();
}