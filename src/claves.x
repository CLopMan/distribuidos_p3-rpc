struct params {
    int key;
    string value1<256>;
    int N_value2;
    double value2[32];
};

program CLAVES{
    version CLAVESVER {
        int init_rpc() = 1;
        int set_value_rpc(struct params param) = 2;
        int get_value_rpc(struct params param) = 3;
        int modify_value_rpc(struct params param) = 4;
        int delete_key_rpc(struct params param) = 5;
        int exist_rpc(struct params param) = 6;
    } = 1;
} = 99;