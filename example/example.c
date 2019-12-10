/*
 * loadfasta by Stephen Cohen <cohen.1107@osu.edu>
 * Released under CC0 1.0 Universal - see LICENSE
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../loadfasta.h"

int
main()
{
	int i;
	clock_t t;
	struct fasta_file *fa;

	/* Load the long example sequences and display time elapsed. */
	t = clock();
	fa = load_fasta("sequence.fa");
	t = clock() - t;
	printf("example.fa loaded in %f sec.\n", ((double) t)/CLOCKS_PER_SEC);

	/* Display number of contigs loaded. */
	printf("File contains %d contig(s).\n", fa->n_contigs);

	/* Display length of each contig. */
	for (i = 0; i < fa->n_contigs; i++) {
		printf("Contig %d is named '%s' ", i+1, *(fa->name+i));
		printf("and contains %lu characters.\n", strlen(*(fa->seq+i)));
	}

	/* Display one of the contigs in total. */
	printf("The sequence for contig 1 is:\n%s\n", *(fa->seq+0));

	/* Display a single character. */
	printf("The 4th character from contig 1 is '%c'.\n", *(*(fa->seq+0)+3));

	/* The file should be unloaded to prevent memory leaks. */
	del_fasta(fa);

	return 0;	
}
