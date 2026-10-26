
#include <iostream>
#include <string>
using namespace std;

// Classe mere
class Vehicule {
protected:
    string immatriculation;
    string marque;
    double vitesseMax;

public:
    // Constructeur parametre
    Vehicule(string immat, string marq, double vitesse) {
        immatriculation = immat;
        marque = marq;
        vitesseMax = vitesse;
    }

    // Methode virtuelle
    virtual void afficherDetails() {
        cout << "Immatriculation : " << immatriculation << endl;
        cout << "Marque : " << marque << endl;
        cout << "Vitesse maximale : " << vitesseMax << " km/h" << endl;
    }

    // Destructeur virtuel
    virtual ~Vehicule() {}
};

// Classe derivee Voiture
class Voiture : public Vehicule {
private:
    int nombrePortes;
    string typeCarburant;

public:
    Voiture(string immat, string marq, double vitesse,
            int portes, string carburant)
        : Vehicule(immat, marq, vitesse) {
        nombrePortes = portes;
        typeCarburant = carburant;
    }

    void afficherDetails() override {
        cout << "--- Voiture ---" << endl;
        Vehicule::afficherDetails();
        cout << "Nombre de portes : " << nombrePortes << endl;
        cout << "Type de carburant : " << typeCarburant << endl;
    }
};

// Classe derivee Camion
class Camion : public Vehicule {
private:
    double capaciteCharge;
    int nombreEssieux;

public:
    Camion(string immat, string marq, double vitesse,
           double capacite, int essieux)
        : Vehicule(immat, marq, vitesse) {
        capaciteCharge = capacite;
        nombreEssieux = essieux;
    }

    void afficherDetails() override {
        cout << "--- Camion ---" << endl;
        Vehicule::afficherDetails();
        cout << "Capacite de charge : " << capaciteCharge << " tonnes" << endl;
        cout << "Nombre d'essieux : " << nombreEssieux << endl;
    }
};

int main() {
    // Creation des objets
    Voiture v1("123-A-45", "Dacia", 180, 5, "Essence");
    Camion c1("456-B-78", "Volvo", 120, 20.5, 4);

    // Tableau de pointeurs vers la classe mere
    Vehicule* vehicules[2];
    vehicules[0] = &v1;
    vehicules[1] = &c1;

    // Polymorphisme
    for (int i = 0; i < 2; i++) {
        vehicules[i]->afficherDetails();
        cout << "-------------------" << endl;
    }

    return 0;
}
