#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    ~Fixed();

    Fixed& operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    //---comparison operator---
    bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

    // --- arithmetic operator ---
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
		
    // --- increment/decrement operator ---
	Fixed&  operator++();       //Prefix increment
	Fixed   operator++(int);    //Postfix increment
	Fixed&  operator--();       //Prefix decrement
	Fixed   operator--(int);    //Postfix decrement

    // --- min and max ---
	static Fixed& min(Fixed& n1, Fixed& n2);
	static const Fixed& min(const Fixed& n1, const Fixed& n2);
	static Fixed& max(Fixed& n1, Fixed& n2);
	static const Fixed& max(const Fixed& n1, const Fixed& n2);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif