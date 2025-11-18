#include <stdio.h>

typedef struct {
    int id;
    char recordDate[20];
    int temperature;
} Weather;

int main() {
    // Example input (you can modify this)
    Weather w[] = {
        {1, "2015-01-01", 10},
        {2, "2015-01-02", 25},
        {3, "2015-01-03", 20},
        {4, "2015-01-04", 30}
    };

    int n = sizeof(w) / sizeof(w[0]);

    printf("IDs with rising temperature compared to previous day:\n");

    for (int i = 1; i < n; i++) {
        // Compare today's temp with yesterday's temp
        if (w[i].temperature > w[i - 1].temperature) {
            printf("%d\n", w[i].id);
        }
    }

    return 0;
}
