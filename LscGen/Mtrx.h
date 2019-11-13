// Matrix.h: interface for the CMatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX_H__F99A5613_4E9F_4D4D_87D0_82DC8CE46F19__INCLUDED_)
#define AFX_MATRIX_H__F99A5613_4E9F_4D4D_87D0_82DC8CE46F19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class Container2DRow
{
public:
		  T& operator [] (int j);
	const T& operator [] (int j) const; 
	T **m_ppMatrix;
	int i; //ROW (Y coord)
	int m_nXSize;
};
///Class container

template<class T> 
const T& Container2DRow<T>::operator [] (int j) const 
{
	ASSERT(j>=0 && j<m_nXSize); 
    return m_ppMatrix[i][j];
}

template<class T> 
T& Container2DRow<T>::operator [] (int j) 
{
	ASSERT(j>=0 && j<m_nXSize); 
    return m_ppMatrix[i][j];
}



template <class T>
class CMatrix  
{
public:
	Container2DRow<T> row;

private:
	int m_nXSize;
	int m_nYSize;
	int m_nMemorySize;
	T **m_ppMatrix;

	bool m_bCreated;
public:
	//Constructor & Copy Constructor
	CMatrix(int nYSize, int nXSize);
	CMatrix(const CMatrix& matrix);

	CMatrix& operator= (const CMatrix& matrix);
	CMatrix  operator+ (const T& item);
	CMatrix  operator- (const T& item);
	
	//Indexing //Y(row) X(col) 
	T& operator()(int i, int j);   // i - row
	    Container2DRow<T> operator [] (int i);
const	Container2DRow<T> operator [] (int i) const; 


	T SumAll();
	//Get Size
	int GetXSize();
	int GetYSize();
	T GetMinValue();
	T GetMaxValue();


	virtual ~CMatrix();

};

template<class T>
CMatrix<T>::CMatrix(int nYSize, int nXSize)
{
	m_bCreated = false;
	ASSERT(nXSize>0 && nYSize>0);


	m_nXSize = nXSize;
	m_nYSize = nYSize;
	m_nMemorySize = m_nYSize*m_nXSize*sizeof(T);

	m_ppMatrix    = new T* [m_nYSize];
    m_ppMatrix[0] = new T  [m_nYSize*m_nXSize];

	for (int i=1; i<m_nYSize; i++)
		m_ppMatrix[i] = m_ppMatrix[0]+i*m_nXSize;
		
	memset(m_ppMatrix[0], 0, m_nMemorySize);
	m_bCreated = true;
	row.m_ppMatrix = m_ppMatrix;
	row.m_nXSize   = m_nXSize;
}

template<class T>
CMatrix<T>::CMatrix(const CMatrix& matrix)
{
		m_nXSize = matrix.m_nXSize;
		m_nYSize = matrix.m_nYSize;
		m_nMemorySize = m_nYSize*m_nXSize*sizeof(T);

		m_ppMatrix    = new T* [m_nYSize];
		ASSERT(m_ppMatrix!=NULL);
        
		m_ppMatrix[0] = new T  [m_nYSize*m_nXSize];
		ASSERT(m_ppMatrix[0]!=NULL);

		for (int i=1; i<m_nYSize; i++)
			m_ppMatrix[i] = m_ppMatrix[0]+i*m_nXSize;

		memcpy(m_ppMatrix[0],matrix.m_ppMatrix[0], m_nMemorySize);

		m_bCreated = true;
}


template<class T>
CMatrix<T>& CMatrix<T>::operator= (const CMatrix& matrix)
{
	if (this == &matrix) return *this;

	ASSERT(m_nXSize == matrix.m_nXSize && 
		   m_nYSize == matrix.m_nYSize);
	memcpy(m_ppMatrix[0],matrix.m_ppMatrix[0], m_nMemorySize);

	return *this;
}
template<class T>
T CMatrix<T>::GetMinValue()
{
	T minValue = m_ppMatrix[0][0];
	int i,j;

		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			if(m_ppMatrix[i][j]<minValue)
				minValue = m_ppMatrix[i][j];
		}
		return minValue;
}

template<class T>
T CMatrix<T>::GetMaxValue()
{
		T maxValue = m_ppMatrix[0][0];
		int i,j;

		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			if(m_ppMatrix[i][j]>maxValue)
				maxValue = m_ppMatrix[i][j];
		}
		return maxValue;
}

template<class T>
CMatrix<T> CMatrix<T>::operator+ (const T& item)
{
		int i, j;

		CMatrix<T> mtrx(m_nYSize, m_nXSize);
		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			mtrx.m_ppMatrix[i][j] = m_ppMatrix[i][j]+item ;
		}
		return mtrx;
}

template<class T>
CMatrix<T> CMatrix<T>::operator- (const T& item)
{
		int i, j;

		CMatrix<T> mtrx(m_nYSize, m_nXSize);
		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			mtrx.m_ppMatrix[i][j] = m_ppMatrix[i][j]-item ;
		}
		return mtrx;
}

template<class T>
CMatrix<T>::~CMatrix()
{
	if (m_bCreated)
	{
		delete [] m_ppMatrix[0];
		delete [] m_ppMatrix;
	}
}

template<class T>
int CMatrix<T>::GetXSize()
{
	return m_nXSize;
}

template<class T>
T CMatrix<T>::SumAll()
{
	T sum = 0;
	int i, j;

	for (i=0; i<m_nYSize; i++)
	for (j=0; j<m_nXSize; j++)
	{
		sum += m_ppMatrix[i][j];
	}
	return sum;
}

template<class T>
int CMatrix<T>::GetYSize()
{
	return m_nYSize;
}
template<class T>        //Y(row) X(col)      
T& CMatrix<T>::operator()(int i, int j)
{
	ASSERT(i>=0 && i<m_nYSize &&
		   j>=0 && j<m_nXSize);

	return m_ppMatrix[i][j];
}

//Fancy Indexing
template<class T> 
Container2DRow<T> CMatrix<T>::operator [] (int i)
{
	ASSERT(i>=0 && i<m_nYSize); 
    row.i = i;
    return row;
}

template<class T> 
const Container2DRow<T> CMatrix<T>::operator [] (int i) const
{
	ASSERT(i>=0 && i<m_nYSize); 
    row.i = i;
    return row;
}

#endif // !defined(AFX_MATRIX_H__F99A5613_4E9F_4D4D_87D0_82DC8CE46F19__INCLUDED_)
