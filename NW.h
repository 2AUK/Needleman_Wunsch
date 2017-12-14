#ifndef NW_H_ 
#define NW_H_ 

typedef struct seq_info {
        char *header;
        char *sequence;
} seq_t;

void SeqRead(char *fpath, char **input_arr);
void SeqParse(char **input_arr, seq_t *Prot);
void SeqLengths(char *input_arr, int *id_len, int *seq_len);

#endif
