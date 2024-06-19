#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Tambahkan ini untuk strchr


// Fungsi untuk mengevaluasi ekspresi penjumlahan
int evaluate(char *expression) {
    int operand1, operand2;
    char operator;

    // Membaca operan dan operator dari ekspresi
    if (sscanf(expression, "%d %c %d", &operand1, &operator, &operand2) != 3) {
        fprintf(stderr, "Error: Format ekspresi tidak valid: %s\n", expression);
        return 0; // Kode error
    }

    // Menjalankan operasi penjumlahan
    if (operator == '+') {
        return operand1 + operand2;
    }
    // Menjalankan operasi pengurangan
    else if (operator == '-') {
        return operand1 - operand2;
    }
    // Menampilkan pesan error jika operator tidak didukung
    else {
        fprintf(stderr, "Error: Operator tidak didukung: %c\n", operator);
        return 0; // Kode error
    }
}

// Fungsi untuk membaca file program Nico dan mengevaluasi setiap baris
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
        fprintf(stderr, "Usage: %s <filename.nico>\n", argv[0]);
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
