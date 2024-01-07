export COMPETITIVE_PATH=$HOME/Competitive

export ATCODER_PATH=$COMPETITIVE_PATH/AtCoder

export AC_LIBRARY_PATH=$COMPETITIVE_PATH/ac-library
export MY_LIBRARY_PATH=$COMPETITIVE_PATH/my-library/algo

export CPLUS_INCLUDE_PATH=$ATCODER_LIBRARY_PATH:$MY_LIBRARY_PATH

function acnew(){
	cd $ATCODER_PATH
	acc new $1
	cd $ATCODER_PATH/$1
}

function acsubmit(){
	echo "\033[36mSubmit? (y/n)\033[0m"
	read input
	if [[ $input == "y" ]]; then
		acc submit submit.cpp -- -y -w 0
	fi
}

function actest(){
	if make all; then
		if oj t -c "./a.out" -t 5 -e 1e-6 -N; then
			echo "\033[32mAccepted\033[0m"
			acsubmit
		else
			echo "\033[33mNot Accepted\033[0m"
		fi
	else
		echo "\033[33mCompilation Error\033[0m"
	fi
}
