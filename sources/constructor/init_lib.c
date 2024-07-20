#include "library.h"

Library	*creat_lib(void)
{
	Library	*lib;
	lib = calloc(1, sizeof(Library));
	if (!lib)
		exit(1);
	return (lib);
}
