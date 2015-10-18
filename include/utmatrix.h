// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v);  // конструктор копирования
	  ~TVector();
  int GetSize()      { return Size;       } // размер вектора
  int GetStartIndex(){ return StartIndex; } // индекс первого элемента
  ValType& operator[](int pos);             // доступ
  bool operator==(const TVector &v) const;  // сравнение
  bool operator!=(const TVector &v) const;  // сравнение
  TVector& operator=(const TVector &v);     // присваивание

  // скалярные операции
  TVector  operator+(const ValType &val);   // прибавить скаляр
  TVector  operator-(const ValType &val);   // вычесть скаляр
  TVector  operator*(const ValType &val);   // умножить на скаляр

  // векторные операции
  TVector  operator+(const TVector &v);     // сложение
  TVector  operator-(const TVector &v);     // вычитание
  ValType  operator*(const TVector &v);     // скалярное произведение

  // ввод-вывод
  friend istream& operator>>(istream &in, TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if (s >= 0)
	{
		Size = s;
		StartIndex = si;
		pVector = new <ValType>[Size];
		for (int i = 0; i < Size; i++)
			pVector[i] = 0;
	}
	else throw s "negative size";
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	int i = 0;
	Size = v.Size;
	StartIndex = v.StartIndex;
	for (i; i < Size; i++)
		pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
	pVector = NULL;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos >= 0)
	{
		return pVector[pos - StartIndex];
	}
	else throw pos;
	} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	flag = 0;
	if (Size == b.Size)
	{
		for (int i = 0; i < size; i++)
		{
			if (pVector[i] == v.pVector[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
			return flag;
	} 
	else return 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	flag = 1;
	if (Size == b.Size)
	{
		for (int i = 0; i < size; i++)
		{
			if (pVector[i] == v.pVector[i])
				flag = 0;
			else
			{
				flag = 1;
				break;
			}
		}
		return flag;
	}
	else return 1;
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	delete[] pVector;
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	for (int i = 0; i < Size; i++)
		pVector[i] = pVector[i] * val;
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size == v.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			pVector[i] += v.pVector[i];
		}
		return *this;
	}
	else throw "different length";
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size == v.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			pVector[i] -= v.pVector[i];
		}
		return *this;
	}
	else throw "different length";
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	int TmpScal = 0
	if (Size == v.Size)
	{
		for (int i = 0; i < Size; i++)
			TmpScal = TmpScal + pVector[i] * v.pVector[i];
	}
	else throw "different length";
} /*-------------------------------------------------------------------------*/


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
private:
	TVector<ValType> *pMatrix;

public:
  TMatrix(int s = 10);                           
  TMatrix(const TMatrix &mt);                    // копирование
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
  bool operator==(const TMatrix &mt) const;      // сравнение
  bool operator!=(const TMatrix &mt) const;      // сравнение
  TMatrix& operator= (const TMatrix &mt);        // присваивание
  TMatrix  operator+ (const TMatrix &mt);        // сложение
  TMatrix  operator- (const TMatrix &mt);        // вычитание

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
	Size = s;
	pMatrix = new TVector<ValType>[Size];
	for (int i = 0; i < Size; i++)
	{
		TVector tmp(Size - i, i);
		pMatrix[i] = tmp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	int flag = 0;
	if (Size == mt.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (pMatrix[i] == mt.pMatrix)
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return true;
		else return false;
	}
	else
	{
		return false;
	}
	
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	int flag = 0;
	if (Size == mt.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (pMatrix[i] == mt.pMatrix)
				flag = 0;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			return true;
		else return false;
	}
	else
	{
		return true;
	}

} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (Size == mt.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			pMatrix[i] = mt.pMatrix[i];
		}
		return *this;
	}
	else throw "different size";
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	if (Size == mt.Size)
	{
		for (int i = 0; i < Size; i++)
			pMatrix[i] += mt.pMatrix[i]
			return *this;
	}
	else throw "different size";
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	if (Size == mt.Size)
	{
		for (int i = 0; i < Size; i++)
			pMatrix[i] -= mt.pMatrix[i]
			return *this;
	}
	else throw "different size";
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
