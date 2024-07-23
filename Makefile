NAME				= library

BUILD				= build

SRC					= sources

DIRS				= manage constructor utils parse

SRCSDIRS			= $(foreach dir, $(DIRS), $(addprefix $(SRC)/, $(dir))) $(SRC)

OBJS				= $(foreach dir, $(SRCSDIRS), \
						$(patsubst $(dir)/%.c, $(BUILD)/%.o, \
						$(shell find $(dir) -maxdepth 1 -name '*.c')))

INCS				= -Iincludes -I./lms/include

HEADERS				= ./includes/library.h ./includes/structures.h

LIB					= -Llms/lib -lreadline

FLAGS				= -Wall -Wextra -Werror -g3 -fsanitize=address

CC					= cc

ifeq ($(shell uname -s), Linux)
	LIB = -lreadline
endif

RESET				= \033[0m
YELLOW				= \033[38;2;255;239;0m
GREEN				= \033[38;5;82m
ORANGE				= \033[38;5;208m
APPLE_GREEN			= \033[38;2;141;182;0m
APPLE_GREEN_BOLD	= \033[1m\033[38;2;141;182;0m
WHITE_BOLD			= \033[1m\033[37m

TOTAL_FILES		= $(words $(OBJS))
COMPILED_FILES	= 0

define show_progress
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@PERCENTAGE=$$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES))); \
	FILLED=$$(echo "$$PERCENTAGE / 5" | bc); \
	EMPTY=$$(echo "20 - $$FILLED" | bc); \
	printf "\r$(CLEAR_LINE)$(APPLE_GREEN_BOLD)Compiling Progress$(WHITE_BOLD) (%2d%%) $(RESET)[" $$PERCENTAGE; \
	printf "$(APPLE_GREEN_BOLD)"; \
	for i in `seq 1 $$FILLED`; do printf "✦"; done; \
	printf "$(RESET)"; \
	for i in `seq 1 $$EMPTY`; do printf " "; done; \
	printf "]";
endef

$(BUILD)/%.o:	$(SRC)/*/%.c $(HEADERS) Makefile
	$(call show_progress)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(BUILD)/%.o:	$(SRC)/%.c $(HEADERS) Makefile
	$(call show_progress)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

all:			$(BUILD) $(NAME)

${NAME}:		${OBJS}
	@$(CC) $(FLAGS) $(OBJS) $(INCS) $(LIB) -o ${NAME}
	@echo "${YELLOW} \nLibrary created 🥑${RESET}"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"
	@echo "$(ORANGE)| Usage               | ./library                      |$(RESET)"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"
	@echo "$(ORANGE)| Help                | make help                      |$(RESET)"
	@echo "$(ORANGE)|                     | ./library -h                   |$(RESET)"
	@echo "$(ORANGE)|                     | ./library --help               |$(RESET)"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"

$(BUILD):
	@mkdir -p $(BUILD)

configure:
	mkdir -p lms
	./readline_config.sh lms

help:
	@echo "$(ORANGE)---------------------------------------------------------$(RESET)"
	@echo "$(ORANGE)| Commands    | REGISTER   - Register new user          |$(RESET)"
	@echo "$(ORANGE)|             | LOGIN      - Log in to personal page    |$(RESET)"
	@echo "$(ORANGE)|             | LOGOUT     - Log out from personal page |$(RESET)"
	@echo "$(ORANGE)|             | ADD        - Add new book               |$(RESET)"
	@echo "$(ORANGE)|             | SEARCH     - Search a book              |$(RESET)"
	@echo "$(ORANGE)|             | BORROW     - Borrow a book              |$(RESET)"
	@echo "$(ORANGE)|             | RETURN     - Return a book              |$(RESET)"
	@echo "$(ORANGE)|             | RESERVE    - Reserve a book             |$(RESET)"
	@echo "$(ORANGE)|             | REMOVE     - Remove a book              |$(RESET)"
	@echo "$(ORANGE)---------------------------------------------------------$(RESET)"

clean:
	@rm -rf $(BUILD) > /dev/null

fclean:
	@rm -rf $(BUILD) > /dev/null
	@rm -f ${NAME}
	@echo "${YELLOW} Everything is cleared ✅${RESET}"

re:				fclean all

.PHONY:			all clean fclean re help
