#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

SEXP _Rcplex(SEXP numcols_p,
	    SEXP numrows_p,
	    SEXP objsen_p,
	    SEXP cvec,
	    SEXP bvec,
	    SEXP Amat,
	    SEXP Qmat,
	    SEXP lb_p,
	    SEXP ub_p,
	    SEXP Rsense,
	    SEXP Rvtype,
	    SEXP isQP_p,
	    SEXP isMIP_p,
	    SEXP num_poplim,
	    SEXP control,
	    SEXP maxcalls);

SEXP _Rcplex_QCP(SEXP numcols_p,
		SEXP numrows_p,
		SEXP objsen_p,
		SEXP cvec,
		SEXP bvec,
		SEXP Amat,
		SEXP Qmat,
		SEXP lb_p,
		SEXP ub_p,
		SEXP Rsense,
		SEXP Rvtype,
		SEXP isQP_p,
		SEXP isMIP_p,
		SEXP num_poplim,
		SEXP control,
		SEXP maxcalls,
		SEXP isQCP_p,
		SEXP QC,
		SEXP nQC);

void Rcplex_free(void);

static const R_CallMethodDef CallEntries[] = {
    {"_Rcplex", (DL_FUNC) &_Rcplex, 16},
    {"_Rcplex_QCP", (DL_FUNC) &_Rcplex_QCP, 19},
    {NULL, NULL, 0}
};

static const R_CMethodDef CEntries[] = {
    {"Rcplex_free", (DL_FUNC) &_Rcplex, 0},
    {NULL, NULL, 0}
};

void R_init_Rcplex(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
