#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed(void) : _fixedPointValue(0)
{

}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits)
{

}

Fixed::Fixed(const float n) : _fixedPointValue(std::roundf(n * (1 << _fractionalBits)))
{

}

Fixed::Fixed(const Fixed &rhs)
{
    *this = rhs;
}

Fixed& Fixed::operator=( const Fixed &rhs ) 
{
    if ( this != &rhs )
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->getRawBits()) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}

bool    Fixed::operator>(const Fixed &rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<(const Fixed &rhs) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=(const Fixed &rhs) const
{
    return this->getRawBits() >= rhs.getRawBits();
}

bool    Fixed::operator<=(const Fixed &rhs) const
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool    Fixed::operator==(const Fixed &rhs) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
    return this->getRawBits() != rhs.getRawBits();
}

Fixed   Fixed::operator+(const Fixed &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&   Fixed::operator++(void)
{
    ++this->_fixedPointValue;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue++;
    return tmp;
}

Fixed&   Fixed::operator--(void)
{
    --this->_fixedPointValue;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue--;
    return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}