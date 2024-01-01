COMPETITIVE_PATH=$HOME/Competitive

ATCODER_PATH=$COMPETITIVE_PATH/AtCoder

AC_LIBRARY_PATH=$COMPETITIVE_PATH/ac-library
MY_LIBRARY_PATH=$COMPETITIVE_PATH/my-library

export CPLUS_INCLUDE_PATH=$ATCODER_LIBRARY_PATH

function acnew(){
	cd $ATCODER_PATH
	acc new $1
	cd $ATCODER_PATH/$1
}

function acmake(){
	make -f $MY_LIBRARY_PATH/acc/cpp/makefile $1
}

function acsubmit(){
	echo "\033[36mSubmit? (y/n)\033[0m"
	read input
	if [[ $input == "y" ]]; then
		acc submit .bundled.cpp -- -y -w 0
	fi
}

function actest(){
	if acmake all; then
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
