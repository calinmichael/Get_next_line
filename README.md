*This project has been created as part of the 42 curriculum by ccascava*

# Description

This project allows us to add a highly useful function to our collection while teaching us the importance of static variables, file descriptors, and buffer management. Through the implementation of get_next_line, we learn how to read a file line by line, manage memory efficiently, and work with linked lists and dynamic memory allocation. It also strengthens our understanding of reading operations, handling different input sources, and preserving data between function calls.

# Instructions

Make sure to include the header file at the top of your C file:

#include "get_next_line.h"


You can then compile your program by typing:

cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl


Here, main.c is the C file you created.

If you have not used a main.c, you can compile like this:

cc -Wall -Wextra -Werror -c get_next_line.c get_next_line_utils.c

You also need to make sure to specify the buffer size when you compile. You can do this by adding -D BUFFER_SIZE=n, where n is the length of your buffer.

# Resources

I used Youtube as a resource to better understand certain functions, their usage, and their functionality. I also used AI for similar purposes, to improve my understanding, as well as formatting this document.

# Functions

	- void del(t_list **head, t_list **tail, int line_len, char *str) \
    - char *stop_it(t_list **head, t_list **tail, char *buffer, int line_len) \
    - char *create_line(t_list **head, t_list **tail, char *buffer) \
    - char *get_remaining(t_list **head, t_list **tail, char *buffer) \
    - char *check_res(int result, t_list **head, t_list **tail, char *buffer) \
    - t_list *assign_head(t_list **head, t_list **tail, char *buffer) \
    - void *append(t_list **head, int j, char *buffer) \
    - int   a_and_a(t_list **head, t_list **tail, char *buffer, int result) \
    - char *main_loop(int fd, char *buffer, t_list **head, t_list **tail) \
    - char *get_next_line(int fd)

# Justification

I used a linked list for this project because I thought it would be more simple to visualize in my mind. Each node represents a character and contains a pointer to the next node, allowing me to store and process the input line character by character. This approach also helped me better understand dynamic memory allocation, pointers, and how to manage data when the length of a line is not known in advance.

# Author

Calin Cascaval — 42 School Vienna


