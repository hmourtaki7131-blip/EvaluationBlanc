
#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    int numero;
    string titulaire;
    double solde;

public:
    // Constructeur parametre
    CompteBancaire(int num, string nom, double montant) {
        numero = num;
        titulaire = nom;
        solde = montant;
    }

    // Deposer un montant positif
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot effectue avec succes." << endl;
        } else {
            cout << "Montant invalide." << endl;
        }
    }

    // Retirer si le montant est positif et le solde suffisant
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        } else {
            cout << "Retrait impossible." << endl;
        }
    }

    // Afficher les informations du compte
    void afficher() {
        cout << "Numero : " << numero << endl;
        cout << "Titulaire : " << titulaire << endl;
        cout << "Solde : " << solde << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    // Creation de deux comptes
    CompteBancaire c1(101, "Sara", 1000);
    CompteBancaire c2(102, "Amine", 500);

    // Depot et retrait
    c1.deposer(200);
    c2.retirer(100);

    // Affichage des soldes et informations
    c1.afficher();
    c2.afficher();

    return 0;
}
