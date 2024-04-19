
#include "claves_rpc.h"
#include <stdio.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "claves.h"

char* get_ip() {
    char *ip = getenv("IP_TUPLAS");
    if (ip == NULL) {
        perror("NOT setted ip");
        return NULL;
    }
    return ip;
}


int init() {
    char *ip = get_ip();
    if (NULL == ip) return -1;
    printf("ip: %s\n", ip);
    CLIENT *clnt;
    clnt = clnt_create(ip, CLAVES, CLAVESVER, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (ip);
		return -1;
    }
    int result;
    enum clnt_stat retval;
    retval = rpc_init_1(&result, clnt);
    if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}

    return result;
}

int set_value(int key, char* value1, int N_value2, double* V_value2) {
    char *ip = get_ip();
    if (NULL == ip) return -1;
    CLIENT *clnt;
    clnt = clnt_create(ip, CLAVES, CLAVESVER, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (ip);
		return -1;
    }
    int result;
    vector_value2 vec;
    vec.vector_value2_len = (u_int)N_value2;
    vec.vector_value2_val = V_value2;
    enum clnt_stat retval;
    retval = rpc_set_value_1(key, value1, N_value2, vec, &result, clnt);
    if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}

    return result;

}

int get_value(int key, char* value1, int* N_value2, double* V_value2) {
    char *ip = get_ip();
    if (NULL == ip) return -1;
    CLIENT *clnt;
    clnt = clnt_create(ip, CLAVES, CLAVESVER, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (ip);
		return -1;
    }
    int result;
    get_exit_args args;
    
    enum clnt_stat retval = rpc_get_value_1(key, &args, clnt);
    if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
    *N_value2 = args.N_value2;
    strcpy(value1, args.value1);
    memcpy(V_value2, args.value2, *(N_value2 ) * sizeof(double));

    return result;

}

int modify_value(int key, char* value1, int N_value2, double* V_value2) {
    char *ip = get_ip();
    if (NULL == ip) return -1;
    CLIENT *clnt;
    clnt = clnt_create(ip, CLAVES, CLAVESVER, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (ip);
		return -1;
    }
    int result;
    vector_value2 vec;
    vec.vector_value2_val = V_value2;
    vec.vector_value2_len = N_value2;
    enum clnt_stat retval = rpc_modify_value_1(key, value1, N_value2, vec, &result, clnt);
    if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}

    return result;
}

int delete_key(int key) {
    char *ip = get_ip();
    if (NULL == ip) return -1;
    CLIENT *clnt;
    clnt = clnt_create(ip, CLAVES, CLAVESVER, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (ip);
		return -1;
    }
    int result;
    enum clnt_stat retval = rpc_delete_key_1(key, &result, clnt);
    if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}

    return result;
}

int exist(int key) {
    printf("call exist\n");
    char *ip = get_ip();
    if (NULL == ip) {printf("hola\n"); return -1;}
    CLIENT *clnt;
    clnt = clnt_create(ip, CLAVES, CLAVESVER, "tcp");
    if (clnt == NULL) {
        printf("clng == NULL\n");
        clnt_pcreateerror (ip);
		return -1;
    }
    int result = 1;
    printf("llamada\n");
    enum clnt_stat retval = rpc_exist_1(key, &result, clnt);
    if (retval != RPC_SUCCESS) {
        printf("error cliente\n");
		clnt_perror (clnt, "call failed");
	}

    printf("fin\n");
    return result;

}