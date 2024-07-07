#include <stdio.h>
#include <stdlib.h>

int min_steps(int x, int y) {
    int distance = y - x;
    if (distance == 0) {
        return 0;
    }
    
    int steps = 0;
    int current_position = x;
    int step_size = 1;
    
    while (current_position < y) {
        if (current_position + step_size <= y) {
            current_position += step_size;
        } else {
            step_size = 1;
            current_position += step_size;
        }
        steps++;
        if (current_position == y) {
            break;
        }
        if (current_position + (step_size + 1) <= y) {
            step_size++;
        } else if (current_position + step_size <= y) {
            // do nothing, continue with the same step_size
        } else {
            step_size--;
        }
    }
    
    return steps;
}

int main() {
    int x, y;
    printf("Введіть x: ");
    scanf("%d", &x);
    printf("Введіть y: ");
    scanf("%d", &y);
    
    int result = min_steps(x, y);
    printf("Мінімальна кількість кроків: %d\n", result);
    
    return 0;
}

