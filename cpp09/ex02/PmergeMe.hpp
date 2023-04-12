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
		void		mergeInsertVector( int argc, char **argv );
		void		mergeInsertList( int argc, char **argv );
		void		printResults( void );

		// void		executeVectorSortingAlgorithm( void );
		// void		mergeSortVector( int left, int mid, int right );
		// void		insertionSortVector( int left, int right );

void	insertionSort(std::vector<int>& arr, int left, int right);
void	merge(std::vector<int>& arr, int left, int mid, int right);
void	mergeInsertSort(std::vector<int>& arr);

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
