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
	Funkcja laduj¹ca plik do pamiêci (zwracaj¹ca) jako string. Zmienna scieza zawiera œcie¿kê dostêpu do pliku: 
	"C:\ExampleFolder\ExampleFile.example_extension", lub "ExampleFile.example_extension" gdy plik jest w tym samym folderze co main.cpp
	errmsg (dotyczy wszystkich) Czy maj¹ byæ wyœwietlone komunikaty b³êdów (true/false) dwPrzeczytane Zmienna przechowuj¹ca iloœæ 
	przeczytanych bajtów.
	*/
 string APXLoadFileToString(LPCWSTR sciezka,bool errmsg, DWORD &dwPrzeczytane);
 /*
 Funkcja zwraca czêœæ ze stringa txt rozpoczynaj¹cego siê od LeftFind znajduj¹cego siê domyœlnie miêdzy dwoma: " "
 */
 string APXReadStringFromString(string txt,string LeftFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca vector typu long int ze zmiennej txt typu string, zaczynaj¹c od znacznika LeftFind. Zmienna next pozwala na okreœlenie
  kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXReadIntToDynamicTableFromString(vector<long int> &tab,string txt, string LeftFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca vector typu float ze zmiennej txt typu string, zaczynaj¹c od znacznika LeftFind. Zmienna next pozwala na okreœlenie
  kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXReadFloatToDynamicTableFromString(vector<float> &tab,string txt, string LeftFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca vector typu long int ze zmiennej txt typu string, pomiêdzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXLoadIntToDynamicTableFromString(vector<long int> &tab,string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca vector typu float ze zmiennej txt typu string, pomiêdzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int  APXLoadFloatToDynamicTableFromString(vector<float> &tab,string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca zmienn¹ int (zwraca) ze zmiennej txt typu string, pomiêdzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXLoadIntToIntFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
  /*
  Funkcja ³aduj¹ca zmienn¹ int (zwraca) ze zmiennej txt typu string, pomiêdzy znacznika LeftFind i RigthFind. Zmienna next pozwala
  na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 float APXLoadFloatToFloatFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca zmienn¹ txt typu string z tablicy typu vector<float> i umieszcza j¹ pomiêdzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXWriteFloatTabToString(vector <float> num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca zmienn¹ txt typu string z zmiennej typu float i umieszcza j¹ pomiêdzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXWriteFloatToString(float num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca zmienn¹ txt typu string z tablicy typu vector<int> i umieszcza j¹ pomiêdzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXWriteIntTabToString(vector <int> num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca zmienn¹ txt typu string z zmiennej typu float i umieszcza j¹ pomiêdzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje).
 */
 int APXWriteIntToString(int num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
  Funkcja ³aduj¹ca zmienn¹ txt typu string z zmiennej text typu string i umieszcza j¹ pomiêdzy znacznikami LeftFind i RigthFind. 
  Zmienna next pozwala na okreœlenie kolejnego znacznika o tej samej nazwie (jeœli istnieje). 
  Zmienna txt string do którego piszemy text string który piszemy do txt
 */
 int APXWriteStringToString(string& text,string& txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
 /*
 Funkcja zwracaj¹ca tekst (string) ze zmiennej txt typu string. Zwrócony tekst zostaje znaleziony pomiêdzy znacznikami
 LeftFind a RigthFind w zmiennej txt.
 */
 string APXLoadStringToStringFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next=0);
}