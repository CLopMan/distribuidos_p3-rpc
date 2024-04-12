/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "claves.h"


char* obtener_ip() {
	char* ip;
	ip = getenv("IP_TUPLAS");
	if (ip == NULL) {
		perror("NOT setted ip");
	}
	else {
		return ip;
	}
}

CLIENT* create_clnt(char* host) {
	CLIENT* clnt = clnt_create(host, CLAVES, CLAVESVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror(host);
		exit(1);
	}
	return clnt;
}

void init() {
	char* ip = obtener_ip();

	CLIENT* clnt;

	enum clnt_stat retval_1;
	int result_1;

	create_clnt(ip);
	retval_1 = init_1(&result_1, clnt);
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
	}
	clnt_destroy(clnt);
}

void set_value_rpc() {
	char* ip = obtener_ip();

	CLIENT* clnt;

	enum clnt_stat retval_2;
	int result_2;

	create_clnt(ip);
	retval_2 = set_value_1(set_value_1_param, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
	}
	clnt_destroy(clnt);
}

void get_value_rpc() {
	char* ip = obtener_ip();

	CLIENT* clnt;

	struct params set_value_1_param;
	enum clnt_stat retval_3;
	int result_3;

	create_clnt(ip);
	retval_3 = get_value_1(get_value_1_param, &result_3, clnt);
	if (retval_3 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
	}
	clnt_destroy(clnt);
}

void modify_value_rpc() {
	char* ip = obtener_ip();

	CLIENT* clnt;

	struct params get_value_1_param;
	enum clnt_stat retval_4;
	int result_4;

	create_clnt(ip);
	retval_4 = modify_value_1(modify_value_1_param, &result_4, clnt);
	if (retval_4 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
	}
	clnt_destroy(clnt);
}

void
claves_1() {

	char* ip = obtener_ip();

	CLIENT* clnt;


	struct params modify_value_1_param;
	enum clnt_stat retval_5;
	int result_5;

	struct params delete_key_1_param;
	enum clnt_stat retval_6;
	int result_6;

	struct params exist_1_param;

	create_clnt(ip);





	retval_5 = delete_key_1(delete_key_1_param, &result_5, clnt);
	if (retval_5 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
	}
	retval_6 = exist_1(exist_1_param, &result_6, clnt);
	if (retval_6 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
	}

	clnt_destroy(clnt);

}


int
main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	claves_1();

	exit(0);
}
