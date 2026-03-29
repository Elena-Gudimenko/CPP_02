/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:15:05 by elvictor          #+#    #+#             */
/*   Updated: 2026/03/27 14:15:05 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" <<std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}