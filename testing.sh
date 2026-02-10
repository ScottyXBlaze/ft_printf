# Fast test using the test.c and the library
#
# ENJOY

make

cc test.c libftprintf.a -Iincludes/ -o test

echo "Running the test executable"
echo "---------------------------"

./test