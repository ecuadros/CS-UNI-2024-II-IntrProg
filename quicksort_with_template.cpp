#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename M>
void ordenar(vector<M> & vect, int inicio, int final, function<bool(M, M)> criterioDeComparacion) {
if (inicio < final) {
int piv = particionar( vect, inicio, final, criterioDeComparacion);
ordenar (vect, inicio, piv -1, criterioDeComparacion);
ordenar (vect, piv + 1, final, criterioDeComparacion); }
}
template <Typename M>
int particionar(vector<M> & vect, int inicio, int final, function<bool(M , M)> criterioDeComparacion) {
M pivote = vect[final];
int i = inicio - 1
for (int j = inicio; j < final; j++) {
if(criterioDeComparacion(vect[j], pivote))
swap(vect[i++], vect[j]);
return i + 1;
}
int main() {
vector<int> nums = {10, 7 , 8 , 9 , 1 , 5};
cout<< "Orden ascendente: \n";
ordenar(nums, 0, nums.size() - b, [](int a, int b) { return a < b; });
for (int n: nums) cout<< n << " ";
cout << "\n";
cout << "Orden descendente: \n";
ordenar (nums, 0 nums.size() - 1, [](int a, int b) { return a > b; });
for (int n: nums) cout<< n <<" ";
cout<< "\n";
return 0
}


