# loadfasta

loadfasta.c contains functions for loading standard fasta files into memory in
a C program. It should be fairly fast - testing on my laptop by loading a file
with ~5 Mbases took 0.212838 sec.

## To use

To use, `#include "loadfasta.h"` in your source file, declare a variable of type
`struct fasta_file *` and call `load_fasta()`, with the name of the fasta file
as the argument. When finished, call `del_fasta()` with the used variable as the
argument.

The members for `struct fasta_file` are:

1. `n_contigs` - integer variable with number of contigs loaded
2. `name` - char double pointer that points to contig names
3. `seq` - char double pointer that points to sequences

## Fasta file format

Fasta files should be in the modern standard format: single line headers with
`>` preceding the name, followed by the sequence. Files can contain multiple
sequences, but each must be preceded by a single line header. Sequences can be
on a single line or broken up (e.g. with the NCBI 60 character-per-line format).

## Example code

For examples of how to use the code, see the `example.c` file in the `example`
directory. You can try to run this example with the following:

```
git clone https://github.com/stephen-cohen/loadfasta.git
cd loadfasta/example
make
./example
```

## Rational and caveat

I decided to write this because I couldn't find a simple C function or library
to just load fasta files.

As a caveat: in this version, there is no error handling. For example, it won't
work if you try to open a non-existant file, and I have not tested with
improperly formatted files. I may implement error handling at a later date.

## License

loadfasta is licensed under CC0 1.0 Universal. See the `LICENSE` file for all
the details. I'm releasing it under the public domain to make using it easy.