#include <iostream>
using namespace std;

class Personne {
  private:
    int id;
    string nom;

  public:
    Personne();
    Personne(int id, string nom);
};

Personne::Personne() {}

Personne::Personne(int id, string nom) 
    : id(id), nom(nom) {}

int main() {
  Personne p1; // liaison statique
  Personne p2(1, "Eduardo"); // liaison statique
  Personne* p3 = new Personne(); // liaison dynamique
  Personne* p4 = new Personne(2, "Felipe"); // liaison dynamique
}

