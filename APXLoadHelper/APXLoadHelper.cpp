// APXLoadHelper.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "APXLoadHelper.h"
string APXLoadFileToString(LPCWSTR sciezka,bool errmsg, DWORD &dwPrzeczytane)
{
	string txt;
	LPSTR Bufor;
	DWORD dwRozmiar;
	HANDLE hPlik=CreateFile(sciezka,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
	if(hPlik==INVALID_HANDLE_VALUE)
	{
		if(errmsg==true)
		MessageBox(0,L"Nie znaleziono pliku o podanej nazwie",L"B³¹d",0);
		return "";
	}
	dwRozmiar=GetFileSize(hPlik,0);
	if(dwRozmiar>=0xFFFFFFFF)
	{
		if(errmsg==true)
		MessageBox(0,L"Nieprawid³owy rozmiar pliu",L"B³¹d",0);
		return "";
	}
	Bufor=(LPSTR) GlobalAlloc(GPTR,dwRozmiar+1);
	if(Bufor==NULL)
	{
		if(errmsg==true)
		MessageBox(0,L"Nie mo¿na zaalokowaæ pamiêci",L"B³¹d",0);
		return "";
	}
	if(!ReadFile(hPlik,Bufor,dwRozmiar,&dwPrzeczytane,0))
	{
		if(errmsg==true)
		MessageBox(0,L"Nie mo¿na odczytaæ pliu",L"B³¹d",0);
		return "";
	}
	else
	{
		txt=Bufor;
	}
	return txt;
}
string APXReadStringFromString(string txt,string LeftFind,bool errmsg, int next)
{
	string buf;
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXReadStringFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	char letter=txt[actualpoz];
	while(letter!='"')
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	actualpoz++;
	poz2=actualpoz;
	letter=txt[poz2];
	while(letter!='"')
	{
		poz2++;
		letter=txt[poz2];
	}
	nextcount++;
	nextpoz=poz2;
	}
	buf.insert(0, txt, actualpoz, poz2 -actualpoz);
	return buf;
}
int APXReadIntToDynamicTableFromString(vector<long int> &tab,string txt, string LeftFind,bool errmsg, int next)
{
	string buf;
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXReadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		if(letter=='-')
			break;
		actualpoz++;
		letter=txt[actualpoz];
	}
	poz2=actualpoz;
	while(isdigit(letter,loc)==true||isspace(letter,loc)==true||letter=='-')
	{
		poz2++;
		letter=txt[poz2];
	}
	nextcount++;
	nextpoz=poz2;
	}
	buf.insert(0, txt, actualpoz, poz2 -actualpoz);
	tab.push_back(strtol(buf.c_str(), &end, 10));
	while (actualpoz != poz2)
	{
		actualpoz = actualpoz + 1;
		letter = txt[actualpoz];
		if (isspace(letter, loc) != 0)
		{
			tab.push_back(strtol(end, &end, 10));
			IndexCount = IndexCount + 1;
		}
	}
	tab.pop_back();
	return IndexCount;
}
 int APXReadFloatToDynamicTableFromString(vector<float> &tab,string txt, string LeftFind,bool errmsg, int next)
 {
	 string buf;
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXReadFloatToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		if(letter=='-')
			break;
		actualpoz++;
		letter=txt[actualpoz];
	}
	poz2=actualpoz;
	while(isdigit(letter,loc)==true||isspace(letter,loc)==true||letter=='-'||letter=='.')
	{
		poz2++;
		letter=txt[poz2];
	}
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////////
	buf.insert(0, txt, actualpoz, poz2 -actualpoz);
	tab.push_back(strtod(buf.c_str(), &end));
	while (actualpoz != poz2)
	{
		actualpoz = actualpoz + 1;
		letter = txt[actualpoz];
		if (isspace(letter, loc) != 0)
		{
			tab.push_back(strtod(end, &end));
			IndexCount = IndexCount + 1;
		}
	}
	tab.pop_back();
	return IndexCount;
 }
 int APXLoadIntToDynamicTableFromString(vector<long int> &tab,string txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	string buf;
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	buf.insert(0, txt, actualpoz, poz2 -actualpoz);
	tab.push_back(strtol(buf.c_str(), &end, 10));
	while (actualpoz != poz2)
	{
		actualpoz = actualpoz + 1;
		letter = txt[actualpoz];
		if (isspace(letter, loc) != 0)
		{
			tab.push_back(strtol(end, &end, 10));
			IndexCount = IndexCount + 1;
		}
	}
	tab.pop_back();
	return IndexCount;
}
 int APXLoadFloatToDynamicTableFromString(vector<float> &tab,string txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	string buf;
	size_t actualpoz;
	size_t poz2;
	char * end;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	///////////////////////
	while(nextcount<=next)
	{
	actualpoz= txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadFloatToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadFloatToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	////////////////////////////////
	buf.insert(0, txt, actualpoz, poz2 -actualpoz);
	tab.push_back(strtod(buf.c_str(), &end));
	while (actualpoz != poz2)
	{
		actualpoz = actualpoz + 1;
		letter = txt[actualpoz];
		if (isspace(letter, loc) != 0)
		{
			tab.push_back(strtod(end, &end));
			IndexCount = IndexCount + 1;
		}
	}
	tab.pop_back();
	return IndexCount;
}
 int APXLoadIntToIntFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	string buf;
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToIntFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToIntFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	buf.insert(0, txt, actualpoz, poz2 -actualpoz);
	return strtol(buf.c_str(), &end, 10);
}
 float APXLoadFloatToFloatFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	string buf;
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToFloatFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToFloatFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	buf.insert(0, txt, actualpoz, poz2 -actualpoz);
	return strtod(buf.c_str(), &end);
}
 int APXWriteFloatTabToString(vector <float> num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	string smalltxt;
	string subnumstr,pause=" ";
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	for(int i=0; i<num.size(); i++)
	 {
		 smalltxt=to_string(static_cast<long double>(num[i]));
		 subnumstr=subnumstr+pause+smalltxt;
	 }
	/////////////////////
	txt.replace(actualpoz, poz2-actualpoz,subnumstr);
	return 0;
}
 int APXWriteFloatToString(float num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	string smalltxt;
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	smalltxt=to_string(static_cast<long double>(num));
	txt.replace(actualpoz, poz2-actualpoz,smalltxt);
	return 0;
}

 int APXWriteIntTabToString(vector <int> num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	char tchar[10];
	string subnumstr,pause=" ";
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	for(int i=0; i<num.size(); i++)
	 {
		 itoa(num[i],tchar,10);
		 subnumstr=subnumstr+pause+tchar;
	 }
	/////////////////////
	txt.replace(actualpoz, poz2-actualpoz,subnumstr);
	return 0;
}
 int APXWriteIntToString(int num,string& txt, string LeftFind, string RigthFind,bool errmsg, int next)
{
	char tchar[10];
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isdigit(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isdigit(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	itoa(num,tchar,10);
	txt.replace(actualpoz, poz2-actualpoz,tchar);
	return 0;
}
  int APXWriteStringToString(string& text,string& txt, string LeftFind, string RigthFind,bool errmsg, int next)
 {
	 //text jest stringirm który w³¹czamy a txt stringiem do którego w³¹czamy
	char * end;
	size_t actualpoz;
	size_t poz2;
	char letter;
	locale loc;
	int IndexCount = 0, nextcount=0,nextpoz=0;
	/////////////////////
	while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The first phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The first phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		OutputDebugStringW(L"The second phraze is not found. The Functions returns 0");
		MessageBoxW(0,L"The second phraze is not found. The Function APXLoadIntToDynamicTableFromString returns 0",L"B³¹d",0);
		}
		return 0;
	}
    char letter=txt[actualpoz];
	while(isspace(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	letter=txt[poz2];
	while(isspace(letter,loc)==false)
	{
		poz2--;
		letter=txt[poz2];
	}
	poz2++;
	nextcount++;
	nextpoz=poz2;
	}
	/////////////////////
	txt.replace(actualpoz, poz2-actualpoz,text);
	return 1;
 }
  string APXLoadStringToStringFromString(string txt, string LeftFind, string RigthFind,bool errmsg, int next)
 {
	 string ExtractedTxt;
	 int nextcount=0,nextpoz=0;
	 char * end;
	size_t actualpoz;
	size_t poz2;
	locale loc;
	LPWSTR text[2]={L"The openning phraze is not found. Invalid or non existing in the file",L"The closing phraze is not found. Invalid or non existing in the file"};
	 while(nextcount<=next)
	{
	actualpoz = txt.find(LeftFind,nextpoz);
	if(actualpoz==string::npos)
	{
		if(errmsg==true)
		{
		MessageBoxW(0,text[0],L"Error",0);
		}
		return 0;
	}
	char letter=txt[actualpoz];
	while(isspace(letter,loc)==false)
	{
		actualpoz++;
		letter=txt[actualpoz];
	}
	poz2 = txt.find(RigthFind,nextpoz+strlen(RigthFind.c_str()));
	if(poz2==string::npos)
	{
		if(errmsg==true)
		{
		MessageBoxW(0,text[1],L"B³¹d",0);
		}
		return 0;
	}
	nextcount++;
	nextpoz=poz2;
	}
	 ExtractedTxt.insert(0, txt, actualpoz, poz2 -actualpoz);
	 return ExtractedTxt;
 }


// This is the constructor of a class that has been exported.
// see APXLoadHelper.h for the class definition
CAPXLoadHelper::CAPXLoadHelper()
{
	return;
}
