# For stress testing

for((i = 1; ; i++)) do

    echo "Running Test #$i"
    ./gen $i > int

    # ./a < int > out1
    # ./brute < int > out2

    if ! diff -w <(./a < int) <(./brute < int) > /dev/null; then
        echo ""
        echo "🚨 Test failed on iteration $i!"
        echo "🔹Input:"
        cat int
        echo ""
        echo "🔹Expected Output: $(./brute < int)"
        echo "🔹Your Output: $(./a < int)"
        exit 1
    fi


    # diff -w <(./a < int) <(./brute < int) || break
done