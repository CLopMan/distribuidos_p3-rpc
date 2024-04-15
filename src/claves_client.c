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
#include "claves_rpc.h"

char* obtener_ip() {
	char* ip;
	ip = getenv("IP_TUPLAS");
	printf("%s\n", ip);
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

int init() {
	char* ip = obtener_ip();
	CLIENT* clnt;
	enum clnt_stat retval_1;
	int result_1;
	printf("antes del create\n");
	clnt = create_clnt(ip);
	printf("despues del create\n");
	retval_1 = init_rpc_1(&result_1, clnt);
	printf("después de mandar init\n");
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
		return -1;
	}
	clnt_destroy(clnt);
	return result_1;

}

int set_value(int key, char* value1, int N_value2, double* V_value2) {
	char* ip = obtener_ip();
	printf("%s\n", ip);
	CLIENT* clnt;
	enum clnt_stat retval_2;
	int result_2;
	struct params set_value_rpc_1_param;

	// Rellenar struct con argumentos
	set_value_rpc_1_param.key = key;
	printf("hemos superado key\n");
	set_value_rpc_1_param.value1 = value1;
	//strcpy(set_value_rpc_1_param.value1, value1);
	printf("hemos superado value1\n");
	set_value_rpc_1_param.N_value2 = N_value2;
	printf("hemos superado Nvalue2\n");
	for (int i = 0; i < N_value2; i++) {
		set_value_rpc_1_param.value2[i] = V_value2[i];
	}
	printf("hemos superado el for\n");

	clnt = create_clnt(ip);
	retval_2 = set_value_rpc_1(set_value_rpc_1_param, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
		return -1;
	}
	clnt_destroy(clnt);

	return result_2;
}
int get_value(int key, char* value1, int* N_value2, double* V_value2) {
	char* ip = obtener_ip();
	CLIENT* clnt;
	enum clnt_stat retval_3;
	int result_3;
	struct params get_value_rpc_1_param;

	// Rellenar struct con argumentos
	get_value_rpc_1_param.key = key;
	get_value_rpc_1_param.value1 = value1;
	get_value_rpc_1_param.N_value2 = *N_value2;
	for (int i = 0; i < *N_value2; i++) {
		get_value_rpc_1_param.value2[i] = V_value2[i];
	}

	clnt = create_clnt(ip);
	retval_3 = get_value_rpc_1(get_value_rpc_1_param, &result_3, clnt);
	if (retval_3 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
		return -1;
	}
	clnt_destroy(clnt);
	return result_3;
}
int modify_value(int key, char* value1, int N_value2, double* V_value2) {


	char* ip = obtener_ip();
	CLIENT* clnt;
	enum clnt_stat retval_4;
	int result_4;
	struct params modify_value_rpc_1_param;

	// Rellenar struct con argumentos
	modify_value_rpc_1_param.key = key;
	modify_value_rpc_1_param.value1 = value1;
	modify_value_rpc_1_param.N_value2 = N_value2;
	for (int i = 0; i < N_value2; i++) {
		modify_value_rpc_1_param.value2[i] = V_value2[i];
	}

	clnt = create_clnt(ip);
	retval_4 = modify_value_rpc_1(modify_value_rpc_1_param, &result_4, clnt);
	if (retval_4 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
		return -1;
	}
	clnt_destroy(clnt);
	return result_4;
}
int delete_key(int key) {
	printf("entro\n");
	char* ip = obtener_ip();
	printf("ip\n");
	CLIENT* clnt;
	enum clnt_stat retval_5;
	int result_5;
	printf("enum\n");
	struct params delete_key_rpc_1_param;

	// Rellenar struct con argumentos
	printf("ky\n");
	delete_key_rpc_1_param.key = key;
	printf("antes de create\n");
	clnt = create_clnt(ip);
	printf("despues del create\n");
	retval_5 = delete_key_rpc_1(delete_key_rpc_1_param, &result_5, clnt);
	printf("Después de llamar a la función de comunicación\n");
	if (retval_5 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
		return -1;
	}
	clnt_destroy(clnt);
	return result_5;
}
int exist(int key) {
	char* ip = obtener_ip();
	CLIENT* clnt;
	enum clnt_stat retval_6;
	int result_6;
	struct params exist_rpc_1_param;

	// Rellenar struct con argumentos
	exist_rpc_1_param.key = key;

	clnt = create_clnt(ip);
	retval_6 = exist_rpc_1(exist_rpc_1_param, &result_6, clnt);
	if (retval_6 != RPC_SUCCESS) {
		clnt_perror(clnt, "call failed");
		return -1;
	}
	clnt_destroy(clnt);
	return result_6;

}

int main(int argc, char* argv[]) {
	double tres[] = { 3.3,33.3,333.3 };
	int N;
	char cd[] = "cd";
	char texto[256];
	int rn;
	double rvec[32];
	char hello[] = "Hello world";
	double vec5[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };


	//init();
	//set_value(3, cd, 3, tres);
	//modify_value(5, cd, 3, tres);
	//get_value(3, texto, &rn, rvec);
	delete_key(3);

	/*
	printf("INIT:\n");
	init();
	printf("pitopausia\n");
	sleep(1);

	int retorno = -1;
	retorno = set_value(3, cd, 3, tres);
	printf("first set: %d\n", retorno);
	sleep(1);
	retorno = set_value(9, cd, 3, tres);
	printf("snd set: %d\n", retorno);
	sleep(1);


	//get_value(3, texto, &rn, rvec);
	printf("get_value:\n\ttexto: %s\n\tN: %d\n\tdoubles:", texto, rn);
	for (int i = 0; i < rn; ++i) {
		printf("\n\t\t[%d]: %lf", i, rvec[i]);
	}
	printf("\n");

	sleep(1);

	modify_value(3, hello, 5, vec5);
	//get_value(3, texto, &rn, rvec);
	printf("first_modify:\n\ttexto: %s\n\tN: %d\n\tdoubles:", texto, rn);
	for (int i = 0; i < rn; ++i) {
		printf("\n\t\t[%d]: %lf", i, rvec[i]);
	}
	printf("\n");
	retorno = modify_value(5, cd, 3, tres);
	printf("snd modify: %d\n", retorno);

	//delete_key(3);
	//printf("exits: %i\n", exist(9));
	//printf("exits: %i\n", exist(3)); */
	return 0;
}