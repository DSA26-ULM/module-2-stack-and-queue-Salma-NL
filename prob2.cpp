#include "queue.h"
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int A[MAX];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    Queue q;
    init(&q);

    int current_sum = 0;

    for (int i = 0; i < k; i++) {
        enqueue(&q, A[i]);
        current_sum += A[i];
    }

    std::cout << current_sum;

    for (int i = k; i < n; i++) {
        current_sum -= front(&q);
        dequeue(&q);

        enqueue(&q, A[i]);
        current_sum += A[i];

        std::cout << " " << current_sum;
    }

    std::cout << std::endl;
    return 0;
}
