#include <stdio.h>
#include <math.h>
    //Binom fonksiyonu: (x+y)^n= k=0'dan n'e kadar olan toplam  n!/(k!(n-k)!)*x'(n-k)*y^k deðeri þeklinde formülle tanýmlayalým

// En baþta faktöriyel hesaplama fonksiyonu ile baþlayalým
int faktoryel(int n) {
	int i;
    int result = 1;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Þimdi de binom katsayýsýný hesaplayan fonksiyonu yazalým
    BinomKatsayisi(int n, int k) {
    return faktoryel(n) / (faktoryel(k) * faktoryel(n - k));
}

// Sýra geldi binom açýlýmýný yazdýran fonksiyona
void BinomAcilimi(int n, int x, int y) {
    int k,i;
	for (k = 0; k <= n; k++) {
        int katsayi = BinomKatsayisi(n, k);
        int xDegeri = 1;
        int yDegeri = 1;

        
        for (i = 0; i < (n - k); i++) {
            xDegeri *= x;
        }
        
        
        for (i = 0; i < k; i++) {
            yDegeri *= y;
        }
        
        if (k > 0) printf(" + ");
        printf("%d%c^%d * %d^%d", katsayi, x, (n - k), y, k);
    }
    printf("\n");
}

int main() {
    int n, x, y;

    
    printf("Sirasi ile n, x ve y degerlerini girin : "); //Þimdi kullanýcýdan binom fonksiyonunun deðerlerini alalým
    scanf("%d %d %d", &n, &x, &y);

    BinomAcilimi(n, x, y);

    return 0;
}
