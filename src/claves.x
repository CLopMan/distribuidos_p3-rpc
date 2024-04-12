typedef double V_value2[32];

program CLAVES{
    version CLAVESVER {
        int init(void) = 1;
        int set_value(int key, string value1<256>, int N_value2, V_value2 value2) = 2;
        int get_value(int key, string value1<256>, int N_value2, V_value2 value2) = 3;
        int modify_value(int key, string value1<256>, int N_value2, V_value2 value2) = 4;
        int delete_key(int key) = 5;
        int exist(int key) = 6;
    } = 1;
} = 99;