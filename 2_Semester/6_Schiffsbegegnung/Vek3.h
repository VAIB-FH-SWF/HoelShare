/*****************************************************************/
/* 	  Dateiname: Vek3.h 										 */
/* Beschreibung: Definition der Klasse Vektor					 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 10.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#ifndef VEK3_H_
#define VEK3_H_
#include <iostream>

using namespace std;

class Vek3
{
	public:
		// ====================  LIFECYCLE     =======================================
		Vek3(double _x = 0.0, double _y = 0.0, double _z = 0.0);
		// ==================== ACCESSORS =======================================
		// Komponentenzugriff
		double get_x() const
		{
			return x;
		}
		// Komponentenzugriff
		double get_y() const
		{
			return y;
		}
		// Komponentenzugriff
		double get_z() const
		{
			return z;
		}
		// Vektorlaenge
		double laenge() const;

		// ====================  MUTATORS   =======================================
		Vek3& set(double _x = 0.0, double _y = 0.0, double _z = 0.0);
		Vek3& set_x(double _x = 0.0)
		{
			this->x = _x;
			return *this;
		}
		Vek3& set_y(double _y = 0.0)
		{
			this->y = _y;
			return *this;
		}
		Vek3& set_z(double _z = 0.0)
		{
			this->z = _z;
			return *this;
		}
		Vek3& set_all(double val = 0.0);
		/**
		 * Nullvektor
		 * @return
		 */
		Vek3& set_zero();
		/**
		 * Einheitsvektor X-Richtung
		 * @return
		 */
		Vek3& set_unit_x();
		/**
		 * Einheitsvektor Y-Richtung
		 * @return
		 */
		Vek3& set_unit_y();
		/**
		 * Einheitsvektor Z-Richtung
		 * @return
		 */
		Vek3& set_unit_z();
		/**
		 * Vektor normieren
		 * @return
		 */
		Vek3& norm();

		// ==================== OPERATORS=======================================
		Vek3& operator +=(const Vek3 &other);	// Addition mit Zuweisung
		Vek3& operator -=(const Vek3 &other);	// Subtraktion mit Zuweisung
		Vek3& operator *=(double s);	// Multiplikation mit Skalar
		Vek3& operator /=(double s);	// Multiplikation mit 1/Skalar
		Vek3 operator +();	// positives Vorzeichen
		Vek3 operator -();	// negatives Vorzeichen

		friend Vek3 operator +(const Vek3 &v1, const Vek3 &v2); // Addition
		friend Vek3 operator -(const Vek3 &v1, const Vek3 &v2); // Subtraktion
		friend double operator *(const Vek3 &v1, const Vek3 &v2); // Skal.prod.
		friend Vek3 operator *(const Vek3 &v, const double s); // Vek*Skalar
		friend Vek3 operator *(const double s, const Vek3 &v); // Skalar*Vek
		friend Vek3 operator /(const Vek3 &v, const double s); // Vek/Skalar
		friend Vek3 operator %(const Vek3 &v1, const Vek3 &v2); // Kreuzprodukt

	private:
		// ==================== DATA MEMBERS =======================================
		double x, y, z; // Vektorkomponenten

};

ostream& operator <<(ostream & os, const Vek3 & obj);
#endif /* VEK3_H_ */
