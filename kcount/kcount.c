/*
 * loadfasta by Stephen Cohen <cohen.1107@osu.edu>
 * Released under CC0 1.0 Universal - see LICENSE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../loadfasta.h"

void	usage(char *argv);

int
main(int argc, char *argv[])
{
	int i;
	unsigned long count;
	unsigned long total;
	unsigned long j;
	clock_t t;
	size_t k_len;
	size_t c_len;
	struct fasta_file *fa;

	/* Make sure there the number of arguments is correct. */
	if (argc != 3) usage(argv[0]);

	/* Load the fasta file. */
	t = clock();
	fa = load_fasta(argv[2]);
	if (fa == NULL) usage(argv[0]);
	printf("File loaded, containing %d contig(s).\n", fa->n_contigs);

	/* Search each contig for given kmer. */
	k_len = strlen(argv[1]);
	total = 0;
	for (i = 0; i < fa->n_contigs; i++) {
		printf("Searching contig %d (%s) ... ", i+1, *(fa->name+i));
		count = 0;
		c_len = strlen(*(fa->seq+i));
		for (j = 0; j < c_len - k_len + 1; j++) {
			if (strncmp(argv[1], *(fa->seq+i)+j, k_len) == 0) {
				count++;
			}
		}
		printf("%lu match(es) for '%s'.\n", count, argv[1]);
		total += count;
	}

	/* The file should be unloaded to prevent memory leaks. */
	del_fasta(fa);
	t = clock() - t;
	printf("Finished! There were %lu total match(es).\n", total);
	printf("The whole process took %f second(s).\n", ((double) t)/CLOCKS_PER_SEC);

	return 0;	
}

void
usage(char *argv)
{
	printf("Usage: %s kmer fasta-file\n", argv);
	exit(1);
}
