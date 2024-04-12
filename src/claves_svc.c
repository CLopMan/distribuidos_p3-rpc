/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "claves.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

int
_init_rpc_1 (void  *argp, void *result, struct svc_req *rqstp)
{
	return (init_rpc_1_svc(result, rqstp));
}

int
_set_value_rpc_1 (struct params  *argp, void *result, struct svc_req *rqstp)
{
	return (set_value_rpc_1_svc(*argp, result, rqstp));
}

int
_get_value_rpc_1 (struct params  *argp, void *result, struct svc_req *rqstp)
{
	return (get_value_rpc_1_svc(*argp, result, rqstp));
}

int
_modify_value_rpc_1 (struct params  *argp, void *result, struct svc_req *rqstp)
{
	return (modify_value_rpc_1_svc(*argp, result, rqstp));
}

int
_delete_key_rpc_1 (struct params  *argp, void *result, struct svc_req *rqstp)
{
	return (delete_key_rpc_1_svc(*argp, result, rqstp));
}

int
_exist_rpc_1 (struct params  *argp, void *result, struct svc_req *rqstp)
{
	return (exist_rpc_1_svc(*argp, result, rqstp));
}

static void
claves_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		struct params set_value_rpc_1_arg;
		struct params get_value_rpc_1_arg;
		struct params modify_value_rpc_1_arg;
		struct params delete_key_rpc_1_arg;
		struct params exist_rpc_1_arg;
	} argument;
	union {
		int init_rpc_1_res;
		int set_value_rpc_1_res;
		int get_value_rpc_1_res;
		int modify_value_rpc_1_res;
		int delete_key_rpc_1_res;
		int exist_rpc_1_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case init_rpc:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_init_rpc_1;
		break;

	case set_value_rpc:
		_xdr_argument = (xdrproc_t) xdr_params;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_set_value_rpc_1;
		break;

	case get_value_rpc:
		_xdr_argument = (xdrproc_t) xdr_params;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_get_value_rpc_1;
		break;

	case modify_value_rpc:
		_xdr_argument = (xdrproc_t) xdr_params;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_modify_value_rpc_1;
		break;

	case delete_key_rpc:
		_xdr_argument = (xdrproc_t) xdr_params;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_delete_key_rpc_1;
		break;

	case exist_rpc:
		_xdr_argument = (xdrproc_t) xdr_params;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_exist_rpc_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!claves_1_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CLAVES, CLAVESVER);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CLAVES, CLAVESVER, claves_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CLAVES, CLAVESVER, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CLAVES, CLAVESVER, claves_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CLAVES, CLAVESVER, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
