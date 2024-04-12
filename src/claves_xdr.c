/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "claves.h"

bool_t
xdr_V_value2 (XDR *xdrs, V_value2 objp)
{
	register int32_t *buf;

	 if (!xdr_vector (xdrs, (char *)objp, 32,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_set_value_1_argument (XDR *xdrs, set_value_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->value1, 256))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N_value2))
		 return FALSE;
	 if (!xdr_V_value2 (xdrs, objp->value2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_get_value_1_argument (XDR *xdrs, get_value_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->value1, 256))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N_value2))
		 return FALSE;
	 if (!xdr_V_value2 (xdrs, objp->value2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_modify_value_1_argument (XDR *xdrs, modify_value_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->value1, 256))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N_value2))
		 return FALSE;
	 if (!xdr_V_value2 (xdrs, objp->value2))
		 return FALSE;
	return TRUE;
}
