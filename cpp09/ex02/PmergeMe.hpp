#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <vector>
# include <ctime>
# include <sys/time.h>
# include <climits>
# include <unistd.h>
# include <algorithm>
# include <deque>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define RUN 32

class PmergeMe{

	public:

		PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		~PmergeMe( void );

		PmergeMe &	operator=( PmergeMe const & rhs );

		int			printError( void ) const;
		int			printError( std::string str ) const;
		int			printError( std::string str , int i ) const;
		int			startProcess( int argc, char **argv );
		int			checkArgs( int argc, char **argv );
		void		printResults( void );

		void		startMergeInsertVector( int argc, char **argv );
		void		executeVectorSortingAlgorithm( void );
		void		insertionSortVector( int left, int right );
		void		mergeVector( int left, int mid, int right );

		void		startMergeInsertDeque( int argc, char **argv );
		void		executeDequeSortingAlgorithm( void );
		void		insertionSortDeque( int left, int right );
		void		mergeDeque( int left, int mid, int right );

	private:

		char				**_originalInput;

		std::vector<int>	_inputVector;
		struct timeval		_vectorStartTime;
		struct timeval		_vectorEndTime;
		long				_vectorDuration;

		std::deque<int>		_inputDeque;
		struct timeval		_dequeStartTime;
		struct timeval		_dequeEndTime;
		long				_dequeDuration;

};

#endif
