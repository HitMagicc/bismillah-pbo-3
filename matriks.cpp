#include <iostream>
using namespace std;

class MatrixSaya {
private:
    int baris;
    int kolom;
    int** nilai;

public:
    MatrixSaya(int baris, int kolom) {
        this->baris = baris;
        this->kolom = kolom;
        nilai = new int*[baris];
        for (int i = 0; i < baris; i++) {
            nilai[i] = new int[kolom];
            for (int j = 0; j < kolom; j++) {
                nilai[i][j] = 0; // Initialize matrix with 0
            }
        }
    }

    ~MatrixSaya() {
        for (int i = 0; i < baris; i++) {
            delete[] nilai[i];
        }
        delete[] nilai;
    }

    void isiMatrix() {
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                cout << "Masukkan Nilai Matriks ke baris " << (i + 1) << " dan kolom " << (j + 1) << ": ";
                cin >> nilai[i][j];
            }
        }
    }

    void cetakMatrix() {
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                cout << nilai[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    MatrixSaya addMatrix(MatrixSaya& matriksLain) {
        MatrixSaya hasilTambah(baris, kolom);
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                hasilTambah.nilai[i][j] = nilai[i][j] + matriksLain.nilai[i][j];
            }
        }
        return hasilTambah;
    }
};

int main() {
    MatrixSaya hidup(3, 3);
    MatrixSaya mati(3, 3);
    
    hidup.isiMatrix();
    mati.isiMatrix();

    MatrixSaya tengah = hidup.addMatrix(mati);

    cout << "Mencetak Matrix Pertama" << endl;
    hidup.cetakMatrix();

    cout << "Mencetak Matrix Kedua" << endl;
    mati.cetakMatrix();

    cout << "Mencetak Matrix Penjumlahan" << endl;
    tengah.cetakMatrix();

    return 0;
}
