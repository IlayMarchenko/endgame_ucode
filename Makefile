NAME = endgame

HDRS = inc/*.h 

SRCS = src/*.c

SRCS1 = src/enemy/*.c

SRCS2 = src/game/*.c

SRCS3 = src/data/*.c

SRCS4 = src/display/*.c

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror -lncurses -lsqlite3

all: install clean
install: 
	@cp $(SRCS) .
	@cp $(SRCS1) .
	@cp $(SRCS2) .
	@cp $(SRCS3) .
	@cp $(SRCS4) .
	@cp $(HDRS) .
	@clang $(CFLAG) *.c -o $(NAME)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf *.h
	@rm -rf *.c

reinstall: uninstall all
