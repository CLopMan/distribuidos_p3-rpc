struct params {
    int key;
    string value1<256>;
    int N_value2;
    double value2[32];
};

program CLAVES{
    version CLAVESVER {
        int init() = 1;
        int set_value(struct params param) = 2;
        int get_value(struct params param) = 3;
        int modify_value(struct params param) = 4;
        int delete_key(struct params param) = 5;
        int exist(struct params param) = 6;
    } = 1;
} = 99;