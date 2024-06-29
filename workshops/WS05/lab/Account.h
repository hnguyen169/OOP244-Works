//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 06/15/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number; // account number
      double m_balance; // account balance
      // sets account to empty: m_number = -1, m_balance = 0.0
      void setEmpty();
   public:
      // sets account to new: m_number = 0, m_balance = 0.0
      Account();
      // sets account to incoming arguments if valid, otherwise sets account to empty
      Account(int number, double balance);
      // displays the account on screen
      std::ostream& display() const;
      // returns true if account is valid, false otherwise
      operator bool() const;
      // returns account number
      operator int() const;
      // returns balance value
      operator double() const;
      // returns true if account is new or not set, false otherwise
      bool operator~() const;
      // if new account, sets account number to the integer argument if valid.
      // if integer is invalid, sets to invalid state.
      // if not new account, takes no action.
      Account& operator=(int num);
      // if new account, sets account number and balance from the argument account if valid.
      // then sets argument account to new state.
      // if not new account or argument account is invalid, takes no action.
      Account& operator=(Account& acc);
      // if account is valid and val is positive, adds val to account balance otherwise, takes no action.
      Account& operator+=(double val);
      // if account is valid, val is positive, and there are enough funds then subtracts val from account balance.
      // if account is invalid, value is negative, or not enough funds, takes no action.
      Account& operator-=(double val);
      // if both accounts are valid and not the same, transfers argument balance into current account balance.
      // then sets balance of argument account to 0.0.
      // if either accounts are invalid or the same account, takes no action.
      Account& operator<<(Account& acc);
      // if both accounts are valid and not the same, transfers current account balance into argument balance.
      // then sets current account balance to 0.0.
      // if either accounts are invalid or the same account, takes no action.
      Account& operator>>(Account& acc);
   };
   // if both accounts are valid, returns sum of balances of both accounts.
   // if either account is invalid, returns zero.
   double operator+(const Account& acc1, const Account& acc2);
   // if account is valid, adds argument account balance to the val from argument then returns val.
   double operator+=(double& val, const Account& acc);
}
#endif // SENECA_ACCOUNT_H_