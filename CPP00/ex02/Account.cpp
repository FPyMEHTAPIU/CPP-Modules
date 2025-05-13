#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ): _amount(initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	std::cout << "[19920104_091532] index:" << _accountIndex
		<< ";amount:" << initial_deposit << ";created" << std::endl;
	_totalAmount += initial_deposit;
}

Account::Account( void ) {
	
}

Account::~Account( void ) {
	std::cout << "[19920104_091532] index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << std::endl;
}

int		Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int		Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int		Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {}

void	Account::makeDeposit( int deposit ) {
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
	return (false);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {}

void	Account::_displayTimestamp( void ) {
	std::time_t t = std::time(nullptr);
	std::tm *now = std::localtime(&t);

	std::cout << '['
		<< std::setw(4) << std::setfill('0') << (now->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << now->tm_mday
		<< '_'
		<< std::setw(2) << std::setfill('0') << now->tm_hour
		<< std::setw(2) << std::setfill('0') << now->tm_min
		<< std::setw(2) << std::setfill('0') << now->tm_sec
		<< ']';
}
