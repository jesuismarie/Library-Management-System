#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define BUFFER_SIZE	42
# define PS				"Enter a command 🥑$ "

# define RESET			"\033[0m"
# define YELLOW			"\033[38;2;255;239;0m"
# define GREEN			"\033[38;5;82m"
# define ORANGE			"\033[38;5;208m"
# define APPLE_GREEN	"\033[38;2;141;182;0m"
# define RED			"\e[0;31m"

typedef struct book Book;
typedef struct library Library;
typedef struct user User;

struct book
{
	char	**title;
	char	**author;
	char	*isbn;
	bool	borrow;
	bool	reserved;
	Book	*next;
};

struct user
{
	char	*username;
	char	*password;
	Book	*book;
	User	*next;
};

struct library
{
	char	*line;
	Book	*books;
	User	*users;
};

#endif