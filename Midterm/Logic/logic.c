#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strchr

// Fungsi untuk mengevaluasi ekspresi logika
int evaluate(char *expression) {
    int operand1, operand2;
    char operator[5]; // Memperhitungkan 'NOT' dan spasi nol di bagian akhir string

    // Membaca operand dan operator dari ekspresi
    if (sscanf(expression, "%s %d %d", operator, &operand1, &operand2) != 3) {
        // Coba lagi dengan format NOT <operand>
        if (sscanf(expression, "%s %d", operator, &operand1) != 2 || strcmp(operator, "NOT") != 0) {
            fprintf(stderr, "Error: Format ekspresi tidak valid: %s\n", expression);
            return 0; // Kode error
        }
        // Jika operator NOT dan operand hanya satu
        return !operand1;
    }

    // Menjalankan operasi logika
    if (strcmp(operator, "AND") == 0) {
        return operand1 && operand2;
    } else if (strcmp(operator, "OR") == 0) {
        return operand1 || operand2;
    } else {
        fprintf(stderr, "Error: Operator tidak didukung: %s\n", operator);
        return 0; // Kode error
    }
}


// Fungsi untuk membaca file program logic.nico dan mengevaluasi setiap baris
void interpret(FILE *file) {
    char line[100]; // Ukuran maksimum satu baris program
    int result;

    while (fgets(line, sizeof(line), file)) {
        // Menghilangkan karakter newline jika ada
        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        // Melakukan evaluasi dan mencetak hasilnya
        result = evaluate(line);
        printf("Result: %d\n", result);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logic.nico>\n", argv[0]);
        return 1; // Kode error
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Tidak dapat membuka file '%s'\n", argv[1]);
        return 1; // Kode error
    }

    interpret(file);
    fclose(file);

    return 0; // Program selesai dengan sukses
}
