#include "library.h"

void	add(Library *lib)
{
	char	*title;
	char	*author;
	char	*isbn;
	Book	*new_book;

	title = readline("Enter title: ");
	author = readline("Enter author: ");
	isbn = readline("Enter isbn: ");
	new_book = create_book(title, author, isbn, 1);
	add_book(&lib->books, new_book);
	free(title);
	free(author);
	free(isbn);
}
