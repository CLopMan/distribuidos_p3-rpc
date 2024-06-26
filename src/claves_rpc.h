/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CLAVES_RPC_H_RPCGEN
#define _CLAVES_RPC_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	u_int vector_value2_len;
	double *vector_value2_val;
} vector_value2;

struct get_exit_args {
	char value1[256];
	int N_value2;
	double value2[32];
	int result;
};
typedef struct get_exit_args get_exit_args;

struct rpc_set_value_1_argument {
	int key;
	char *value1;
	int N_value2;
	vector_value2 value2;
};
typedef struct rpc_set_value_1_argument rpc_set_value_1_argument;

struct rpc_modify_value_1_argument {
	int key;
	char *value1;
	int N_value2;
	vector_value2 value2;
};
typedef struct rpc_modify_value_1_argument rpc_modify_value_1_argument;

#define CLAVES 99
#define CLAVESVER 1

#if defined(__STDC__) || defined(__cplusplus)
#define rpc_init 0
extern  enum clnt_stat rpc_init_1(int *, CLIENT *);
extern  bool_t rpc_init_1_svc(int *, struct svc_req *);
#define rpc_set_value 1
extern  enum clnt_stat rpc_set_value_1(int , char *, int , vector_value2 , int *, CLIENT *);
extern  bool_t rpc_set_value_1_svc(int , char *, int , vector_value2 , int *, struct svc_req *);
#define rpc_get_value 2
extern  enum clnt_stat rpc_get_value_1(int , get_exit_args *, CLIENT *);
extern  bool_t rpc_get_value_1_svc(int , get_exit_args *, struct svc_req *);
#define rpc_modify_value 3
extern  enum clnt_stat rpc_modify_value_1(int , char *, int , vector_value2 , int *, CLIENT *);
extern  bool_t rpc_modify_value_1_svc(int , char *, int , vector_value2 , int *, struct svc_req *);
#define rpc_delete_key 4
extern  enum clnt_stat rpc_delete_key_1(int , int *, CLIENT *);
extern  bool_t rpc_delete_key_1_svc(int , int *, struct svc_req *);
#define rpc_exist 5
extern  enum clnt_stat rpc_exist_1(int , int *, CLIENT *);
extern  bool_t rpc_exist_1_svc(int , int *, struct svc_req *);
extern int claves_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define rpc_init 0
extern  enum clnt_stat rpc_init_1();
extern  bool_t rpc_init_1_svc();
#define rpc_set_value 1
extern  enum clnt_stat rpc_set_value_1();
extern  bool_t rpc_set_value_1_svc();
#define rpc_get_value 2
extern  enum clnt_stat rpc_get_value_1();
extern  bool_t rpc_get_value_1_svc();
#define rpc_modify_value 3
extern  enum clnt_stat rpc_modify_value_1();
extern  bool_t rpc_modify_value_1_svc();
#define rpc_delete_key 4
extern  enum clnt_stat rpc_delete_key_1();
extern  bool_t rpc_delete_key_1_svc();
#define rpc_exist 5
extern  enum clnt_stat rpc_exist_1();
extern  bool_t rpc_exist_1_svc();
extern int claves_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_vector_value2 (XDR *, vector_value2*);
extern  bool_t xdr_get_exit_args (XDR *, get_exit_args*);
extern  bool_t xdr_rpc_set_value_1_argument (XDR *, rpc_set_value_1_argument*);
extern  bool_t xdr_rpc_modify_value_1_argument (XDR *, rpc_modify_value_1_argument*);

#else /* K&R C */
extern bool_t xdr_vector_value2 ();
extern bool_t xdr_get_exit_args ();
extern bool_t xdr_rpc_set_value_1_argument ();
extern bool_t xdr_rpc_modify_value_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CLAVES_RPC_H_RPCGEN */
