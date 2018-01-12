# Charles Buyas, cjb8qf, 3-14-17, averagetime.sh

read -e -p "Enter dictionary file: " command1
read -e -p "Enter grid file: " command2

RUNNING_TIME1=`./a.out $command1 $command2 | tail -1`
RUNNING_TIME2=`./a.out $command1 $command2 | tail -1`
RUNNING_TIME3=`./a.out $command1 $command2 | tail -1`
RUNNING_TIME4=`./a.out $command1 $command2 | tail -1`
RUNNING_TIME5=`./a.out $command1 $command2 | tail -1`
TOTAL=$(((RUNNING_TIME1 + RUNNING_TIME2 + RUNNING_TIME3 + RUNNING_TIME4 + RUNNING_TIME5) / 5))
echo $TOTAL
