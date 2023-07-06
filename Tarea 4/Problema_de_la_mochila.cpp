#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
    public:
        int peso;
        int valor;
};

bool comparar_proporcion(Item a, Item b) {
    double ratioA = (double)a.valor / a.peso;
    double ratioB = (double)b.valor / b.peso;
    return ratioA > ratioB;
}

double greedyKnapsack(int capacidad, vector<Item>& items) {
    sort(items.begin(), items.end(), comparar_proporcion);

    double valor_total = 0.0;
    int PI = 0;

    for (const Item& item : items) {
        if (PI + item.peso <= capacidad) {
            PI += item.peso;
            valor_total += item.valor;
        } else {
            int peso_restante = capacidad - PI;
            valor_total += item.valor * ((double)peso_restante / item.peso);
            break;
        }
    }

    return valor_total;
}

int main() {
    int capacidad = 50;
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    double maxvalor = greedyKnapsack(capacidad, items);

    cout << "El valor máximo obtenido es: " << maxvalor << endl;

    return 0;
}
