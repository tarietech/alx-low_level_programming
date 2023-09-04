#ifndef MAIN_H
#define MAIN_H

/**
 * struct elf_hdr - Short description
 * @ei_magic: First member
 * @ei_class: Second member
 * @ei_data: Third member
 * @ei_version: Fourth member
 * @os_abi: Fifth memeber
 * @abi_version: Sixth member
 * @type: elffile type
 * @entry_pt: Entry point
 *
 * Description: Longer description
 */
typedef struct elf_hdr
{
	int ei_magic[16];
	int ei_class;
	int ei_data;
	int ei_version;
	int os_abi;
	int abi_version;
	int type;
	int entry_pt[4];
} elf_hdr;
/**
 * struct os_abi - Short description
 * @hex: First member
 * @osabi_name: Second member
 *
 * Description: Longer description
 */
typedef struct os_abi
{
	int hex;
	char *osabi_name;
} os_abi;
/**
 * struct elftype - Short description
 * @hex: First member
 * @type: Second member
 * @object: Third memeber
 *
 * Description: Longer description
 */
typedef struct elftype
{
	int hex;
	char *type;
	char *object;
} elftype;

/* Header file */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/* Prototypes */
int _putchar(char c);
ssize_t read_textfile(const char *, size_t);
int create_file(const char *, char *);
int append_text_to_file(const char *, char *);

#endif /* HOLBERTON_H */
