#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
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

int main(){
        char seq[MAX];
        seq_t *woa;
        SeqRead("/Users/AbdullahAhmad/Desktop/1mc2.fasta.txt", seq);
        SeqParse(seq, woa);
        printf("%d\n", SeqLength(seq));
}

void SeqRead(char *fpath, char *input_arr){
        FILE * file;
        int c, i;
        i = 0;
        file = fopen(fpath, "r");
        if (file) {
                while ((c = getc(file)) != EOF){
                        input_arr[i] = c;
                        ++i;
                }
        }else{
                printf("Error: File not found");
                return;
        }
}

void SeqParse(char *input_arr, seq_t *Prot){
        char name[MAX];
        char seq[MAX];
        int linecount;
        printf("%s\n", input_arr);
        for (int i = 0; i < MAX; ++i){
                if (input_arr[i] == '>'){
                        name[0] = input_arr[i+1]; name[1] = input_arr[i+2]; name[2] = input_arr[i+3]; name[3] = input_arr[i+4];
                }
                if (input_arr[i] == '\n'){
                        ++linecount;
                }
                if (linecount == 1){
                }
        }
        printf("%s\n", name);
}

int SeqLength(char *input_arr){
        int linecount;
        int seqcount;
        for (int i = 0; i < MAX; ++i){
                if (input_arr[i] == '\n'){
                        ++linecount;
                }
                if (linecount > 1){
                     if (input_arr[i] != '\n' && input_arr[i] != 0)
                             seqcount++;
                }
        }
        return seqcount;
}
