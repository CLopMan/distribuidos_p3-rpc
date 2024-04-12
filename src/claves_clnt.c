/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "claves.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
init_1(int *clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, init, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
set_value_1(struct params param, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, set_value,
		(xdrproc_t) xdr_params, (caddr_t) &param,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
get_value_1(struct params param, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, get_value,
		(xdrproc_t) xdr_params, (caddr_t) &param,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
modify_value_1(struct params param, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, modify_value,
		(xdrproc_t) xdr_params, (caddr_t) &param,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
delete_key_1(struct params param, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, delete_key,
		(xdrproc_t) xdr_params, (caddr_t) &param,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
exist_1(struct params param, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, exist,
		(xdrproc_t) xdr_params, (caddr_t) &param,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}
