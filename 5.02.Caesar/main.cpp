//==========================================================
//
//	  Filename:	main.cpp
//
// Description: TODO	
//
//	   Version:	1.0
// 	   Created:	26.10.2015 19:34:45
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <cmath>

using namespace std;

void ausgabeFeld(char a[], unsigned int n)
{
   for (unsigned int i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

void feld_wenden(char a[], unsigned int n)
{
   char zwischenspeicher;
   // Ganzzahl division gewollt
   for (unsigned int i = 0; i < n / 2; i++)
   {
      zwischenspeicher = a[i];
      a[i] = a[n - i -1];  // -1 da im letzten Feld \0 steht
      a[n - i - 1] = zwischenspeicher;
   }
}

void feld_links_rotieren(char a[], unsigned int n, unsigned int shift)
{
   feld_wenden(a, shift);
   feld_wenden(a, n);
   feld_wenden(a, n-shift);
}

void feld_rechts_rotieren(char a[], unsigned int n, unsigned int shift)
{
   feld_wenden(a, n - shift);
   feld_wenden(a, n);
   feld_wenden(a, shift);
}


int main ( )
{
   const int feldGroesse = 26;
   char feld[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
   cout << "Feld im Original:                                           ";
   ausgabeFeld(feld, feldGroesse);
   feld_wenden(feld, feldGroesse);
   cout << "Feld komplett gewendet:                                     ";
   ausgabeFeld(feld, feldGroesse);
   feld_wenden(feld, feldGroesse);
   cout << "Feld komplett gewendet:                                     ";
   ausgabeFeld(feld, feldGroesse);
   feld_links_rotieren(feld, feldGroesse, 5);
   cout << "Verschiebung eines Feldinhalts um 5 Positionen nach Links:  ";
   ausgabeFeld(feld, feldGroesse);
   feld_rechts_rotieren(feld, feldGroesse, 5);
   cout << "Verschiebung eines Feldinhalts um 5 Positionen nach Rechts: ";
   ausgabeFeld(feld, feldGroesse);

   return (0);
}

