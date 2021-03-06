//=============================================================================
/*! _dgsmatrix+_dsymatrix operator */
/*
inline _dgematrix operator+(const _dgsmatrix& matA, const _dsymatrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.m!=matB.n || matA.n!=matB.n){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") + (" << matB.n << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat(matB);
  for(CPPL_INT c=0; c<matA.vol; c++){
    newmat(matA.indx[c],matA.jndx[c]) += matA.array[c];
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}
*/
//=============================================================================
/*! _dgsmatrix-_dsymatrix operator */
/*
inline _dgematrix operator-(const _dgsmatrix& matA, const _dsymatrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.m!=matB.n || matA.n!=matB.n){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a subtraction." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") - (" << matB.n << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG

  //// shallow copy to dgematrix  ////
  dgematrix newmat(-matB);
  
  //// add ////
  for(CPPL_INT c=0; c<matA.vol; c++){
    newmat(matA.indx[c],matA.jndx[c]) += matA.array[c];
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}
*/
//=============================================================================
/*! _dgsmatrix*_dsymatrix operator */
/*
inline _dgematrix operator*(const _dgsmatrix& matA, const _dsymatrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.n){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") * (" << matB.n << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat(matA.m, matB.n);
  newmat.zero();
  
  for(CPPL_INT c=0; c<matA.vol; c++){
    for(CPPL_INT i=0; i<matB.n; i++){
      newmat(matA.indx[c],i) += matA.array[c]*matB(matA.jndx[c],i);
    }
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}
*/
