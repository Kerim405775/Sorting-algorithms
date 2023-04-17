#include <iostream>
#include <chrono>

using namespace std;

void wypiszTablice(int tablica[], int iloscLiczbWTablicy)
{
    for (int i = 0; i < iloscLiczbWTablicy; i++)
        cout << tablica[i] << " " ;
    cout << endl;
}

void selectionSort(int tablica[], int iloscLiczbWTablicy)
{
    int i, j, najmniejszyIndeks;
    for (i = 0; i < iloscLiczbWTablicy - 1; i++)
    {
        najmniejszyIndeks = i;
        for (j = i+1; j < iloscLiczbWTablicy; j++)
        {
            if (tablica[j] < tablica[najmniejszyIndeks])
                najmniejszyIndeks = j;
        }
        if (najmniejszyIndeks != i)
        {
            int zmiennaPomocnicza = tablica[najmniejszyIndeks];
            tablica[najmniejszyIndeks] = tablica[i];
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

void bubbleSort(int tablica[], int iloscLiczbWTablicy)
{
    int i, j;
    for (i = 1; i < iloscLiczbWTablicy; i++)
    {
        for (j = iloscLiczbWTablicy - i; j >= 1; j--)
            if (tablica[j] < tablica[j - 1])
            {
                int zmiennaPomocnicza = tablica[j - 1];
                tablica[j - 1] = tablica[j];
                tablica[j] = zmiennaPomocnicza;
            }
    }

}

void quickSort (int tablica[], int start, int koniec)
{
    int elementPodzialu = tablica[(start + koniec) / 2];
    int i, j, zmiennaPomocnicza;
    i = start;
    j = koniec;
    do
    {
        while (tablica[i] < elementPodzialu)
            i++;
        while (tablica[j] > elementPodzialu)
            j--;

        if (i <= j)
        {
            zmiennaPomocnicza = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = zmiennaPomocnicza;
            i++;
            j--;
        }
    }
    while (i <= j);

    if (j > start)
        quickSort (tablica, start, j);
    if (i < koniec)
        quickSort (tablica, i, koniec);
}

void scal(int tablica[], int start, int srodek, int koniec)
{
    int *tablicaPomocnicza = new int[(koniec - start + 1)];
    int i = start, j = srodek + 1, k = 0;

    while (i <= srodek && j <= koniec)
    {
        if (tablica[j] < tablica[i])
        {
            tablicaPomocnicza[k] = tablica[j];
            j++;
        }
        else
        {
            tablicaPomocnicza[k] = tablica[i];
            i++;
        }
        k++;
    }

    if (i <= srodek)
    {
        while (i <= srodek)
        {
            tablicaPomocnicza[k] = tablica[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= koniec)
        {
            tablicaPomocnicza[k] = tablica[j];
            j++;
            k++;
        }
    }

    for (i = 0; i <= koniec - start; i++)
    {
        tablica[start + i] = tablicaPomocnicza[i];
    }

    delete[] tablicaPomocnicza;
}

void mergeSort(int tablica[], int start, int koniec)
{
    int srodek;

    if (start != koniec)
    {
        srodek = (start + koniec) / 2;
        mergeSort(tablica, start, srodek);
        mergeSort(tablica, srodek + 1, koniec);
        scal(tablica, start, srodek, koniec);
    }
}

int main ()
{
    //inicjowanie generatora liczb pseudolosowych
    srand (time (NULL));

    cout << "Porownanie czasow sortowania v.2" << endl;
    cout << "Ilosc liczb losowych w tablicy: ";
    int iloscLiczbWTablicy;
    cin >> iloscLiczbWTablicy;
    cout << endl;

    //dynamiczna alokacja tablicalicy
    int *tablica = new int[iloscLiczbWTablicy];
    int *tablica2 = new int[iloscLiczbWTablicy];
    int *tablica3 = new int[iloscLiczbWTablicy];
    int *tablica4 = new int[iloscLiczbWTablicy];
    int *tablica5 = new int[iloscLiczbWTablicy];

    //wczytywanie losowych liczb do tablicy
    for (int i = 0; i < iloscLiczbWTablicy; i++)
    {
        tablica[i] = rand () % 100000 + 1;
    }

    for (int i = 0; i < iloscLiczbWTablicy; i++)
    {
        tablica5[i] = tablica4[i] = tablica3[i] = tablica2[i] = tablica[i] ;
    }


    cout << "Selectionsort. Prosze czekac!" << endl;
    auto start = chrono::high_resolution_clock::now ();
    selectionSort (tablica, iloscLiczbWTablicy);
    auto stop = chrono::high_resolution_clock::now ();
    //wypiszTablice(tablica, iloscLiczbWTablicy);
    double czas = chrono::duration_cast<chrono::milliseconds> (stop - start).count ();
    cout << endl << "Czas selectionsort: " << czas << " ms" << endl;
    cout << endl;

    cout << "Insertionsort. Prosze czekac!" << endl;
    start = chrono::high_resolution_clock::now ();
    insertionSort (tablica2, iloscLiczbWTablicy);
    stop = chrono::high_resolution_clock::now ();
    //wypiszTablice(tablica, iloscLiczbWTablicy);
    czas = chrono::duration_cast<chrono::milliseconds> (stop - start).count ();
    cout << endl << "Czas insertionsort: " << czas << " ms" << endl;
    cout << endl;

    cout << "Bubblesort. Prosze czekac!" << endl;
    start = chrono::high_resolution_clock::now ();
    bubbleSort (tablica, iloscLiczbWTablicy);
    stop = chrono::high_resolution_clock::now ();
    //wypiszTablice(tablica, iloscLiczbWTablicy);
    czas = chrono::duration_cast<chrono::milliseconds> (stop - start).count ();
    cout << endl << "Czas bubblesort: " << czas << " ms" << endl;
    cout << endl;

    cout << "QuickSort. Prosze czekac!" << endl;
    start = chrono::high_resolution_clock::now ();
    quickSort (tablica, 0, iloscLiczbWTablicy - 1);
    stop = chrono::high_resolution_clock::now ();
    //wypiszTablice(tablica, iloscLiczbWTablicy);
    czas = chrono::duration_cast<chrono::milliseconds> (stop - start).count ();
    cout << endl << "Czas quicksort: " << czas << " ms" << endl;
    cout << endl;

    cout << "MergeSort. Prosze czekac!" << endl;
    start = chrono::high_resolution_clock::now ();
    mergeSort (tablica, 0, iloscLiczbWTablicy - 1);
    stop = chrono::high_resolution_clock::now ();
    //wypiszTablice(tablica, iloscLiczbWTablicy);
    czas = chrono::duration_cast<chrono::milliseconds> (stop - start).count ();
    cout << endl << "Czas mergesort: " << czas << " ms" << endl;
    cout << endl;

    delete[] tablica;
    delete[] tablica2;
    delete[] tablica3;
    delete[] tablica4;
    delete[] tablica5;

    return 0;
}

