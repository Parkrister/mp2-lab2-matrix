// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
#include <Windows.h>
HANDLE nConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//---------------------------------------------------------------------------

void main()
{
	SetConsoleTextAttribute(nConsole, 15);

	TVector<int> a(5), b(5), c(5);

  setlocale(LC_ALL, "Russian");
  cout << "\n������������ �������� ��������� ������������� ��������\n";


  TVector<int> w(3);
  for (int i = 0; i < 3; i++) {
	  w[i] = i + 1;
  }


  TVector<int> q(3);
  for (int i = 0; i < 3; i++) {
	  q[i] = 2 * (i + 1);
  }

  int res = w * q;

  cout << res;
  return;


  for (int i = 0; i < a.GetSize(); i++) {
	  a[i] = i;
  }

  b = b + 5;

  cout << "a = " << a << '\n' << "b = " << b <<'\n';
  cout << "a+b = " << a + b << '\n' << "a*b = " << a * b;



  //cout << "\n������������ �������� ��������� ������������� ����������� ������\n";

  TMatrix<int> x(5), y(5);
  TMatrix<int> z(2);


  //for (int i = 0; i < x.GetSize(); i++) {
	 // TVector<int> tmp(x[i].GetSize(), x[i].GetStartIndex());
	 // tmp = tmp + i;
	 // cout << tmp << endl;
	 // x[i] = tmp;
  //}
  for (int i = 0; i < x.GetSize(); i++) {
	  TVector<int> tmp(x[i].GetSize(), x[i].GetStartIndex());
	  tmp = tmp + i;
	  x[i] = tmp;
  }


  cout << x;

  //for (int i = 0; i < x.GetSize(); i++) {
	 // TVector<int> tmp(x[i].GetSize(), x[i].GetStartIndex());
	 // tmp = tmp + i;
	 // x[i] = x[i] + tmp;
  //}

  //cout << x;

  //for (i = 0; i < 5; i++)
  //  for (j = i; j < 5; j++ )
  //  {
  //    x[i][j] =  i * 10 + j;
  //    y[i][j] = (i * 10 + j) * 100;
  //  }
  //z = x + y;
  //cout << "Matrix a = " << endl << x << endl;
  //cout << "Matrix b = " << endl << y << endl;
  //cout << "Matrix c = a + b" << endl << z << endl;
}
//---------------------------------------------------------------------------
