#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int i;
    int onesCount = 0;
    int parityChoice;
    int parityBit;
    int checksum;

    printf("Enter binary data: ");
    scanf("%s", data);

    printf("\nChoose Parity Type:\n");
    printf("1. Even Parity\n");
    printf("2. Odd Parity\n");
    printf("Enter choice: ");
    scanf("%d", &parityChoice);

    /* -------- STEP 1: COUNTING 1s -------- */
    printf("\n--- STEP 1: COUNTING NUMBER OF 1s ---\n");
    printf("Data Bits : ");
    for (i = 0; i < strlen(data); i++) {
        printf("%c ", data[i]);
        if (data[i] == '1')
            onesCount++;
    }
    printf("\nTotal number of 1s = %d\n", onesCount);

    /* -------- STEP 2: PARITY BIT -------- */
    printf("\n--- STEP 2: PARITY BIT CALCULATION ---\n");

    if (parityChoice == 1) {
        printf("Selected Parity : EVEN PARITY\n");
        printf("Rule : Total number of 1s (including parity bit) should be EVEN\n");

        if (onesCount % 2 == 0)
            parityBit = 0;
        else
            parityBit = 1;

    } else if (parityChoice == 2) {
        printf("Selected Parity : ODD PARITY\n");
        printf("Rule : Total number of 1s (including parity bit) should be ODD\n");

        if (onesCount % 2 == 0)
            parityBit = 1;
        else
            parityBit = 0;

    } else {
        printf("Invalid parity choice\n");
        return 0;
    }

    printf("Data with Parity Placeholder : %s X\n", data);
    printf("Calculated Parity Bit (X)    : %d\n", parityBit);
    printf("Final Codeword              : %s %d\n", data, parityBit);

    /* -------- STEP 3: CHECKSUM -------- */
    printf("\n--- STEP 3: CHECKSUM CALCULATION ---\n");
    checksum = onesCount % 2;
    printf("Checksum = Total number of 1s mod 2\n");
    printf("Checksum = %d mod 2 = %d\n", onesCount, checksum);

    /* -------- TRANSMITTED FRAME -------- */
    printf("\n--- TRANSMITTED FRAME ---\n");
    printf("%s %d | Checksum = %d\n", data, parityBit, checksum);

    /* -------- RECEIVER SIDE -------- */
    printf("\n--- RECEIVER SIDE VERIFICATION ---\n");

    int receiverOnes = 0;
    for (i = 0; i < strlen(data); i++) {
        if (data[i] == '1')
            receiverOnes++;
    }

    printf("Receiver counted number of 1s = %d\n", receiverOnes);
    printf("Receiver Calculation : %d mod 2 = %d\n",
           receiverOnes, receiverOnes % 2);

    int totalWithParity = receiverOnes + parityBit;
    printf("Total 1s including parity   = %d\n", totalWithParity);

    printf("\n===============================\n");
    if ((parityChoice == 1 && totalWithParity % 2 == 0) ||
    (parityChoice == 2 && totalWithParity % 2 != 0)) {
    printf("FINAL RESULT : NO ERROR DETECTED\n");
} else {
    printf("FINAL RESULT : ERROR DETECTED\n");
}

    printf("===============================\n");
    return 0;
}
