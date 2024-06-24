#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    private:
        int value;
		static const int bits = 8;
    public:
        Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &source);
		Fixed();
		~Fixed();
		Fixed& operator=(const Fixed &source);
		float toFloat(void) const;
		int toInt(void)const;
		int getRawBits(void) const;
		void setRawBits( int const raw );
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed& operator++();
		Fixed& operator--();
		Fixed& min(Fixed& input1, Fixed& input2);
		Fixed& max(Fixed& input1, Fixed& input2);
		Fixed& min(const Fixed& input1, const Fixed& input2);
		Fixed& max(const Fixed& input1, const Fixed& input2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
bool operator<(const Fixed& input1, const Fixed& input2);
bool operator>(const Fixed& input1, const Fixed& input2);
bool operator<=(const Fixed& input1, const Fixed& input2);
bool operator>=(const Fixed& input1, const Fixed& input2);
bool operator==(const Fixed& input1, const Fixed& input2);
bool operator!=(const Fixed& input1, const Fixed& input2);
Fixed operator-(const Fixed& input1, const Fixed& input2);
Fixed operator+(const Fixed& input1, const Fixed& input2);
Fixed operator*(const Fixed& input1, const Fixed& input2);
Fixed operator/(const Fixed& input1, const Fixed& input2);


#endif