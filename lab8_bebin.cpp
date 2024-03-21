#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    const int n = 10;
    double arr[n];

    cout << "Введiть " << n << " дiйсних чисел для масиву:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    double sum_dodatniy = 0;
    int kilkist_vidjemniy = 0;

    double max_elem = arr[0], min_elem = arr[0];
    int max_index = 0, min_index = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_elem) {
            max_elem = arr[i];
            max_index = i;
        }
        if (arr[i] < min_elem) {
            min_elem = arr[i];
            min_index = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            sum_dodatniy += arr[i];
        }
        else if (arr[i] < 0) {
            kilkist_vidjemniy++;
        }
    }

    cout << "a) Сума додатних елементiв масиву: " << sum_dodatniy << endl;
    cout << "   Кiлькiсть вiд'ємних елементiв масиву: " << kilkist_vidjemniy << endl;

    double dob = 1;
    int start_index = (max_index < min_index) ? max_index : min_index;
    int end_index = (max_index < min_index) ? min_index : max_index;
    for (int i = start_index + 1; i < end_index; ++i) {
        dob *= arr[i];
    }

 
    cout << "b) Добуток елементiв масиву, розташованих мiж максимальним та мiнiмальним: " << dob << endl;
    cout << "Елементи масиву з 15 послiдовними простими числами:\n";

    int count = 0;
    int num = 2; 
    while (count < 15) {
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << endl;

    return 0;
}
