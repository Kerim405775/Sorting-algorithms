#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

void wypiszTablice(int tablica[], int iloscLiczbWTablicy)
{
    for (int i = 0; i < iloscLiczbWTablicy; i++)
        cout << tablica[i] << " ";
    cout << endl;
}

void selectionSort(int tablica[], int iloscLiczbWTablicy)
{
    int i, j, min_idx;
    for (i = 0; i < iloscLiczbWTablicy-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < iloscLiczbWTablicy; j++)
        {
            if (tablica[j] < tablica[min_idx])
                min_idx = j;
        }
        if (min_idx!=i)
        {
            int zmiennaPomocnicza = tablica[min_idx];
            tablica[min_idx] = tablica[i];
            tablica[i] = zmiennaPomocnicza;
        }
    }
}

void insertionSort(int tablica[], int iloscLiczbWTablicy)
{
    int i, j, zmiennaPomocnicza;
    for (i = 1; i < iloscLiczbWTablicy; i++)
    {
        zmiennaPomocnicza = tablica[i];
        j = i - 1;
        while (j >= 0 && tablica[j] > zmiennaPomocnicza)
        {
            tablica[j + 1] = tablica[j];
            j = j - 1;
        }
        tablica[j + 1] = zmiennaPomocnicza;
    }
}

void generowanieLiczbPseudolosowych(int *tablica, int iloscLiczbWTablicy)
{
    srand (time (NULL));
    for (int i = 0; i < iloscLiczbWTablicy; i++)
    {
        tablica[i] = rand () % 100000 + 1;
    }
}

double mierzenieCzasuSortowania(void (*algorytmSortujacy)(int*, int), int *tablica, int iloscLiczbWTablicy)
{
    auto start = chrono::high_resolution_clock::now();
    algorytmSortujacy(tablica, iloscLiczbWTablicy);
    auto stop = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(stop - start).count();
}


int main ()
{
    cout << "Porownanie czasow sortowania v.2" << endl;
    cout << "Ilosc liczb losowych w tablicy: ";
    int iloscLiczbWTablicy;
    cin >> iloscLiczbWTablicy;
    cout << endl;
    int *tablica = new int[iloscLiczbWTablicy];
    int *tablica2 = new int[iloscLiczbWTablicy];

    generowanieLiczbPseudolosowych(tablica, iloscLiczbWTablicy);
    for (int i = 0; i < iloscLiczbWTablicy; i++)
    {
        tablica2[i] = tablica[i] ;
    }
    cout << "Selectionsort. Prosze czekac!" << endl;
    wypiszTablice(tablica, iloscLiczbWTablicy);
    double czas = mierzenieCzasuSortowania(selectionSort, tablica, iloscLiczbWTablicy);
    cout << endl << "Czas selectionsort: " << czas << " ms" << endl;
    cout << endl;

    cout << "Insertionsort. Prosze czekac!" << endl;
    wypiszTablice(tablica, iloscLiczbWTablicy);
    czas = mierzenieCzasuSortowania(insertionSort, tablica2, iloscLiczbWTablicy);
    cout << endl << "Czas insertionsort: " << czas << " ms" << endl;
    cout << endl;


    delete[] tablica;
    delete[] tablica2;


    return 0;
}