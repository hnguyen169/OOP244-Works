//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 06/15/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const {
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const {
       return m_number >= 10000 && m_number <= 99999;
   }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }
   bool Account::operator~() const{
       return m_number == 0;
   }
   Account& Account::operator=(int num) {
       if (m_number == 0) {
           if (num >= 10000 && num <= 99999) {
               m_number = num;
           }
           else {
               setEmpty();
           }
       }
       return *this;
   }
   Account& Account::operator=(Account& acc) {
       if (~(*this) && acc) {
           m_number = acc.m_number;
           m_balance = acc.m_balance;
           acc.m_number = 0;
           acc.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator+=(double val) {
       if (*this && val > 0) {
           m_balance += val;
       }
       return *this;
   }
   Account& Account::operator-=(double val) {
       if (*this && val > 0 && m_balance >= val) {
           m_balance -= val;
       }
       return *this;
   }
   Account& Account::operator<<(Account& acc) {
       if (*this && acc && this != &acc) {
           m_balance += acc.m_balance;
           acc.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& acc) {
       if (*this && acc && this != &acc) {
           acc.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }
   double operator+(const Account& acc1, const Account& acc2) {
       if (acc1 && acc2) {
           return acc1.operator double() + acc2.operator double();
       }
       return 0.0;
   }
   double operator+=(double& val, const Account& acc) {
       if (acc) {
           val += acc.operator double();
       }
       return val;
   }
}