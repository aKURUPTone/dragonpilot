#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2155524759348881706) {
   out_2155524759348881706[0] = delta_x[0] + nom_x[0];
   out_2155524759348881706[1] = delta_x[1] + nom_x[1];
   out_2155524759348881706[2] = delta_x[2] + nom_x[2];
   out_2155524759348881706[3] = delta_x[3] + nom_x[3];
   out_2155524759348881706[4] = delta_x[4] + nom_x[4];
   out_2155524759348881706[5] = delta_x[5] + nom_x[5];
   out_2155524759348881706[6] = delta_x[6] + nom_x[6];
   out_2155524759348881706[7] = delta_x[7] + nom_x[7];
   out_2155524759348881706[8] = delta_x[8] + nom_x[8];
   out_2155524759348881706[9] = delta_x[9] + nom_x[9];
   out_2155524759348881706[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3000442515133824169) {
   out_3000442515133824169[0] = -nom_x[0] + true_x[0];
   out_3000442515133824169[1] = -nom_x[1] + true_x[1];
   out_3000442515133824169[2] = -nom_x[2] + true_x[2];
   out_3000442515133824169[3] = -nom_x[3] + true_x[3];
   out_3000442515133824169[4] = -nom_x[4] + true_x[4];
   out_3000442515133824169[5] = -nom_x[5] + true_x[5];
   out_3000442515133824169[6] = -nom_x[6] + true_x[6];
   out_3000442515133824169[7] = -nom_x[7] + true_x[7];
   out_3000442515133824169[8] = -nom_x[8] + true_x[8];
   out_3000442515133824169[9] = -nom_x[9] + true_x[9];
   out_3000442515133824169[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_6886810493919790975) {
   out_6886810493919790975[0] = 1.0;
   out_6886810493919790975[1] = 0;
   out_6886810493919790975[2] = 0;
   out_6886810493919790975[3] = 0;
   out_6886810493919790975[4] = 0;
   out_6886810493919790975[5] = 0;
   out_6886810493919790975[6] = 0;
   out_6886810493919790975[7] = 0;
   out_6886810493919790975[8] = 0;
   out_6886810493919790975[9] = 0;
   out_6886810493919790975[10] = 0;
   out_6886810493919790975[11] = 0;
   out_6886810493919790975[12] = 1.0;
   out_6886810493919790975[13] = 0;
   out_6886810493919790975[14] = 0;
   out_6886810493919790975[15] = 0;
   out_6886810493919790975[16] = 0;
   out_6886810493919790975[17] = 0;
   out_6886810493919790975[18] = 0;
   out_6886810493919790975[19] = 0;
   out_6886810493919790975[20] = 0;
   out_6886810493919790975[21] = 0;
   out_6886810493919790975[22] = 0;
   out_6886810493919790975[23] = 0;
   out_6886810493919790975[24] = 1.0;
   out_6886810493919790975[25] = 0;
   out_6886810493919790975[26] = 0;
   out_6886810493919790975[27] = 0;
   out_6886810493919790975[28] = 0;
   out_6886810493919790975[29] = 0;
   out_6886810493919790975[30] = 0;
   out_6886810493919790975[31] = 0;
   out_6886810493919790975[32] = 0;
   out_6886810493919790975[33] = 0;
   out_6886810493919790975[34] = 0;
   out_6886810493919790975[35] = 0;
   out_6886810493919790975[36] = 1.0;
   out_6886810493919790975[37] = 0;
   out_6886810493919790975[38] = 0;
   out_6886810493919790975[39] = 0;
   out_6886810493919790975[40] = 0;
   out_6886810493919790975[41] = 0;
   out_6886810493919790975[42] = 0;
   out_6886810493919790975[43] = 0;
   out_6886810493919790975[44] = 0;
   out_6886810493919790975[45] = 0;
   out_6886810493919790975[46] = 0;
   out_6886810493919790975[47] = 0;
   out_6886810493919790975[48] = 1.0;
   out_6886810493919790975[49] = 0;
   out_6886810493919790975[50] = 0;
   out_6886810493919790975[51] = 0;
   out_6886810493919790975[52] = 0;
   out_6886810493919790975[53] = 0;
   out_6886810493919790975[54] = 0;
   out_6886810493919790975[55] = 0;
   out_6886810493919790975[56] = 0;
   out_6886810493919790975[57] = 0;
   out_6886810493919790975[58] = 0;
   out_6886810493919790975[59] = 0;
   out_6886810493919790975[60] = 1.0;
   out_6886810493919790975[61] = 0;
   out_6886810493919790975[62] = 0;
   out_6886810493919790975[63] = 0;
   out_6886810493919790975[64] = 0;
   out_6886810493919790975[65] = 0;
   out_6886810493919790975[66] = 0;
   out_6886810493919790975[67] = 0;
   out_6886810493919790975[68] = 0;
   out_6886810493919790975[69] = 0;
   out_6886810493919790975[70] = 0;
   out_6886810493919790975[71] = 0;
   out_6886810493919790975[72] = 1.0;
   out_6886810493919790975[73] = 0;
   out_6886810493919790975[74] = 0;
   out_6886810493919790975[75] = 0;
   out_6886810493919790975[76] = 0;
   out_6886810493919790975[77] = 0;
   out_6886810493919790975[78] = 0;
   out_6886810493919790975[79] = 0;
   out_6886810493919790975[80] = 0;
   out_6886810493919790975[81] = 0;
   out_6886810493919790975[82] = 0;
   out_6886810493919790975[83] = 0;
   out_6886810493919790975[84] = 1.0;
   out_6886810493919790975[85] = 0;
   out_6886810493919790975[86] = 0;
   out_6886810493919790975[87] = 0;
   out_6886810493919790975[88] = 0;
   out_6886810493919790975[89] = 0;
   out_6886810493919790975[90] = 0;
   out_6886810493919790975[91] = 0;
   out_6886810493919790975[92] = 0;
   out_6886810493919790975[93] = 0;
   out_6886810493919790975[94] = 0;
   out_6886810493919790975[95] = 0;
   out_6886810493919790975[96] = 1.0;
   out_6886810493919790975[97] = 0;
   out_6886810493919790975[98] = 0;
   out_6886810493919790975[99] = 0;
   out_6886810493919790975[100] = 0;
   out_6886810493919790975[101] = 0;
   out_6886810493919790975[102] = 0;
   out_6886810493919790975[103] = 0;
   out_6886810493919790975[104] = 0;
   out_6886810493919790975[105] = 0;
   out_6886810493919790975[106] = 0;
   out_6886810493919790975[107] = 0;
   out_6886810493919790975[108] = 1.0;
   out_6886810493919790975[109] = 0;
   out_6886810493919790975[110] = 0;
   out_6886810493919790975[111] = 0;
   out_6886810493919790975[112] = 0;
   out_6886810493919790975[113] = 0;
   out_6886810493919790975[114] = 0;
   out_6886810493919790975[115] = 0;
   out_6886810493919790975[116] = 0;
   out_6886810493919790975[117] = 0;
   out_6886810493919790975[118] = 0;
   out_6886810493919790975[119] = 0;
   out_6886810493919790975[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_8724257366443597251) {
   out_8724257366443597251[0] = dt*state[3] + state[0];
   out_8724257366443597251[1] = dt*state[4] + state[1];
   out_8724257366443597251[2] = dt*state[5] + state[2];
   out_8724257366443597251[3] = state[3];
   out_8724257366443597251[4] = state[4];
   out_8724257366443597251[5] = state[5];
   out_8724257366443597251[6] = dt*state[7] + state[6];
   out_8724257366443597251[7] = dt*state[8] + state[7];
   out_8724257366443597251[8] = state[8];
   out_8724257366443597251[9] = state[9];
   out_8724257366443597251[10] = state[10];
}
void F_fun(double *state, double dt, double *out_2206723714956142118) {
   out_2206723714956142118[0] = 1;
   out_2206723714956142118[1] = 0;
   out_2206723714956142118[2] = 0;
   out_2206723714956142118[3] = dt;
   out_2206723714956142118[4] = 0;
   out_2206723714956142118[5] = 0;
   out_2206723714956142118[6] = 0;
   out_2206723714956142118[7] = 0;
   out_2206723714956142118[8] = 0;
   out_2206723714956142118[9] = 0;
   out_2206723714956142118[10] = 0;
   out_2206723714956142118[11] = 0;
   out_2206723714956142118[12] = 1;
   out_2206723714956142118[13] = 0;
   out_2206723714956142118[14] = 0;
   out_2206723714956142118[15] = dt;
   out_2206723714956142118[16] = 0;
   out_2206723714956142118[17] = 0;
   out_2206723714956142118[18] = 0;
   out_2206723714956142118[19] = 0;
   out_2206723714956142118[20] = 0;
   out_2206723714956142118[21] = 0;
   out_2206723714956142118[22] = 0;
   out_2206723714956142118[23] = 0;
   out_2206723714956142118[24] = 1;
   out_2206723714956142118[25] = 0;
   out_2206723714956142118[26] = 0;
   out_2206723714956142118[27] = dt;
   out_2206723714956142118[28] = 0;
   out_2206723714956142118[29] = 0;
   out_2206723714956142118[30] = 0;
   out_2206723714956142118[31] = 0;
   out_2206723714956142118[32] = 0;
   out_2206723714956142118[33] = 0;
   out_2206723714956142118[34] = 0;
   out_2206723714956142118[35] = 0;
   out_2206723714956142118[36] = 1;
   out_2206723714956142118[37] = 0;
   out_2206723714956142118[38] = 0;
   out_2206723714956142118[39] = 0;
   out_2206723714956142118[40] = 0;
   out_2206723714956142118[41] = 0;
   out_2206723714956142118[42] = 0;
   out_2206723714956142118[43] = 0;
   out_2206723714956142118[44] = 0;
   out_2206723714956142118[45] = 0;
   out_2206723714956142118[46] = 0;
   out_2206723714956142118[47] = 0;
   out_2206723714956142118[48] = 1;
   out_2206723714956142118[49] = 0;
   out_2206723714956142118[50] = 0;
   out_2206723714956142118[51] = 0;
   out_2206723714956142118[52] = 0;
   out_2206723714956142118[53] = 0;
   out_2206723714956142118[54] = 0;
   out_2206723714956142118[55] = 0;
   out_2206723714956142118[56] = 0;
   out_2206723714956142118[57] = 0;
   out_2206723714956142118[58] = 0;
   out_2206723714956142118[59] = 0;
   out_2206723714956142118[60] = 1;
   out_2206723714956142118[61] = 0;
   out_2206723714956142118[62] = 0;
   out_2206723714956142118[63] = 0;
   out_2206723714956142118[64] = 0;
   out_2206723714956142118[65] = 0;
   out_2206723714956142118[66] = 0;
   out_2206723714956142118[67] = 0;
   out_2206723714956142118[68] = 0;
   out_2206723714956142118[69] = 0;
   out_2206723714956142118[70] = 0;
   out_2206723714956142118[71] = 0;
   out_2206723714956142118[72] = 1;
   out_2206723714956142118[73] = dt;
   out_2206723714956142118[74] = 0;
   out_2206723714956142118[75] = 0;
   out_2206723714956142118[76] = 0;
   out_2206723714956142118[77] = 0;
   out_2206723714956142118[78] = 0;
   out_2206723714956142118[79] = 0;
   out_2206723714956142118[80] = 0;
   out_2206723714956142118[81] = 0;
   out_2206723714956142118[82] = 0;
   out_2206723714956142118[83] = 0;
   out_2206723714956142118[84] = 1;
   out_2206723714956142118[85] = dt;
   out_2206723714956142118[86] = 0;
   out_2206723714956142118[87] = 0;
   out_2206723714956142118[88] = 0;
   out_2206723714956142118[89] = 0;
   out_2206723714956142118[90] = 0;
   out_2206723714956142118[91] = 0;
   out_2206723714956142118[92] = 0;
   out_2206723714956142118[93] = 0;
   out_2206723714956142118[94] = 0;
   out_2206723714956142118[95] = 0;
   out_2206723714956142118[96] = 1;
   out_2206723714956142118[97] = 0;
   out_2206723714956142118[98] = 0;
   out_2206723714956142118[99] = 0;
   out_2206723714956142118[100] = 0;
   out_2206723714956142118[101] = 0;
   out_2206723714956142118[102] = 0;
   out_2206723714956142118[103] = 0;
   out_2206723714956142118[104] = 0;
   out_2206723714956142118[105] = 0;
   out_2206723714956142118[106] = 0;
   out_2206723714956142118[107] = 0;
   out_2206723714956142118[108] = 1;
   out_2206723714956142118[109] = 0;
   out_2206723714956142118[110] = 0;
   out_2206723714956142118[111] = 0;
   out_2206723714956142118[112] = 0;
   out_2206723714956142118[113] = 0;
   out_2206723714956142118[114] = 0;
   out_2206723714956142118[115] = 0;
   out_2206723714956142118[116] = 0;
   out_2206723714956142118[117] = 0;
   out_2206723714956142118[118] = 0;
   out_2206723714956142118[119] = 0;
   out_2206723714956142118[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_9215791719434072081) {
   out_9215791719434072081[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_6079281560797038039) {
   out_6079281560797038039[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6079281560797038039[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6079281560797038039[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6079281560797038039[3] = 0;
   out_6079281560797038039[4] = 0;
   out_6079281560797038039[5] = 0;
   out_6079281560797038039[6] = 1;
   out_6079281560797038039[7] = 0;
   out_6079281560797038039[8] = 0;
   out_6079281560797038039[9] = 0;
   out_6079281560797038039[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_707679285162606847) {
   out_707679285162606847[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_6425650286104756584) {
   out_6425650286104756584[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6425650286104756584[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6425650286104756584[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6425650286104756584[3] = 0;
   out_6425650286104756584[4] = 0;
   out_6425650286104756584[5] = 0;
   out_6425650286104756584[6] = 1;
   out_6425650286104756584[7] = 0;
   out_6425650286104756584[8] = 0;
   out_6425650286104756584[9] = 1;
   out_6425650286104756584[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_8648640613651272087) {
   out_8648640613651272087[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_236788228116502184) {
   out_236788228116502184[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[6] = 0;
   out_236788228116502184[7] = 1;
   out_236788228116502184[8] = 0;
   out_236788228116502184[9] = 0;
   out_236788228116502184[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_8648640613651272087) {
   out_8648640613651272087[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_236788228116502184) {
   out_236788228116502184[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_236788228116502184[6] = 0;
   out_236788228116502184[7] = 1;
   out_236788228116502184[8] = 0;
   out_236788228116502184[9] = 0;
   out_236788228116502184[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2155524759348881706) {
  err_fun(nom_x, delta_x, out_2155524759348881706);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_3000442515133824169) {
  inv_err_fun(nom_x, true_x, out_3000442515133824169);
}
void gnss_H_mod_fun(double *state, double *out_6886810493919790975) {
  H_mod_fun(state, out_6886810493919790975);
}
void gnss_f_fun(double *state, double dt, double *out_8724257366443597251) {
  f_fun(state,  dt, out_8724257366443597251);
}
void gnss_F_fun(double *state, double dt, double *out_2206723714956142118) {
  F_fun(state,  dt, out_2206723714956142118);
}
void gnss_h_6(double *state, double *sat_pos, double *out_9215791719434072081) {
  h_6(state, sat_pos, out_9215791719434072081);
}
void gnss_H_6(double *state, double *sat_pos, double *out_6079281560797038039) {
  H_6(state, sat_pos, out_6079281560797038039);
}
void gnss_h_20(double *state, double *sat_pos, double *out_707679285162606847) {
  h_20(state, sat_pos, out_707679285162606847);
}
void gnss_H_20(double *state, double *sat_pos, double *out_6425650286104756584) {
  H_20(state, sat_pos, out_6425650286104756584);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8648640613651272087) {
  h_7(state, sat_pos_vel, out_8648640613651272087);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_236788228116502184) {
  H_7(state, sat_pos_vel, out_236788228116502184);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8648640613651272087) {
  h_21(state, sat_pos_vel, out_8648640613651272087);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_236788228116502184) {
  H_21(state, sat_pos_vel, out_236788228116502184);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);