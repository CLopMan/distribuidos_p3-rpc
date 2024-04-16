/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "claves_rpc.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
rpc_init_1(int *clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, rpc_init, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
rpc_set_value_1(int key, char *value1, int N_value2, vector_value2 value2, int *clnt_res,  CLIENT *clnt)
{
	rpc_set_value_1_argument arg;
	arg.key = key;
	arg.value1 = value1;
	arg.N_value2 = N_value2;
	arg.value2 = value2;
	return (clnt_call (clnt, rpc_set_value, (xdrproc_t) xdr_rpc_set_value_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
rpc_get_value_1(int key, get_exit_args *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, rpc_get_value,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_get_exit_args, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
rpc_modify_value_1(int key, char *value1, int N_value2, vector_value2 value2, int *clnt_res,  CLIENT *clnt)
{
	rpc_modify_value_1_argument arg;
	arg.key = key;
	arg.value1 = value1;
	arg.N_value2 = N_value2;
	arg.value2 = value2;
	return (clnt_call (clnt, rpc_modify_value, (xdrproc_t) xdr_rpc_modify_value_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
rpc_delete_key_1(int key, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, rpc_delete_key,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
rpc_exist_1(int key, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, rpc_exist,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}
