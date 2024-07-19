#ifndef LIBRARY_H
# define LIBRARY_H

# include "structures.h"
# include <unistd.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>

void	enter_to_profile(Library *lib);
void	manage(Library *lib);

User	*create_user(char *username, char *password);
void	add_user(User **users, User *new_user);
Book	*create_book(char *title, char *author, char *isbn);
void	add_book(Book **books, Book *new_book);


char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_join_free(char *s1, char *s2);
bool	parse_book(Library *lib);
bool	parse_user(Library *lib);

void	clean(Library *lib);
int		free_malloc(char **str);
void	free_users(Library *lib);
void	free_books(Library *lib);

#endif
