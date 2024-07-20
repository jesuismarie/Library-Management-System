#include "library.h"

void	disable_echo(void)
{
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void	enable_echo(void)
{
	struct termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	oldt.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
