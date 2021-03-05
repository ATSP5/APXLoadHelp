// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the APXLOADHELPER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// APXLOADHELPER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include <vector>
#include <string>
#include <locale>
#include <Windows.h>
using namespace std;

#ifdef APXLOADHELPER_EXPORTS
#define APXLOADHELPER_API __declspec(dllexport)
#else
#define APXLOADHELPER_API __declspec(dllimport)
#endif

// This class is exported from the APXLoadHelper.dll
class APXLOADHELPER_API CAPXLoadHelper {
public:
	CAPXLoadHelper(void);
	// TODO: add your methods here.
};

extern APXLOADHELPER_API int nAPXLoadHelper;

APXLOADHELPER_API int fnAPXLoadHelper(void);

extern "C"
{
	/*
	Funkcja laduj�ca plik do pami�ci (zwracaj�ca) jako string. Zmienna scieza zawiera �cie�k� dost�pu do pliku: 
	"C:\ExampleFolder\ExampleFile.example_extension", lub "ExampleFile.example_extension" gdy plik jest w tym samym folderze co main.cpp
	errmsg (dotyczy wszystkich) Czy maj� by� wy�wietlone komunikaty b��d�w (true/false) dwPrzeczytane Zmienna przechowuj�ca ilo�� 
	przeczytanych bajt�w.
	*/
 string APXLoadFileToString(LPCWSTR sciezka,bool errmsg, DWORD &dwPrzeczytane);
 /*
 Funkcja zwraca cz�� ze stringa txt rozpoczynaj�cego si� od LeftFind znajduj�cego si� domy�lnie mi�dzy dwoma: " "
 */
 string APXReadStringFromString(string txt,string LeftFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca vector typu long int ze zmiennej txt typu string, zaczynaj�c od znacznika LeftFind. Zmienna next pozwala na okre�lenie
  kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXReadIntToDynamicTableFromString(vector<long int> &tab,string txt, string LeftFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca vector typu float ze zmiennej txt typu string, zaczynaj�c od znacznika LeftFind. Zmienna next pozwala na okre�lenie
  kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXReadFloatToDynamicTableFromString(vector<float> &tab,string txt, string LeftFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca vector typu long int ze zmiennej txt typu string, pomi�dzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXLoadIntToDynamicTableFromString(vector<long int> &tab,string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca vector typu float ze zmiennej txt typu string, pomi�dzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int  APXLoadFloatToDynamicTableFromString(vector<float> &tab,string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca zmienn� int (zwraca) ze zmiennej txt typu string, pomi�dzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXLoadIntToIntFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
  /*
  Funkcja �aduj�ca zmienn� int (zwraca) ze zmiennej txt typu string, pomi�dzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 float APXLoadFloatToFloatFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca zmienn� txt typu string z tablicy typu vector<float> i umieszcza j� pomi�dzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXWriteFloatTabToString(vector <float> num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca zmienn� txt typu string z zmiennej typu float i umieszcza j� pomi�dzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXWriteFloatToString(float num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca zmienn� txt typu string z tablicy typu vector<int> i umieszcza j� pomi�dzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXWriteIntTabToString(vector <int> num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca zmienn� txt typu string z zmiennej typu float i umieszcza j� pomi�dzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje).
 */
 int APXWriteIntToString(int num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja �aduj�ca zmienn� txt typu string z zmiennej text typu string i umieszcza j� pomi�dzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okre�lenie kolejnego znacznika o tej samej nazwie (je�li istnieje). 
  Zmienna txt string do kt�rego piszemy text string kt�ry piszemy do txt
 */
 int APXWriteStringToString(string& text,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
 Funkcja zwracaj�ca tekst (string) ze zmiennej txt typu string. Zwr�cony tekst zostaje znaleziony pomi�dzy znacznikami
 LeftFind a RigthFind w zmiennej txt.
 */
 string APXLoadStringToStringFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
}