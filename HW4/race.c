#include <stdio.h>          // Import the standard input-output header
#include <pthread.h>        // Import the pthread header for threading

#define LOOPS 1000000       // Define a constant for the number of loop iterations

int money_on_hand = 0;      // Variable to store the amount of money on hand
int money = 2000000;        // Variable to store the initial amount of money
int num1;                   // Additional variable (not used in this code)
int num2;                   // Additional variable (not used in this code)

// Function to simulate depositing money
void Depositing() {
    for (int i = 0; i < LOOPS; i++) {  // Loop for the defined number of iterations
        money_on_hand = money_on_hand + 1;  // Increment money_on_hand by 1
    }
}

// Function to simulate withdrawing money
void Withdrawing() {
    for (int i = 0; i < LOOPS; i++) {  // Loop for the defined number of iterations
        money_on_hand = money_on_hand - 1;  // Decrement money_on_hand by 1
    }
}

// Function to simulate a person depositing and withdrawing money
void person() {
    Depositing();     // Call the Depositing function
    Withdrawing();    // Call the Withdrawing function

    if (money != 2000000) {  // Check if money has changed from its initial value
        printf("Error !\n"); // Print an error message if money is not equal to 2000000
    }
}

// Function to simulate ATM1 performing deposit operations
void *ATM1() {
    for (int i = 0; i < LOOPS; i++) {  // Loop for the defined number of iterations
        money = money + 1;             // Increment money by 1
    }
    return NULL;  // Return NULL as the thread function needs to return a void pointer
}

// Function to simulate ATM2 performing withdrawal operations
void *ATM2() {
    for (int i = 0; i < LOOPS; i++) {  // Loop for the defined number of iterations
        money = money - 1;             // Decrement money by 1
    }
    return NULL;  // Return NULL as the thread function needs to return a void pointer
}

int main() {
    printf("Initial money = %d\n", money);  // Print the initial amount of money

    pthread_t thread1, thread2;  // Declare two thread variables

    pthread_create(&thread1, NULL, ATM1, NULL);  // Create a thread to run ATM1
    pthread_create(&thread2, NULL, ATM2, NULL);  // Create a thread to run ATM2

    pthread_join(thread1, NULL);  // Wait for thread1 to finish
    pthread_join(thread2, NULL);  // Wait for thread2 to finish

    person();  // Call the person function to simulate depositing and withdrawing

    printf("money = %d\nmoney_on_hand = %d\n", money, money_on_hand);  // Print the final values of money and money_on_hand

    return 0;  // Return 0 to indicate successful completion
}
