#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <vector>
# include <list>
# include <ctime>
# include <sys/time.h>
# include <climits>
# include <unistd.h>
# include <algorithm>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define RUN 8

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

		void		startMergeInsertList( int argc, char **argv );
		void		executeListSortingAlgorithm( void );
		void		insertionSortList( std::list<int>::iterator leftLimit, std::list<int>::iterator rightLimit );
		void		mergeList( std::list<int>::iterator leftLimit, std::list<int>::iterator midPoint, std::list<int>::iterator rightLimit );

		std::list<int>::iterator	addRunSizeOrToTheTnd(std::list<int>::iterator it );
		void						printList();
		void						printList(std::list<int>::iterator begin, std::list<int>::iterator end);

	private:

		char				**_originalInput;

		std::vector<int>	_inputVector;
		struct timeval		_vectorStartTime;
		struct timeval		_vectorEndTime;
		long				_vectorDuration;

		std::list<int>		_inputList;
		struct timeval		_listStartTime;
		struct timeval		_listEndTime;
		long				_listDuration;

};

#endif
