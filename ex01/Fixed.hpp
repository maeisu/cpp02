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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif