/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:15:57 by elvictor          #+#    #+#             */
/*   Updated: 2026/03/27 14:15:57 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int n)
{
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    this->_value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    this->_value = other.getRawBits();
}

Fixed::~Fixed(){
}

// --- Assigment operator ---
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// --- comparison operator ---
bool Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other.getRawBits());
}

// ***** arithmetic operator *****
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed sum;

	sum.setRawBits(_value + other.getRawBits());
	return sum;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed sub;

	sub.setRawBits(_value - other.getRawBits());
	return sub;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed mult;

	mult.setRawBits((_value * other.getRawBits()) / (1 << _fractionalBits));
	return mult;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed div;

	//div.setRawBits(_value/ other.getRawBits());
    div.setRawBits((this->_value << _fractionalBits) / other.getRawBits());
	return div;
}

// --- increment/decrement operator ---
Fixed& Fixed::operator++(){
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value--;
	return temp;
}

// --- min and max ---
Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

// --- Getters and Setters --
int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// --- Convert to ---
float Fixed::toFloat() const
{
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt() const
{
    return (_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}