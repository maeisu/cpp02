#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
	this->value = value << Fixed::bits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed &source) : value(source.value)
{
}

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &source)
{
	if (this == &source)
        return *this;
	this->value = source.value;
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

float Fixed::toFloat(void) const
{
	return this->value / (float)(1 << Fixed::bits);
}

int Fixed::toInt(void) const
{
	return this->value >> Fixed::bits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
