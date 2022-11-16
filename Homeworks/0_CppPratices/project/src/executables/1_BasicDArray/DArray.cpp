// Copyright (c) Watson 2022
// implementation of class DArray
#include "DArray.h"

#include <cassert>
#include <iostream>

// default constructor
DArray::DArray() { Init(); }

// set an array with default values
DArray::DArray(int nSize, double dValue)
    : m_nSize(nSize), m_pData(new double[nSize]) {
  for (size_t i = 0; i < m_nSize; i++) {
    m_pData[i] = dValue;
  }
}

DArray::DArray(const DArray& arr)
    : m_nSize(arr.m_nSize), m_pData(new double[arr.m_nSize]) {
  for (size_t i = 0; i < m_nSize; i++) {
    m_pData[i] = arr.m_pData[i];
  }
}

// deconstructor
DArray::~DArray() { Free(); }

// display the elements of the array
void DArray::Print() const {
  std::cout << "Size = " << m_nSize << std::endl;
  for (size_t i = 0; i < m_nSize; i++) {
    std::cout << " " << GetAt(i);
  }
  std::cout << std::endl;
}

// initilize the array
void DArray::Init() {
  m_pData = nullptr;
  m_nSize = 0;
}

// free the array
void DArray::Free() {
  delete[] m_pData;
  m_pData = nullptr;
  m_nSize = 0;
}

// get the size of the array
int DArray::GetSize() const {
  return m_nSize;  // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize) {
  assert(nSize >= 0);
  if (nSize == m_nSize) {
    return;
  }

  double* pData = new double[nSize];
  int copyCount = nSize > m_nSize ? m_nSize : nSize;
  for (size_t i = 0; i < copyCount; i++) {
    pData[i] = m_pData[i];
  }
  for (size_t i = copyCount; i < nSize; i++) {
    pData[i] = 0;
  }
  m_nSize = nSize;
  delete[] m_pData;
  m_pData = pData;
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
  assert(nIndex >= 0 && nIndex < m_nSize);
  return m_pData[nIndex];
}

// set the value of an element
void DArray::SetAt(int nIndex, double dValue) {
  assert(nIndex >= 0 && nIndex < m_nSize);
  m_pData[nIndex] = dValue;
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
  assert(nIndex >= 0 && nIndex < m_nSize);
  return m_pData[nIndex];
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
  SetSize(m_nSize + 1);
  m_pData[m_nSize] = dValue;
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
  assert(nIndex >= 0 && nIndex < m_nSize);
  
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
  // TODO
}

// overload operator '='
DArray& DArray::operator=(const DArray& arr) {
  // TODO
  return *this;
}
