//=============================================================================
/*! _dgsmatrix+dgematrix operator */
inline _dgematrix operator+(const _dgsmatrix& matA, const dgematrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.m!=matB.m || matA.n!=matB.n){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat(matB);
  
  const std::vector<dcomponent>::const_iterator matA_data_end =matA.data.end();
  for(std::vector<dcomponent>::const_iterator it=matA.data.begin(); it!=matA_data_end; it++){
    newmat(it->i,it->j) += it->v;
  }
  
  matA.destroy();
  return _(newmat);
}

//=============================================================================
/*! _dgsmatrix-dgematrix operator */
inline _dgematrix operator-(const _dgsmatrix& matA, const dgematrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.m!=matB.m || matA.n!=matB.n){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a subtraction." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") - (" << matB.n << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat(-matB);
  
  const std::vector<dcomponent>::const_iterator matA_data_end =matA.data.end();
  for(std::vector<dcomponent>::const_iterator it=matA.data.begin(); it!=matA_data_end; it++){
    newmat(it->i,it->j) += it->v;
  }
  
  matA.destroy();
  return _(newmat);
}

//=============================================================================
/*! _dgsmatrix*dgematrix operator */
inline _dgematrix operator*(const _dgsmatrix& matA, const dgematrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") * (" << matB.n << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat(matA.m, matB.n);
  newmat.zero();
  
  const std::vector<dcomponent>::const_iterator matA_data_end =matA.data.end();
  for(std::vector<dcomponent>::const_iterator it=matA.data.begin(); it!=matA_data_end; it++){
    for(CPPL_INT j=0; j<matB.n; j++){
      newmat(it->i,j) += it->v*matB(it->j,j);
    }
  }
  
  matA.destroy();
  return _(newmat);
}
