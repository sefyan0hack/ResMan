#pragma once

enum R_type {
    IMG,
    AUDIO,
};

struct Resource {
    int id;
    R_type type;
    const char* path;
    const unsigned char* data;
    const unsigned int size;
};


inline static Resource resources[0];

constexpr unsigned int resources_count = 0;
