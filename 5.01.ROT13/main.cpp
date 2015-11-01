//==========================================================
//
//	  Filename:	main.cpp
//
// Description: TODO	
//
//	   Version:	1.0
// 	   Created:	26.10.2015 19:06:40
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

bool isInArray(const char* array, char objekt, int groesse)
{
   int i = 0;
   while (i < groesse)
   {
      if (array[i++] == objekt)
         return (true);
   }
   return (false);
}

int main()
{
   ifstream ifs;
   ofstream ofs;
   char c; // Speichert den gelesenen Character
   char ROT13[] = { 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};

   ifs.open("klar.txt");

   if(!ifs)
   {
      cout << "Die Datei klar.txt kann nicht geoeffnet werden!" << endl;
      exit(1);
   }

   ofs.open("geheim.txt");

   if(!ofs)
   {
      cout << "Kann die Datei geheim.txt nicht zum schreiben öffnen!" << endl;
      exit(1);
   }

   while((c = ifs.get()) != EOF)
   {
      if (isInArray(ROT13, c, 26))
      // Wenn das Zeichen im Array vorhanden ist, wird es verschluesselt
      {
         ofs << ROT13[c - 'A'];
      }
      else
      {
         ofs << c;
      }
   }

   ofs.close();
   ifs.close();

   cout << "Geheimtext erstellt!";
}
