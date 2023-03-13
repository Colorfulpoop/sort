#include <stdlib.h>
#include <stdio.h>

// funzione per calcolare il valore massimo in un array
int maxVector(int arr[],int size)
{
	int max;
	int i;

	i = 0;
	max = arr[0];
	while (arr[i] > size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		i++;
	}
	return (max);
}

// funzione per effettuare il counting sort su un certo digit
void countingSort(int arr[], int n, int digit) {
	int output[n];
	int bucket[10] = {0};

	// conta il numero di occorrenze di ogni cifra
	int i = 0;
	while (i < n) {
		bucket[(arr[i]/digit)%10]++;
		i++;
	}

	// calcola le posizioni nella sequenza ordinata
    i = 1;
    while (i < 10) {
        bucket[i] += bucket[i-1];
        i++;
    }

    // riordina l'array in base alle posizioni calcolate
    i = n-1;
    while (i >= 0) {
        output[bucket[(arr[i]/digit)%10]-1] = arr[i];
        bucket[(arr[i]/digit)%10]--;
        i--;
    }

    // copia l'array ordinato in quello originale
    i = 0;
    while (i < n) {
        arr[i] = output[i];
        i++;
    }
}

// funzione principale per effettuare la radix sort
void radixSort(int arr[], int n) {
    // trova il massimo valore dell'array
	int max = maxVector(arr, n);

    // effettua counting sort per ogni digit, partendo dalle unità
    int digit = 1;
    while (max/digit > 0) {
        countingSort(arr, n, digit);
        digit *= 10;
    }
}

// funzione di utilità per stampare l'array
void stampaArray(int arr[], int n) {
    int i = 0;
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

int main()
{
	int vettore[] = {180,320,40,211,10};
	int size;

	// calcolo la dimensione di un array
	size = sizeof(vettore)/sizeof(vettore[0]);
	radixSort(vettore, size);
	printf ("Array ordinato : \n");
	stampaArray(vettore, size);

	return (0);
}