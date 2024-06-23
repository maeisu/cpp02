#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
    private:
        int value;
		static const int bits = 8;
    public:
        Fixed();
		Fixed(const Fixed &source);
		~Fixed();
		Fixed& operator=(const Fixed &source);
		int getRawBits(void) const;
		void setRawBits( int const raw );
};

#endif