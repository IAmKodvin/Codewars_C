/* Note:
    Allocate memory yourself!
*/

#include <stdlib.h>

char *dna_strand(const char *dna)
{  
    char * ans;
    ans = malloc(sizeof(char)*(strlen(dna)+1));
    
    char complement [255] = {'0'};
    complement['A'] = 'T';
    complement['T'] = 'A';
    complement['C'] = 'G';
    complement['G'] = 'C';

    int i = 0;
    for(i=0; i<strlen(dna); i++){
      *(ans+i) = complement[dna[i]];
    }
    *(ans+i) = '\0';
    
    return ans;
}