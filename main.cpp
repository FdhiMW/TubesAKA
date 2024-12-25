//
//  main.cpp
//  Tubes AKA
//
//  Created by Fadhilla on 24/12/24.
//

#include <iostream>
using namespace std;

// Fungsi iteratif untuk menghitung kombinasi
int coinChangeIterative(int coins[], int n, int amount) {
    int dp[1000]; // Pastikan array cukup besar (ubah 1001 sesuai kebutuhan)
    dp[0] = 1; // Satu cara untuk mencapai jumlah 0 (tidak mengambil koin)

    for (int i = 0; i < n; i++) {
           for (int j = 0; j <= amount; j++) { // Iterasi dari 0 ke amount
               if (j >= coins[i]) {
                   dp[j] = dp[j] + dp[j - coins[i]];
               }
           }
       }
    return dp[amount];
}

int coinChangeRecursive(int coins[], int n, int amount) {
    // Basis rekursi
    if (amount == 0) {
        return 1; // Ditemukan satu kombinasi
    }
    if (amount < 0 || n <= 0) {
        return 0; // Tidak ada solusi
    }

    // Rekursi: menggunakan koin terakhir dua kali secara berbeda
    return coinChangeRecursive(coins, n - 1, amount) +
           coinChangeRecursive(coins, n, amount - coins[n - 1]);
}

int main() {
    int coins[] = {1, 3, 5};
    int amount = 5;
    int pilihan;
    
    cout << "=====================================" << endl;
    cout << "1. Iteratif" << endl;
    cout << "2. Rekursif" << endl;
    cout << "=====================================" << endl;
    cin >> pilihan;
    
    if (pilihan == 1) {
        cout << "Jumlah kombinasi (iteratif): "
             << coinChangeIterative(coins, 3, amount) << endl;
    } else {
        cout << "Jumlah kombinasi (rekursif): "
             << coinChangeRecursive(coins, 3, amount) << endl;
    }
    

    return 0;
}

