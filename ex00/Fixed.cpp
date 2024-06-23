#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed &source) : value(source.value)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &source)
{
	if (this == &source)
        return *this;

}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
