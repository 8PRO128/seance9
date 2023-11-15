class Animal {
  public:
    void manger(){}
    void se_deplacer(){}
    Animal(int age) {}
};

class Mammifere : public Animal {
  public:
    void allaiter(){}
    Mammifere() : Animal(0) {}
};

class Chien : public Mammifere {
  public:
    void aboyer(){}
    Chien() : Mammifere() {}
};

int main() {
  Animal animal(0);
  animal.manger();
  animal.se_deplacer();

  Mammifere animal2;
  animal2.manger();
  animal2.se_deplacer();
  animal2.allaiter();

  Chien animal3;
  animal3.manger();
  animal3.se_deplacer();
  animal3.allaiter();
  animal3.aboyer();

  return 0;
}