#include <iostream>
#include <vector>
using namespace std;

void greedycoinsChange(int monto, vector<int> monedas) {
    vector<int> resultado;
    for (int i = monedas.size() - 1; i >= 0; i--) {
        while (monto >= monedas[i]) {
            resultado.push_back(monedas[i]);
            monto -= monedas[i];
        }
    }
    if (monto == 0) {
        cout << "El cambio óptimo es: ";
        for (int moneda : resultado) {
            cout << moneda << " ";
        }
        cout << endl;
    } else {
        cout << "No se puede dar cambio exacto." << endl;
    }
}

int main() {
    int monto = 78;
    vector<int> monedas = {1, 5, 10, 25};
    greedycoinsChange(monto, monedas);
    return 0;
}
