#include <stdio.h>
#include <string.h>

struct Person {
    int personId;
    char lastName[50];
    char firstName[50];
};

struct Address {
    int addressId;
    int personId;
    char city[100];
    char state[100];
};

int main() {
    // Person table
    struct Person persons[] = {
        {1, "Wang", "Allen"},
        {2, "Alice", "Bob"}
    };
    int personCount = 2;

    // Address table
    struct Address addresses[] = {
        {1, 2, "New York City", "New York"},
        {2, 3, "Leetcode", "California"}
    };
    int addressCount = 2;

    printf("firstName | lastName | city | state\n");
    printf("--------------------------------------\n");

    // Perform LEFT JOIN manually
    for (int i = 0; i < personCount; i++) {
        int found = 0;

        // Search address with matching personId
        for (int j = 0; j < addressCount; j++) {
            if (persons[i].personId == addresses[j].personId) {
                printf("%s | %s | %s | %s\n",
                       persons[i].firstName,
                       persons[i].lastName,
                       addresses[j].city,
                       addresses[j].state);
                found = 1;
                break;
            }
        }

        // If no matching address → print NULL
        if (!found) {
            printf("%s | %s | NULL | NULL\n",
                   persons[i].firstName,
                   persons[i].lastName);
        }
    }

    return 0;
}

