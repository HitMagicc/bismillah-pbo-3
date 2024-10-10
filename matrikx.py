class MatrixSaya:   
    def __init__(self,baris,kolom):
        self.baris=baris
        self.kolom=kolom
        self.nilai= [[0 for _ in range(kolom)] for _ in range(baris)]
    
    def isi_matrix(self):
        for i in range(self.baris):
            for j in range(self.kolom):
                self.nilai[i][j]=int(input(f"Masukkan Nilai Matriks ke baris {i+1} dan masukkan kolom {j+1} \n"))
    
    def cetak_matrix(self):
        for i in range(self.baris):
            for j in range(self.kolom):
                print(self.nilai[i][j], end=" ")
            print()
        print()
            
    def add_matrix(self, matriks_lain):
        hasilTambah=MatrixSaya(self.baris,self.kolom)
        for i in range(self.baris):
            for j in range(self.kolom):
                hasilTambah.nilai[i][j] = self.nilai[i][j] + matriks_lain.nilai[i][j]
        return hasilTambah
    
if __name__ == "__main__":
    hidup = MatrixSaya(3,3)
    mati = MatrixSaya(3,3)
    tengah = MatrixSaya(3,3)
    
    hidup.isi_matrix()
    mati.isi_matrix()
    tengah = hidup.add_matrix(mati)
    
    print("Mencetak Matrix Pertama")
    hidup.cetak_matrix()
    print("Mencetak Matrix Kedua")
    mati.cetak_matrix()
    print("Mencetak Matrix Penjumlahan")
    tengah.cetak_matrix()