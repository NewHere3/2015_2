#include <iostream>
#include <fstream>

using namespace std;

struct avis
{
    string name = "Error";
    string DNR = "Error";
    int k = 0;
};

void read(avis& tiriamoji, avis avys[20], int& n, int& m)
{
    int temp;
    ifstream duom("Duomenys.txt");
    duom >> n >> m >> temp;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == temp)
        {
            char temp[11];
            duom.ignore();
            duom.get(temp, 11);
            tiriamoji.name = temp;
            duom >> tiriamoji.DNR;
        }
        else
        {
            char temp[11];
            duom.ignore();
            duom.get(temp, 11);
            avys[j].name = temp;
            duom >> avys[j].DNR;
            j++;
        }
    }
    n--;
    duom.close();
}

void koeficientas(avis tiriamoji, avis& lyginama, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tiriamoji.DNR[i]==lyginama.DNR[i])
        {
            lyginama.k++;
        }
    }
}

void mysort(avis arr[], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (arr[k].k > arr[j].k)
            {
                swap(arr[k], arr[j]);
            }
            if (arr[k].k == arr[j].k)
            {
                if (arr[k].name < arr[j].name)
                {
                    swap(arr[k], arr[j]);
                }
            }
        }
    }
}

void write(avis tiriamoji, avis avys[], int n)
{
    ofstream rez("Rezultatai.txt");
    rez << tiriamoji.name << '\n';

    for (int i = 0; i < n; i++)
    {
        rez << avys[i].name << ' ';
        rez << avys[i].k << '\n';
    }
    rez.close();
}

int main()
{
    avis tiriamoji;
    avis avys[20];
    int n = 0, m = 0;
    read(tiriamoji, avys, n, m);
    for (int i = 0; i < n; i++)
    {
        koeficientas(tiriamoji, avys[i], m);
    }
    mysort(avys, n);
    write(tiriamoji, avys, n);
    return 0;
}