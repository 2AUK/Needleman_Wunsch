#include <stdio.h>
#include <stdlib.h>
/*
 * TODO:
 * -Sequence Parser
 * -NW Equation Core
 */

typedef struct seq_info {
        char *name;
        char *prot_seq;
} seq_t;

void SeqRead(char *fpath, char **input_arr);
void SeqParse(char **input_arr, seq_t *Prot);
int SeqLength(char *input_arr);

int main(int argc, char **argv){
        char *seq;
        seq_t woa;
        SeqRead(argv[1], &seq);
        SeqParse(&seq, &woa);
        printf("%s\n%d\n", woa.name, SeqLength(seq));
        free(seq);
}

void SeqRead(char *fpath, char **input_arr){
        FILE * file;
        size_t size = 0;
        file = fopen(fpath, "r");
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        rewind(file);
        *input_arr = malloc((size + 1) * sizeof(char));
        fread(*input_arr, size, sizeof(char), file);
        (*input_arr)[size] = '\0';
}

void SeqParse(char **input_arr, seq_t *Prot){
        int i = 0;
        int linecount = 0;
        Prot->name = malloc((5) * sizeof(char));
        while((*input_arr)[i] != '\0'){
                if ((*input_arr)[i] == '>'){
                        Prot->name[0] = (*input_arr)[i+1];
                        Prot->name[1] = (*input_arr)[i+2];
                        Prot->name[2] = (*input_arr)[i+3];
                        Prot->name[3] = (*input_arr)[i+4];
                        Prot->name[4] = '\0';
                }
                if ((*input_arr)[i] == '\n'){
                        linecount++;
                        ++i;
                }
                if (linecount > 0){
                        printf("%c", (*input_arr)[i]);
                }
                ++i;
        }
        printf("\n");
}

int SeqLength(char *input_arr){
        int i, linecount, wc;
        i = linecount = wc = 0;
        while(input_arr[i] != '\0'){
                if (input_arr[i] == '\n'){
                        linecount++;
                        i++;
                }
                if (linecount > 0){
                        printf("%c", input_arr[i]);
                        }
                }
        return wc;
}
