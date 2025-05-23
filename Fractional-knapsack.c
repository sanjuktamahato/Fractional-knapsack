#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value, weight;
};

int cmp(const void* a, const void* b) {
    double r1 = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double r2 = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    return r2 - r1 > 0 ? 1 : -1;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), cmp);

    double totalValue = 0.0; 
    int i;

    for ( i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int W = 50; 
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value in Knapsack = %.2f\n", fractionalKnapsack(W, arr, n));
    return 0;
}