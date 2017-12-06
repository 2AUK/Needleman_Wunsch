#include <stdio.h>
#include <stdlib.h>
#define MAX 200
/*
 * TODO:
 * -Sequence Parser
 * -NW Equation Core
 */

typedef struct seq_info {
        char *prot_id;
        char *prot_seq;
} seq_t;

void SeqRead(char *fpath, char *input_arr);
void SeqParse(char *input_arr, seq_t *Prot);
int SeqLength(char *input_arr);

int main(int argc, char **argv){
        char *seq;
        seq_t *woa;
        SeqRead(argv[1], seq);
        free(seq);
}

void SeqRead(char *fpath, char *input_arr){
        FILE * file;
        size_t size = 0;
        file = fopen(fpath, "r");
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        rewind(file);
        input_arr = malloc((size + 1) * sizeof(*input_arr));
        fread(input_arr, size, 1, file);
        input_arr[size] = '\0';
        printf("%s", input_arr);
}

void SeqParse(char *input_arr, seq_t *Prot){
        int i, nc;
        i = 0;
        while (input_arr[i] != '\0'){
               printf("%c", input_arr[i]);
                ++i;
        }
}
