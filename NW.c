#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NW.h"

/*
 * TODO:
 * -Sequence Parser
 * -NW Equation Core
 */

int main(int argc, char **argv){
        char *seq;
        seq_t woa;
        SeqRead(argv[1], &seq);
        SeqParse(&seq, &woa);
        printf("%s\n%s\n", woa.header, woa.sequence);
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
        int idlen, seqlen;
        SeqLengths(input_arr, &idlen, &seqlen);
        int backup = seqlen;
        printf("%d\t%d\n", idlen, seqlen);
        printf("%d\n", backup);
        Prot->header = malloc((idlen + 1) * sizeof(char));
        strncpy(Prot->header, *input_arr, idlen);
        Prot->header[idlen] = '\0';
        free(Prot->header);
//        Prot->sequence = malloc((seqlen + 1) * sizeof(char));
//        strncpy(Prot->sequence, (*input_arr+(idlen+1)), seqlen);
//        Prot->sequence[seqlen] = '\0';
}

void SeqLengths(char **input_arr, int *id_len, int *seq_len){
        char *token;
        int sum;
        token = strtok(*input_arr, "\n");
        while( token != NULL) {
                if(token[0] == '>'){
                        *id_len  = (int)strlen(token);
                }else{
                        sum += strlen(token);
                }
                token = strtok(NULL, "\n");
        }
        *seq_len = sum;
}
