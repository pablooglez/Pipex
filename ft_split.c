#include <stdlib.h>
#include <stdio.h>

int is_delimiter(char c, char separater) {
    return (c == 32 || c == 9 || c == 10 || c == 58 || c == separater); 
}

int count_words(char *str, char separater) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (!is_delimiter(*str, separater)) {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }
        str++;
    }
    return count;
}

char **ft_split(char *str, char separater) {
    int word_count = count_words(str, separater);
    char **split = malloc((word_count + 1) * sizeof(char *));
    char *word;
    int i = 0, j = 0, start = 0, k;

    if (!split) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while (str[i]) {
        if (!is_delimiter(str[i], separater)) {
            start = i;
            k = 0;
            while (str[i] && !is_delimiter(str[i], separater)) {
                i++;
            }
            word = (char *)malloc(i - start + 1);
            if (!word) {
                perror("malloc");
                // Liberar memoria previamente asignada antes de salir
                for (int l = 0; l < j; l++) {
                    free(split[l]);
                }
                free(split);
                exit(EXIT_FAILURE);
            }
            while (start < i) {
                word[k++] = str[start++];
            }
            word[k] = '\0';
            split[j++] = word;
        } else {
            i++;
        }
    }
    split[j] = NULL;
    return split;
}

int main() {
    char *str = "Este es un : ejemplo : de prueba\ncon varios\tdelimitadores.";
    char separater = ':';
    char **words = ft_split(str, separater);
    int i = 0;

    while (words[i] != NULL) {
        printf("Palabra %d: %s\n", i + 1, words[i]);
        free(words[i]);
        i++;
    }
    free(words);

    return 0;
}