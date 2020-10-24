#include <stdio.h>
#include <math.h>

#define EPS_F 1e-6f
#define EPS_D 1e-6

void float_experiment() {
    printf("FLOAT EXPERIMENT\n");
    float deviation_value = 0.0001f;
    float received_x, received_y;
    float reference_x = 1.0f, reference_y = 1.0f;
    float previous_solution = 0.0f, current_solution;
    float current_distant;
    int step = 0;
    do {
        ++step;
        received_y = ((2.0001f + deviation_value) - 2.0f) / 0.0001f;
        received_x = 2.0f - received_y;
        current_solution = 1.0001f * received_y + received_x;
        if (current_solution == previous_solution) {
            printf("Found an infinite loop in float on the %d step, further calculation does not make sense\n", step);
            break;
        }
        previous_solution = current_solution;
        printf("Step = %d\n", step);
        printf("Received X = %.30f, Y = %.30f\n", received_x, received_y);
        printf("Current solution = %.30f\n", current_solution);
        printf("Current deviation value = %.30f\n", deviation_value);
        deviation_value /= 2.0f;
        current_distant = sqrtf((reference_x - received_x) * (reference_x - received_x) +
                          (reference_y - received_y) * (reference_y - received_y));
        printf("Current distant = %.30f\n", current_distant);
    } while ((reference_x - received_x) * (reference_x - received_x) +
             (reference_y - received_y) * (reference_y - received_y) > EPS_F * EPS_F);

}

void double_experiment() {
    printf("DOUBLE EXPERIMENT\n");
    double deviation_value = 0.0001;
    double received_x, received_y;
    double reference_x = 1.0, reference_y = 1.0;
    double previous_solution = 0.0, current_solution;
    double current_distant;
    int step = 0;
    do {
        ++step;
        received_y = ((2.0001 + deviation_value) - 2.0) / 0.0001;
        received_x = 2.0 - received_y;
        current_solution = 1.0001 * received_y + received_x;
        if (current_solution == previous_solution) {
            printf("Found an infinite loop in double on the %d step, further calculation does not make sense\n", step);
            break;
        }
        previous_solution = current_solution;
        printf("Step = %d\n", step);
        printf("Received X = %.30f, Y = %.30f\n", received_x, received_y);
        printf("Current solution = %.30f\n", current_solution);
        printf("Current deviation value = %.30f\n", deviation_value);
        deviation_value /= 2.0;
        current_distant = sqrt((reference_x - received_x) * (reference_x - received_x) +
                               (reference_y - received_y) * (reference_y - received_y));
        printf("Current distant = %.30f\n", current_distant);
    } while ((reference_x - received_x) * (reference_x - received_x) +
             (reference_y - received_y) * (reference_y - received_y) > EPS_D * EPS_D);

}

int main() {
    float_experiment();
    double_experiment();
    return 0;
}
