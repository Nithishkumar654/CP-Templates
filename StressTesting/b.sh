# For samples

# Ensure input file exists
if [[ ! -f input ]]; then
    echo "Error: 'input' file not found!"
    exit 1
fi

# Read total test cases from input
read -r total_testcases < input
tail -n +2 input > temp_input  # Remove the first line (total test cases)

i=1
while read -r n; do

    # Read the array elements
    read -r -a array  # Reads the next line as an array

    # Save test case to `int` file
    {
        echo "$n"
        echo "${array[@]}"
    } > int

    echo "Running Test #$i"

    # Run both programs
    # ./a < int > out1
    # ./brute < int > out2

    # Take expected inputs
    read -r n <&3
    # read -r -a array <&3
    
    # Compare outputs
    
    if ! diff -w <(./a < int) \
        <(\
        echo $n
        # echo "${array[@]}"
        ) > /dev/null; then
        echo ""
        echo "🚨 Test failed on iteration $i!"
        echo "🔹Input:"
        cat int
        echo ""
        echo "🔹Expected Output: $n"
        echo "🔹Your Output: $(./a < int)"
        exit 1
    fi

    ((i++))
done 3< expected_output < temp_input

echo "✨ All test cases passed successfully!"
rm temp_input  # Clean up temp file
