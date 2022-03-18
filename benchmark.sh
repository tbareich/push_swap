# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 08:50:14 by tbareich          #+#    #+#              #
#    Updated: 2022/03/18 22:51:10 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#!/bin/bash

MAX=0
ITERATIONS=0
LIMIT=700
FILE=problem_100
SUM=0

for i in {1..100}
do
		export ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
		OPT="$(./push_swap $ARG)"
		if echo "$OPT" | ./checker $ARG | grep -q KO
		then
			echo "Error!"
			echo $ARG
			break
		fi
		NUMBER="$(echo "$OPT" | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo $NUMBER >> $FILE
			echo $ARG >> $FILE
			break
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo $i ":" $NUMBER
		let SUM+=$NUMBER;
		let ITERATIONS+=1
done

if [ "$ITERATIONS" -gt "0" ]
	then
	echo "AVG: $(($SUM / $ITERATIONS))"
fi
echo "MAX: " $MAX