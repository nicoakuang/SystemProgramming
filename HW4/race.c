#include <stdio.h>
#include <pthread.h>

#define LOOPS 1000000
int money = 500;

// Function to simulate depositing money in ATM1
void *ATM1() {
  for (int i = 0; i < LOOPS; i++) {
    money = money + 1;  // Increment 'money' by 1
  }
  return NULL;
}

// Function to simulate withdrawing money in ATM2
void *ATM2() {
  for (int i = 0; i < LOOPS; i++) {
    money = money - 1;  // Decrement 'money' by 1
  }
  return NULL;
}

int main() {
  pthread_t thread1, thread2;  // Declare two thread variables

  // Create two threads to run ATM1 and ATM2 functions
  pthread_create(&thread1, NULL, ATM1, NULL);
  pthread_create(&thread2, NULL, ATM2, NULL);

  // Wait for both threads to complete
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // Print the final value of 'money'
  printf("Final money = %d\n", money);

  return 0;  // Return 0 to indicate successful completion
}
