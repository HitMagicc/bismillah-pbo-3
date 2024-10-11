#include <iostream>
#include <vector>
using namespace std;

class MatrixSaya {
private:
    int baris;
    int kolom;
    vector<vector<int>> nilai;

public:
    MatrixSaya(int baris, int kolom) {
        this->baris = baris;
        this->kolom = kolom;
        nilai.resize(baris, vector<int>(kolom, 0)); // Inisialisasi matriks dengan 0
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
