/*
 * esmini - Environment Simulator Minimalistic
 * https://github.com/esmini/esmini
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) partners of Simulation Scenarios
 * https://sites.google.com/view/simulationscenarios
 */

// expression implementation is based on https://github.com/zserge/expr

#include "expr.h"

// Custom function that returns the floor of its argument
static double round_(struct expr_func* f, vec_expr_t* args, void* c) {
    double a = expr_eval(&vec_nth(args, 0));
    return round(a);
}

// Custom function that returns the floor of its argument
static double floor_(struct expr_func* f, vec_expr_t* args, void* c) {
    double a = expr_eval(&vec_nth(args, 0));
    return floor(a);
}

// Custom function that returns the floor of its argument
static double ceil_(struct expr_func* f, vec_expr_t* args, void* c) {
    double a = expr_eval(&vec_nth(args, 0));
    return ceil(a);
}

// Custom function that returns the floor of its argument
static double sqrt_(struct expr_func* f, vec_expr_t* args, void* c) {
    double a = expr_eval(&vec_nth(args, 0));
    return sqrt(a);
}

// Custom function that returns first argument raised to the power of the second argument
static double pow_(struct expr_func* f, vec_expr_t* args, void* c) {
    double a = expr_eval(&vec_nth(args, 0));
    double b = expr_eval(&vec_nth(args, 1));
    return pow(a, b);
}

static struct expr_func user_funcs[] = {
    {"round", round_, NULL, 0},
    {"floor", floor_, NULL, 0},
    {"ceil", ceil_, NULL, 0},
    {"sqrt", sqrt_, NULL, 0},
    {"pow", pow_, NULL, 0},
    {NULL, NULL, NULL, 0},
};

double eval_expr(const char* str)
{
    struct expr_var_list vars = { 0 };
    struct expr* e = expr_create(str, strlen(str), &vars, user_funcs);
    if (e == 0)
    {
        return NAN;
    }

    double retval = expr_eval(e);

    expr_destroy(e, 0);

    return retval;
}

#ifdef __cplusplus
} /* extern "C" */
#endif
