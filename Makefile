.PHONY: $(LIB) all clean fclean re mclean mfclean mre

NAME :=			lem-in

SRC_PATH :=		src/
INC_PATH :=		includes/
LIB_PATH :=		ft_printf/
OBJ_PATH :=		.obj/

CC :=			clang
CFLAGS :=		-Wall -Werror -Wextra -g
IFLAGS :=		-I $(INC_PATH) -I $(LIB_PATH) -I $(LIB_PATH)includes/  -I $(LIB_PATH)libft/
LFLAGS :=		-lftprintf -L $(LIB_PATH)

LIB :=			$(LIB_PATH)libftprintf.a
HFILES :=		lemin
FILES :=		lem_in functional bfs move_ants

HDRS :=			$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=			$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=			$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
$(LIB):
	@ $(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
fclean: mfclean
	make fclean -C $(LIB_PATH)
re: fclean all

mclean:
	rm -f $(OBJS) $(DEPS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all
