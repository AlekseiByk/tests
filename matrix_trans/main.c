#include <stdio.h>
#include <stdlib.h>

int* transport_m(int* matrix, int n, int m);

int main() {
    FILE* input = fopen("input.csv", "r");
    if (input == NULL)
        return 1;
    int N, M;
    if (fscanf(input, "%d,%d", &N, &M) != 2)
        return 1;
    int val;
    int** matrix = (int**) calloc(N, sizeof(matrix[0]));
    for(int k = 0; k < N; k++)
    {
        matrix[k] = (int*) calloc (M, sizeof(matrix[0][0]));
    }

    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j< M; j++)
        {
            fscanf(input, "%d,", &val);
            matrix[i * M + j] = val;
        }
    }
    fclose(input);

    int* matrix_t = transport_m(matrix, N, M);
    FILE* output = fopen("output.csv", "w");
    if (output == NULL)
        return 1;
    fprintf(output, "%d,%d\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++)
            fprintf(output, "%d,", matrix_t[i * N + j]);
        fprintf(output, "%d\n", matrix_t[i * N + N - 1]);
    }

    fclose(output);
    free(matrix);
    free(matrix_t);
    return 0;
}

int* transport_m(int* matrix, int n, int m)
{
    int* answer = (int*) calloc (n*m, sizeof(answer[0]));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            answer[j * n + i] = matrix[i*m + j];
        }
    return answer;
}
