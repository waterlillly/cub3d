**to do**

***i ran valgrind& this was the output:***
(i added a free in read_file.c)
+i've been told to use ft_calloc instead of malloc because it's safer (&it's saving lines since we don't need to null-terminate the end) but i didn't change anything in your code because i wanted to ask if you use malloc for a specific reason? (just curious, i'm okay with anything haha)

make; valgrind --leak-check=full --show-leak-kinds=all ./cub3d assets/maps/valid/valid.cub
cc -Wall -Wextra -Werror -g -c src/msimic_split.c -o src/msimic_split.o
(make -C ./lib)
make[1]: Entering directory '/home/lbaumeis/CCore/projects/cub3d/lib'
make[1]: Nothing to be done for 'all'.
make[1]: Leaving directory '/home/lbaumeis/CCore/projects/cub3d/lib'
cc src/main.o src/args_handler.o src/map_validator.o src/read_file.o src/strappend.o src/init.o src/msimic_split.o src/error.o src/get_map.o ./lib/libft.a -o cub3d
==1561898== Memcheck, a memory error detector
==1561898== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1561898== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1561898== Command: ./cub3d assets/maps/valid/valid.cub
==1561898== 

READING MAP FILE

CLOSING FILE

==1561898== 
==1561898== HEAP SUMMARY:
==1561898==     in use at exit: 11,508 bytes in 647 blocks
==1561898==   total heap usage: 739 allocs, 92 frees, 19,450 bytes allocated
==1561898== 
==1561898== 1 bytes in 1 blocks are definitely lost in loss record 1 of 5
==1561898==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1561898==    by 0x4026D5: ft_calloc (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x401FC9: ft_strdup (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x4024C2: get_next_line (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x401391: read_file (read_file.c:17)
==1561898==    by 0x401B10: get_map (get_map.c:7)
==1561898==    by 0x4011FD: main (main.c:13)
==1561898== 
==1561898== 21 bytes in 21 blocks are definitely lost in loss record 2 of 5
==1561898==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1561898==    by 0x402164: ft_rest (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x40259F: get_next_line (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x401391: read_file (read_file.c:17)
==1561898==    by 0x401B10: get_map (get_map.c:7)
==1561898==    by 0x4011FD: main (main.c:13)
==1561898== 
==1561898== 625 bytes in 20 blocks are indirectly lost in loss record 3 of 5
==1561898==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1561898==    by 0x40190F: ft_word (msimic_split.c:40)
==1561898==    by 0x401634: msimic_split (msimic_split.c:88)
==1561898==    by 0x401B48: get_map (get_map.c:11)
==1561898==    by 0x4011FD: main (main.c:13)
==1561898== 
==1561898== 793 (168 direct, 625 indirect) bytes in 1 blocks are definitely lost in loss record 4 of 5
==1561898==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1561898==    by 0x40156D: msimic_split (msimic_split.c:79)
==1561898==    by 0x401B48: get_map (get_map.c:11)
==1561898==    by 0x4011FD: main (main.c:13)
==1561898== 
==1561898== 10,693 bytes in 604 blocks are definitely lost in loss record 5 of 5
==1561898==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1561898==    by 0x4027BA: ft_strjoin (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x40242B: ft_next (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x40250A: get_next_line (in /home/lbaumeis/CCore/projects/cub3d/cub3d)
==1561898==    by 0x401391: read_file (read_file.c:17)
==1561898==    by 0x401B10: get_map (get_map.c:7)
==1561898==    by 0x4011FD: main (main.c:13)
==1561898== 
==1561898== LEAK SUMMARY:
==1561898==    definitely lost: 10,883 bytes in 627 blocks
==1561898==    indirectly lost: 625 bytes in 20 blocks
==1561898==      possibly lost: 0 bytes in 0 blocks
==1561898==    still reachable: 0 bytes in 0 blocks
==1561898==         suppressed: 0 bytes in 0 blocks
==1561898== 
==1561898== For lists of detected and suppressed errors, rerun with: -s
==1561898== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)