#ifndef VECTORS_H
#define VECTORS_H

#include <stdbool.h>

// Macro to define a vector struct with 2, 3, or 4 components
#define DEFINE_VECTOR(type, name)     \
    typedef struct {                  \
        type x, y;                    \
    } name##2;                        \
                                      \
    typedef struct {                  \
        type x, y, z;                 \
    } name##3;                        \
                                      \
    typedef struct {                  \
        type w, x, y, z;              \
    } name##4;

// Define vector types
DEFINE_VECTOR(bool, bvec)        // Boolean vectors: bvec2, bvec3, bvec4
DEFINE_VECTOR(int, ivec)         // Integer vectors: ivec2, ivec3, ivec4
DEFINE_VECTOR(unsigned int, uvec) // Unsigned integer vectors: uvec2, uvec3, uvec4
DEFINE_VECTOR(float, vec)        // Float vectors: vec2, vec3, vec4
DEFINE_VECTOR(double, dvec)      // Double vectors: dvec2, dvec3, dvec4

// Utility Functions
// Macro to create addition and scaling functions for each type of vector
#define DEFINE_VECTOR_FUNCTIONS(type, name)                        \
    static inline name##2 name##2_add(name##2 a, name##2 b) {      \
        return (name##2){a.x + b.x, a.y + b.y};                    \
    }                                                              \
                                                                   \
    static inline name##3 name##3_add(name##3 a, name##3 b) {      \
        return (name##3){a.x + b.x, a.y + b.y, a.z + b.z};         \
    }                                                              \
                                                                   \
    static inline name##4 name##4_add(name##4 a, name##4 b) {      \
        return (name##4){a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z}; \
    }                                                              \
                                                                   \
    static inline name##2 name##2_scale(name##2 v, type scalar) {  \
        return (name##2){v.x * scalar, v.y * scalar};              \
    }                                                              \
                                                                   \
    static inline name##3 name##3_scale(name##3 v, type scalar) {  \
        return (name##3){v.x * scalar, v.y * scalar, v.z * scalar};\
    }                                                              \
                                                                   \
    static inline name##4 name##4_scale(name##4 v, type scalar) {  \
        return (name##4){v.w * scalar, v.x * scalar, v.y * scalar, v.z * scalar}; \
    }

// Define utility functions for each type of vector
DEFINE_VECTOR_FUNCTIONS(bool, bvec)
DEFINE_VECTOR_FUNCTIONS(int, ivec)
DEFINE_VECTOR_FUNCTIONS(unsigned int, uvec)
DEFINE_VECTOR_FUNCTIONS(float, vec)
DEFINE_VECTOR_FUNCTIONS(double, dvec)

#endif // VECTORS_H
