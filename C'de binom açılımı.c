#include <stdio.h>
#include <math.h>
    //Binom fonksiyonu: (x+y)^n= k=0'dan n'e kadar olan toplam  n!/(k!(n-k)!)*x'(n-k)*y^k degeri seklinde formulle tanımlayalım
    //Bizden istenen ornek x^3*y^0+3x^2*y+3x*y^2+y^3 seklinde olmasi

// En basta faktoriyel hesaplama fonksiyonu ile baslayalim
int faktoryel(int n) {
	int i;
    int result = 1;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Simdi de binom katsayisini hesaplayan fonksiyonu yazalim
    BinomKatsayisi(int n, int k) {
    return faktoryel(n) / (faktoryel(k) * faktoryel(n - k));
}

// Sira geldi binom acilimini yazdiran fonksiyona
void BinomAcilimi(int n, int x, int y) {
    int k,i;
	for (k = 0; k <= n; k++) {
        int katsayi = BinomKatsayisi(n, k);
        int xDegeri = 1;
        int yDegeri = 1;

        
        for (i = 0; i < k; i++) {
            xDegeri *= x;
        }
        
        
        for (i = 0; i < ( k - n ); i++) {
            yDegeri *= y;
        }
        
        if (k > 0) printf(" + ");
        printf("%dx^%d * y^%d", katsayi, (n - k), k);
    }
    printf("\n");
}

int main() {
    int n, x, y;

    
    printf("Acilimini ogrenmek istediginiz us degerini (n) girin : "); //Simdi kullanicidan binom fonksiyonunun degerlerini alalım
    scanf("%d", &n );

    BinomAcilimi(n, x, y);

    return 0;
}
