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

Fixed Fixed::operator++(int i)
{
	return Fixed(this->value + 1);
}

Fixed Fixed::operator--(int i)
{
	return Fixed(this->value - 1);
}

Fixed& Fixed::operator++()
{
	this->setRawBits(this->value + 1);
	return *this;
}

Fixed& Fixed::operator--()
{
	this->setRawBits(this->value - 1);
	return *this;
}

Fixed &Fixed::min(Fixed &input1, Fixed &input2)
{
	if (input1.getRawBits() < input2.getRawBits())
		return input1;
	return input2;
}

Fixed &Fixed::max(Fixed &input1, Fixed &input2)
{
	if (input1.getRawBits() > input2.getRawBits())
		return input1;
	return input2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

bool operator<(const Fixed& input1, const Fixed& input2)
{
	return input1.getRawBits() < input2.getRawBits();
}

bool operator>(const Fixed& input1, const Fixed& input2)
{
	return input1.getRawBits() > input2.getRawBits();
}

bool operator<=(const Fixed& input1, const Fixed& input2)
{
	return !(input1.getRawBits() > input2.getRawBits());
}

bool operator>=(const Fixed& input1, const Fixed& input2)
{
	return !(input1.getRawBits() < input2.getRawBits());
}

bool operator==(const Fixed& input1, const Fixed& input2)
{
	return !(input1.getRawBits() > input2.getRawBits()) && !(input1.getRawBits() < input2.getRawBits());
}

bool operator!=(const Fixed& input1, const Fixed& input2)
{
	return !(input1.getRawBits() == input2.getRawBits());
}

Fixed operator+(const Fixed& input1, const Fixed& input2)
{
	return Fixed(input1.getRawBits() + input2.getRawBits());
}

Fixed operator-(const Fixed& input1, const Fixed& input2)
{
	return Fixed(input1.getRawBits() - input2.getRawBits());
}

Fixed operator*(const Fixed& input1, const Fixed& input2)
{
	return Fixed(input1.getRawBits() * input2.getRawBits());
}

Fixed operator/(const Fixed& input1, const Fixed& input2)
{
	return Fixed(input1.getRawBits() / input2.getRawBits());
}