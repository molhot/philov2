NAME = philo

SRCS = main.c\
		ready_info/ready_info.c\
			ready_info/arg_checker.c\
			ready_info/philos_info/ready_philosinfo.c\
				ready_info/utils/ft_atoi.c\
			ready_info/philo_info/ready_samephiloinfo.c\
		constructor/start_threads.c\
			constructor/lifecycle.c\
				constructor/philo_action/philo_think_eat.c\
				constructor/philo_action/forkunlock.c\
			constructor/checker.c\
					constructor/utils/print_action.c\
					constructor/utils/ft_getnowtime.c\
					constructor/utils/checker_utils.c\
					constructor/handle_commonval/handle_commonval.c\
		destructer/destracter.c\
			destructer/utils/free.c\
			destructer/utils/destroy_forks.c\
			destructer/utils/destroy_eatch.c\
			destructer/utils/destroy_mutex.c\
			destructer/utils/destroy_timech.c\
		basic_func/putserror.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes -pthread

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	rm -f all

re: fclean all

.PHONY:			all clean fclean re bonus