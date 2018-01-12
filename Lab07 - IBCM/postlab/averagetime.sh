#!/bin/bash
# Charles Buyas, cjb8qf, 3-14-17, averagetime.sh

read -p "Enter in a number, 1-9, or quit: " command1

variable=0
average=0

if [[ "$command1" = "quit" ]] ; then
    exit 0
fi

for i in {1..5} ; do
    runtime=`./a.out $command1 | tail -1`
    variable=$((variable+runtime))
    echo "Running time " $i "... "
    echo "time taken: " $runtime " ms"
done

average=$((variable/5))

echo $average
echo "5 iterations took " $variable " ms"
echo "Average time was " $average " ms"
