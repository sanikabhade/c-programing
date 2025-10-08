#include <stdio.h>

#define MAX 10

typedef struct {
    float weight;
    float cost;
    float profit;
    float profit_per_weight;
} Item;

int main() {
    int n, capacity;
    float sp;
    Item items[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter sell price per unit weight: ");
    scanf("%f", &sp);

    // Input items
    for (int i = 0; i < n; i++) {
        printf("Enter weight and cost of item %d: ", i + 1);
        scanf("%f %f", &items[i].weight, &items[i].cost);
        items[i].profit = (items[i].weight * sp) - items[i].cost;
        items[i].profit_per_weight = items[i].profit / items[i].weight;
    }

    // Selection sort by profit per weight
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (items[j].profit_per_weight > items[max].profit_per_weight)
                max = j;
        }
        if (max != i) {
            Item temp = items[i];
            items[i] = items[max];
            items[max] = temp;
        }
    }

    // Fractional Knapsack
    float total_profit = 0;
    float remaining = capacity;

    printf("\nSelected items:\n");

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            printf("%.2f kg → Profit: %.2f\n", items[i].weight, items[i].profit);
            total_profit += items[i].profit;
            remaining -= items[i].weight;
        } else {
            float fraction = remaining / items[i].weight;
            float profit_fraction = items[i].profit * fraction;
            printf("%.2f kg → Profit: %.2f (Fraction - %.0f/%.0f)\n",
                   remaining, profit_fraction, remaining, items[i].weight);
            total_profit += profit_fraction;
            remaining = 0;
        }
    }

    printf("\nTotal Profit = %.2f\n", total_profit);

    return 0;
}
