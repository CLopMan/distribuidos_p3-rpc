/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CLAVES_H_RPCGEN
#define _CLAVES_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


struct params {
	int key;
	char *value1;
	int N_value2;
	double value2[32];
};
typedef struct params params;

#define CLAVES 99
#define CLAVESVER 1

#if defined(__STDC__) || defined(__cplusplus)
#define init_rpc 1
extern  enum clnt_stat init_rpc_1(int *, CLIENT *);
extern  bool_t init_rpc_1_svc(int *, struct svc_req *);
#define set_value_rpc 2
extern  enum clnt_stat set_value_rpc_1(struct params , int *, CLIENT *);
extern  bool_t set_value_rpc_1_svc(struct params , int *, struct svc_req *);
#define get_value_rpc 3
extern  enum clnt_stat get_value_rpc_1(struct params , int *, CLIENT *);
extern  bool_t get_value_rpc_1_svc(struct params , int *, struct svc_req *);
#define modify_value_rpc 4
extern  enum clnt_stat modify_value_rpc_1(struct params , int *, CLIENT *);
extern  bool_t modify_value_rpc_1_svc(struct params , int *, struct svc_req *);
#define delete_key_rpc 5
extern  enum clnt_stat delete_key_rpc_1(struct params , int *, CLIENT *);
extern  bool_t delete_key_rpc_1_svc(struct params , int *, struct svc_req *);
#define exist_rpc 6
extern  enum clnt_stat exist_rpc_1(struct params , int *, CLIENT *);
extern  bool_t exist_rpc_1_svc(struct params , int *, struct svc_req *);
extern int claves_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define init_rpc 1
extern  enum clnt_stat init_rpc_1();
extern  bool_t init_rpc_1_svc();
#define set_value_rpc 2
extern  enum clnt_stat set_value_rpc_1();
extern  bool_t set_value_rpc_1_svc();
#define get_value_rpc 3
extern  enum clnt_stat get_value_rpc_1();
extern  bool_t get_value_rpc_1_svc();
#define modify_value_rpc 4
extern  enum clnt_stat modify_value_rpc_1();
extern  bool_t modify_value_rpc_1_svc();
#define delete_key_rpc 5
extern  enum clnt_stat delete_key_rpc_1();
extern  bool_t delete_key_rpc_1_svc();
#define exist_rpc 6
extern  enum clnt_stat exist_rpc_1();
extern  bool_t exist_rpc_1_svc();
extern int claves_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_params (XDR *, params*);

#else /* K&R C */
extern bool_t xdr_params ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CLAVES_H_RPCGEN */
