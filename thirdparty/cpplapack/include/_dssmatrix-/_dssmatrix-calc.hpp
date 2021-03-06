//=============================================================================
/*! return transposed _dssmatrix */
inline _dssmatrix t(const _dssmatrix& mat)
{CPPL_VERBOSE_REPORT;
  return mat;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//=============================================================================
/*! search the index of element having the largest absolute value
  in 0-based numbering system */
inline void idamax(CPPL_INT& i, CPPL_INT& j, const _dssmatrix& mat)
{CPPL_VERBOSE_REPORT;
  std::vector<dcomponent>::const_iterator itx(mat.data.begin());
  double vmax(0);
  
  const std::vector<dcomponent>::const_iterator mat_data_end =mat.data.end();
  for(std::vector<dcomponent>::const_iterator it=mat.data.begin(); it!=mat_data_end; it++){
    if(vmax < it->v){
      vmax=fabs(it->v);
      itx=it;
    }
  }
  
  i=itx->i;
  j=itx->j;
  
  mat.destroy();
}

//=============================================================================
/*! return its largest absolute value */
inline double damax(const _dssmatrix& mat)
{CPPL_VERBOSE_REPORT;
  std::vector<dcomponent>::const_iterator itx(mat.data.begin());
  double vmax(0);
  
  const std::vector<dcomponent>::const_iterator mat_data_end =mat.data.end();
  for(std::vector<dcomponent>::const_iterator it=mat.data.begin(); it!=mat_data_end; it++){
    if(vmax < it->v){
      vmax=fabs(it->v);
      itx=it;
    }
  }
  
  double val(itx->v);
  mat.destroy();
  return val;
}
