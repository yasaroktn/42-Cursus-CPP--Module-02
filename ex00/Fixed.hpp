#ifndef FIXED_HPP
# define FIXED_HPP

#include "iostream"

class Fixed
{
    private:
        int                 _fixedPoint;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &rhs);
        Fixed& operator=(const Fixed &rhs);
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(int const raw);


};

#endif