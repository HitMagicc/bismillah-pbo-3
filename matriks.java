
import java.util.Scanner;

/**
 * MatrixSaya
 */
class MatrixSaya {
    private int baris;
    private int kolom;
    private int[][] nilai;

    public MatrixSaya(int baris, int kolom) {
        this.baris = baris;
        this.kolom = kolom;
        nilai = new int[baris][kolom];
    }

    public MatrixSaya() {
        baris = 3;
        kolom = 3;
        nilai = new int[baris][kolom];
    }

    public void isiMatriks() {
        Scanner scan = new Scanner(System.in);
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                System.out.println("Masukkan Nilai Matriks ke baris "+(i+1)+" dan masukkan kolom "+(j+1));
                nilai[i][j]=scan.nextInt();
            }
        }
    }

    public void cetak() {
        System.out.println("Matriks Anda:");
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                System.out.print(nilai[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public void addMatrix(MatrixSaya a,MatrixSaya b) {
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                nilai[i][j]=a.nilai[i][j]+b.nilai[i][j];
            }
        }
    }
}

public class matriks {
    public static void main(String[] args) {
        MatrixSaya hidup = new MatrixSaya();
        MatrixSaya mati = new MatrixSaya();
        MatrixSaya tengahtengah = new MatrixSaya();

        hidup.isiMatriks();
        mati.isiMatriks();

        tengahtengah.addMatrix(hidup, mati);

        hidup.cetak();
        mati.cetak();
        tengahtengah.cetak();
    }
}
