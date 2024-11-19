#include <iostream>
#include <vector>
using namespace std;

struct Alumno { int dia, mes; string nombre; };

template <typename T>
void ordenar(vector<T>& vect, int inicio, int final, bool (*cmp)(T, T)) {
    if (inicio < final) {
        int piv = particionar(vect, inicio, final, cmp);
        ordenar(vect, inicio, piv - 1, cmp);
        ordenar(vect, piv + 1, final, cmp);
    }
}

template <typename T>
int particionar(vector<T>& vect, int inicio, int final, bool (*cmp)(T, T)) {
    T piv = v[final]; int i = inicio - 1;
    for (int j = inicio; j < final; j++) if (cmp(vect[j], piv)) swap(vect[++i], vect[j]);
    swap(vect[i + 1], vect[final]);
    return i + 1;
}

int main() {
    vector<Alumno> a = {{15, 5, "Ana"}, {20, 5, "Juan"}, {10, 6, "Carlos"}, {5, 5, "Marta"}, {25, 6, "Luis"}};
    
    ordenar(a, 0, a.size() - 1, [](Alumno &x, Alumno &y) { return x.mes < y.mes || (x.mes == y.mes && x.dia < y.dia); });
    for (auto& x : a) cout << x.nombre << " (" << x.dia << "/" << x.mes << ")\n";

    ordenar(a, 0, a.size() - 1, [](Alumno &x, Alumno &y) { return x.mes > y.mes || (x.mes == y.mes && x.dia > y.dia); });
    for (auto& x : a) cout << x.nombre << " (" << x.dia << "/" << x.mes << ")\n";

    return 0;
}
