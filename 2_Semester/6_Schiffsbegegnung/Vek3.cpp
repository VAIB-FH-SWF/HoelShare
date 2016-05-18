/*****************************************************************/
/*    Dateiname: Vek3.cpp										 */
/* Beschreibung: Implementierung des Vektors					 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 10.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include "Vek3.h"
#include <cmath>
/**
 *
 * @param _x
 * @param _y
 * @param _z
 */
Vek3::Vek3(double _x, double _y, double _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

/**
 * Gibt die Laenge des Vektors zurueck
 * @return
 */
double Vek3::laenge() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

/**
 * Setzt die Vektorelemente
 * @param _x
 * @param _y
 * @param _z
 * @return Diesen Vektor
 */
Vek3& Vek3::set(double _x, double _y, double _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;

	return *this;
}

/**
 * Setzt alle Vektorelemente auf Value
 * @param val
 * @return Diesen Vektor
 */
Vek3& Vek3::set_all(double val)
{
	return set(val, val, val);
}

/**
 * Setzt den Vektor auf 0
 * @return Diesen Vektor
 */
Vek3& Vek3::set_zero()
{
	return set_all(0);
}

/**
 * Einheitsvektor in X-Richtung erzeugen
 * @return Diesen Vektor
 */
Vek3& Vek3::set_unit_x()
{
	this->x = 1;
	this->y = 0;
	this->z = 0;
	return *this;
}

/**
 * Einheitsvektor in Y-Richtung erzeugen
 * @return Diesen Vektor
 */
Vek3& Vek3::set_unit_y()
{
	this->x = 0;
	this->y = 1;
	this->z = 0;
	return *this;
}

/**
 * Einheitsvektor in Z-Richtung erzeugen
 * @return Diesen Vektor
 */
Vek3& Vek3::set_unit_z()
{
	this->x = 0;
	this->y = 0;
	this->z = 1;
	return *this;
}

/**
 * Normiert den Vektor
 * @return Diesen Vektor
 */
Vek3& Vek3::norm()
{
	// norm = a/|a|
	return *this /= laenge();
}

/**
 * Vektor Addition
 * @param other
 * @return Diesen Vektor
 */
Vek3& Vek3::operator +=(const Vek3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

/**
 * Vektorsubtraktion
 * @param other
 * @return Diesen Vektor
 */
Vek3& Vek3::operator -=(const Vek3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

/**
 * Multiplikation mit einem Skalar
 * @param s Skalar
 * @return Diesen Vektor
 */
Vek3& Vek3::operator *=(double s)
{
	this->x *= s;
	this->y *= s;
	this->z *= s;
	return *this;
}

/**
 * Multiplikation mit dem Kehrwert des Skalar
 * @param s
 * @return
 */
Vek3& Vek3::operator /=(double s)
{
	this->x /= s;
	this->y /= s;
	this->z /= s;
	return *this;
}

/**
 * Positives Vorzeichen
 * @return Diesen Vektor
 */
Vek3 Vek3::operator +()
{
	// Hier ist nichts zu tun
	return *this;
}

/**
 * Negatives Vorzeichen
 * @return Diesen Vektor
 */
Vek3 Vek3::operator -()
{
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
	return *this;
}

/**
 * Einfache Ausgabe funktion
 * Gibt den Vektor im Format
 * <b>[x, y, z]</b>
 * aus
 * @param os
 * @param obj
 * @return
 */
ostream& operator <<(ostream& os, const Vek3& obj)
{
	os << "[" << obj.get_x() << "; " << obj.get_y() << "; " << obj.get_z() << "]";
	return os;
}

/**
 * Vektor addition
 * @param v1
 * @param v2
 * @return v1 + v2
 */
Vek3 operator +(const Vek3 &v1, const Vek3 &v2)
{
	// Addition
	Vek3 ret;
	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;

	return ret;
}

/**
 * Subtraktion
 * @param v1
 * @param v2
 * @return v1 - v2
 */
Vek3 operator -(const Vek3 &v1, const Vek3 &v2)
{
	// Subtraktion
	Vek3 ret;
	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;

	return ret;

}

/**
 * Skalarprodukt zweier Vektoren
 * @param v1
 * @param v2
 * @return Skalar
 */
double operator *(const Vek3 &v1, const Vek3 &v2)
{
	// Skal.prod.
	double ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return ret;
}

/**
 * Multipliziert den Vektor mit dem Skalar
 * @param v
 * @param s
 * @return Vektor * Skalar
 */
Vek3 operator *(const Vek3 &v, const double s)
{
	// Vek*Skalar
	Vek3 ret;
	ret.x = v.x * s;
	ret.y = v.y * s;
	ret.z = v.z * s;

	return ret;
}

/**
 * Multipliziert den Vektor mit dem Skalar
 * @param s
 * @param v
 * @return Vektor * Skalar
 */
Vek3 operator *(const double s, const Vek3 &v)
{
	// Skalar*Vek
	return v * s;
}

/**
 * Teilt einen Vektor durch einen Skalar
 * @param v
 * @param s
 * @return Vektor / Skalar
 */
Vek3 operator /(const Vek3 &v, const double s)
{
	// Vek/Skalar
	return v * (1 / s);
}

/**
 * Operator fuer das Kreuzprodukt
 * @param v1
 * @param v2
 * @return Gibt das Kreuzprodukt zurueck
 */
Vek3 operator %(const Vek3 &v1, const Vek3 &v2)
{
	// Kreuzprodukt
	Vek3 ret;
	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;

	return ret;
}

