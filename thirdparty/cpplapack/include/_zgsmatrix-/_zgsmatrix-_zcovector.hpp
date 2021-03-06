//=============================================================================
/*! _zgsmatrix*_zcovector operator */
inline _zcovector operator*(const _zgsmatrix& mat, const _zcovector& vec)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(mat.n!=vec.l){
    ERROR_REPORT;
    std::cerr << "These matrix and vector can not make a product." << std::endl
              << "Your input was (" << mat.m << "x" << mat.n << ") * (" << vec.l << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zcovector newvec(mat.m);
  newvec.zero();
  
  const std::vector<zcomponent>::const_iterator mat_data_end =mat.data.end();
  for(std::vector<zcomponent>::const_iterator it=mat.data.begin(); it!=mat_data_end; it++){
    newvec(it->i) += it->v*vec(it->j);
  }
  
  mat.destroy();
  vec.destroy();
  return _(newvec);
}
