#bin/bash/
make
echo ===============================
echo "ls"
echo ===============================
./my_ls | cat -e
echo "******************************"
ls | cat -e
echo "------------------------------"
./my_ls | cat -e | wc
ls | cat -e | wc
echo ===============================
echo "ls include"
echo ===============================
./my_ls include | cat -e
echo "******************************"
ls include | cat -e
echo "------------------------------"
./my_ls include| cat -e | wc
ls include | cat -e | wc
echo ===============================
echo "ls include lib lib/my"
echo ===============================
./my_ls include lib lib/my | cat -e
echo "******************************"
ls include lib lib/my | cat -e
echo "------------------------------"
./my_ls include lib lib/my | cat -e | wc
ls include lib lib/my | cat -e | wc
echo ===============================
echo "ls Makefile"
echo ===============================
./my_ls Makefile | cat -e
echo "******************************"
ls Makefile | cat -e
echo "------------------------------"
./my_ls Makefile | cat -e | wc
ls Makefile | cat -e | wc
echo ===============================
echo "ls Makefile main.c lib/src/my_ls.c"
echo ===============================
./my_ls Makefile main.c lib/src/my_ls.c | cat -e
echo "******************************"
ls Makefile main.c lib/src/my_ls.c | cat -e
echo "------------------------------"
./my_ls Makefile main.c lib/src/my_ls.c | cat -e | wc
ls Makefile main.c lib/src/my_ls.c | cat -e | wc
echo ===============================
echo "ls Makefile lib/my"
echo ===============================
./my_ls Makefile lib/my | cat -e
echo "******************************"
ls Makefile lib/my | cat -e
echo "------------------------------"
./my_ls Makefile lib/my | cat -e | wc
ls Makefile lib/my | cat -e | wc
echo ===============================
echo "ls lib main.c Makefile tests lib/src lib/src/my_ls.c"
echo ===============================
./my_ls lib main.c Makefile tests lib/src lib/src/my_ls.c | cat -e
echo "******************************"
ls lib main.c Makefile tests lib/src lib/src/my_ls.c | cat -e
echo "------------------------------"
./my_ls lib main.c Makefile tests lib/src lib/src/my_ls.c | cat -e | wc
ls lib main.c Makefile tests lib/src lib/src/my_ls.c | cat -e | wc
echo ===============================
echo "ls -a"
echo ===============================
./my_ls -a | cat -e
echo "******************************"
ls -a | cat -e
echo "------------------------------"
./my_ls -a | cat -e | wc
ls -a | cat -e | wc
echo ===============================
echo "ls /root"
echo ===============================
./my_ls /root
echo "******************************"
ls /root
echo ===============================
echo "ls e"
echo ===============================
./my_ls e
echo "******************************"
ls e
echo ===============================
echo "ls main.c l"
echo ===============================
./my_ls main.c l
echo "******************************"
ls main.c l | cat
echo ===============================
echo "ls main.c -l"
echo ===============================
./my_ls main.c -l | cat -e
echo "******************************"
ls main.c -l | cat -e
echo "------------------------------"
./my_ls main.c -l | cat -e | wc
ls main.c -l | cat -e | wc
echo ===============================
