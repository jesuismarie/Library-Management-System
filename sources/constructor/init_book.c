#include "library.h"

Book	*create_book(char *title, char *author, char *isbn)
{
	Book	*new_book;

	new_book = (Book *)calloc(1, sizeof(Book));
	if (!new_book)
		return (NULL);
	new_book->title = ft_split(title, ' ');
	if (!new_book->title || !*new_book->title)
		return (NULL);
	new_book->author = ft_split(author, ' ');
	if (!new_book->author || !*new_book->author)
		return (NULL);
	new_book->isbn = ft_strdup(isbn);
	new_book->borrow = false;
	new_book->reserved = false;
	new_book->next = NULL;
	return (new_book);
}

void	add_book(Book **books, Book *new_book)
{
	Book	*tmp;

	if (!(*books))
	{
		*books = new_book;
		return ;
	}
	tmp = *books;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new_book;
}
