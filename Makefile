cc = gcc
exec = program
dep = -I./include/
src = $(shell find src/ -name "*.c")
obj = $(src:.c=.o)
dek = -g # -W -Wall -Werror

all : $(exec)
	@clear
	@echo "Make" $<
	@echo "To launch please write ./"$<
	@echo "========================"
	@./$<

$(exec) : $(obj)
	@$(cc) $(obj) $(dek) $(dep) -o $(exec)

.c.o:
	@$(cc) $(dep) $(dek) -c $< -o $@

clean:
	@rm -f ${obj}
	@rm -f *.o

fclean: clean
	@rm -rf $(exec)

re : fclean all

.SUFFIXE: .c .o
