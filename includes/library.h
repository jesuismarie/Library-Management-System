#ifndef LIBRARY_H
# define LIBRARY_H

# include "structures.h"
# include <unistd.h>
# include <fcntl.h>
#include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>


/******************************************************************************/
/***************************** Profile management *****************************/
/******************************************************************************/

void	enter_to_profile(Library *lib);
void	manage(Library *lib);
void	add(Library *lib);
void	search(Library *lib);
void	lib_register(Library *lib, bool *flag);
void	lib_login(Library *lib, bool *flag);

/******************************************************************************/
/***************************** Library management *****************************/
/******************************************************************************/

Library	*creat_lib(void);
User	*create_user(char *username, char *password, bool flag);
void	add_user(User **users, User *new_user);
Book	*create_book(char *title, char *author, char *isbn, bool flag);
void	add_book(Book **books, Book *new_book);


/******************************************************************************/
/*********************************** Utils ************************************/
/******************************************************************************/

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_join_free(char *s1, char *s2);
char	*join_with_symbol(char *s1, char *s2, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
void	disable_echo(void);
void	enable_echo(void);
bool	check_user(Library *lib, char *username);
bool	check_login(Library *lib, char *str, bool *flag, User **user);
bool	check_password(User *user, char *password);

/******************************************************************************/
/*********************************** Parse ************************************/
/******************************************************************************/

bool	parse_book(Library *lib);
bool	parse_user(Library *lib);

/******************************************************************************/
/********************************** Cleanup ***********************************/
/******************************************************************************/

void	clean(Library *lib);
int		free_malloc(char **str);
void	free_users(Library *lib);
void	free_books(Library *lib);

#endif
