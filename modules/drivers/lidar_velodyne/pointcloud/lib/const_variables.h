/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_DRIVERS_LIDAR_VELODYNE_POINTCLOUD_LIB_CONST_VARIABLES_H_
#define MODULES_DRIVERS_LIDAR_VELODYNE_POINTCLOUD_LIB_CONST_VARIABLES_H_

namespace apollo {
namespace drivers {
namespace lidar_velodyne {

// default topics
const std::string TOPIC_PREFIX = "/apollo/sensor/velodyne/";        // NOLINT
const std::string TOPIC_PACKTES = "VelodyneScanUnified";            // NOLINT
const std::string TOPIC_POINTCLOUD = TOPIC_PREFIX + "PointCloud2";  // NOLINT
const std::string TOPIC_COMPENSATED_POINTCLOUD =                    // NOLINT
    TOPIC_PREFIX + "compensator/PointCloud2";                       // NOLINT

/**
* @brief Order array for re-ordering point cloud.
* Refer to Velodyne official manual
*/
const int ORDER_16[16] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15};

const int ORDER_HDL32E[32] = {0,  2,  4,  6,  8,  10, 12, 14, 16, 18, 20,
                              22, 24, 26, 28, 30, 1,  3,  5,  7,  9,  11,
                              13, 15, 17, 19, 21, 23, 25, 27, 29, 31};

const int ORDER_64[64] = {38, 39, 42, 43, 32, 33, 36, 37, 40, 41, 46, 47, 50,
                          51, 54, 55, 44, 45, 48, 49, 52, 53, 58, 59, 62, 63,
                          34, 35, 56, 57, 60, 61, 6,  7,  10, 11, 0,  1,  4,
                          5,  8,  9,  14, 15, 18, 19, 22, 23, 12, 13, 16, 17,
                          20, 21, 26, 27, 30, 31, 2,  3,  24, 25, 28, 29};

// micro second
const float INNER_TIME_64[12][32] = {
    {419.30, 418.57, 417.84, 417.12, 416.39, 415.66, 414.93, 414.20,
     413.48, 412.75, 412.02, 411.29, 410.56, 409.84, 409.11, 408.38,
     407.65, 406.92, 406.20, 405.47, 404.74, 404.01, 403.28, 402.56,
     401.83, 401.10, 400.37, 399.64, 398.92, 398.19, 397.46, 396.73},
    {419.30, 418.57, 417.84, 417.12, 416.39, 415.66, 414.93, 414.20,
     413.48, 412.75, 412.02, 411.29, 410.56, 409.84, 409.11, 408.38,
     407.65, 406.92, 406.20, 405.47, 404.74, 404.01, 403.28, 402.56,
     401.83, 401.10, 400.37, 399.64, 398.92, 398.19, 397.46, 396.73},
    {396.00, 395.28, 394.55, 393.82, 393.09, 392.36, 391.64, 390.91,
     390.18, 389.45, 388.72, 388.00, 387.27, 386.54, 385.81, 385.08,
     384.36, 383.63, 382.90, 382.17, 381.44, 380.72, 379.99, 379.26,
     378.53, 377.80, 377.08, 376.35, 375.62, 374.89, 374.16, 373.44},
    {396.00, 395.28, 394.55, 393.82, 393.09, 392.36, 391.64, 390.91,
     390.18, 389.45, 388.72, 388.00, 387.27, 386.54, 385.81, 385.08,
     384.36, 383.63, 382.90, 382.17, 381.44, 380.72, 379.99, 379.26,
     378.53, 377.80, 377.08, 376.35, 375.62, 374.89, 374.16, 373.44},
    {372.71, 371.98, 371.25, 370.52, 369.80, 369.07, 368.34, 367.61,
     366.88, 366.16, 365.43, 364.70, 363.97, 363.24, 362.52, 361.79,
     361.06, 360.33, 359.60, 358.88, 358.15, 357.42, 356.69, 355.96,
     355.24, 354.51, 353.78, 353.05, 352.32, 351.60, 350.87, 350.14},
    {372.71, 371.98, 371.25, 370.52, 369.80, 369.07, 368.34, 367.61,
     366.88, 366.16, 365.43, 364.70, 363.97, 363.24, 362.52, 361.79,
     361.06, 360.33, 359.60, 358.88, 358.15, 357.42, 356.69, 355.96,
     355.24, 354.51, 353.78, 353.05, 352.32, 351.60, 350.87, 350.14},
    {349.41, 348.68, 347.96, 347.23, 346.50, 345.77, 345.04, 344.32,
     343.59, 342.86, 342.13, 341.40, 340.68, 339.95, 339.22, 338.49,
     337.76, 337.04, 336.31, 335.58, 334.85, 334.12, 333.40, 332.67,
     331.94, 331.21, 330.48, 329.76, 329.03, 328.30, 327.57, 326.84},
    {349.41, 348.68, 347.96, 347.23, 346.50, 345.77, 345.04, 344.32,
     343.59, 342.86, 342.13, 341.40, 340.68, 339.95, 339.22, 338.49,
     337.76, 337.04, 336.31, 335.58, 334.85, 334.12, 333.40, 332.67,
     331.94, 331.21, 330.48, 329.76, 329.03, 328.30, 327.57, 326.84},
    {326.12, 325.39, 324.66, 323.93, 323.20, 322.48, 321.75, 321.02,
     320.29, 319.56, 318.84, 318.11, 317.38, 316.65, 315.92, 315.20,
     314.47, 313.74, 313.01, 312.28, 311.56, 310.83, 310.10, 309.37,
     308.64, 307.92, 307.19, 306.46, 305.73, 305.00, 304.28, 303.55},
    {326.12, 325.39, 324.66, 323.93, 323.20, 322.48, 321.75, 321.02,
     320.29, 319.56, 318.84, 318.11, 317.38, 316.65, 315.92, 315.20,
     314.47, 313.74, 313.01, 312.28, 311.56, 310.83, 310.10, 309.37,
     308.64, 307.92, 307.19, 306.46, 305.73, 305.00, 304.28, 303.55},
    {302.82, 302.09, 301.36, 300.64, 299.91, 299.18, 298.45, 297.72,
     297.00, 296.27, 295.54, 294.81, 294.08, 293.36, 292.63, 291.90,
     291.17, 290.44, 289.72, 288.99, 288.26, 287.53, 286.80, 286.08,
     285.35, 284.62, 283.89, 283.16, 282.44, 281.71, 280.98, 280.25},
    {302.82, 302.09, 301.36, 300.64, 299.91, 299.18, 298.45, 297.72,
     297.00, 296.27, 295.54, 294.81, 294.08, 293.36, 292.63, 291.90,
     291.17, 290.44, 289.72, 288.99, 288.26, 287.53, 286.80, 286.08,
     285.35, 284.62, 283.89, 283.16, 282.44, 281.71, 280.98, 280.25}};

const float INNER_TIME_64E_S3[12][32] = {
    {172.8, 171.5, 170.3, 169.1, 165.6, 164.3, 163.1, 161.9,
     158.4, 157.1, 155.9, 154.7, 151.2, 149.9, 148.7, 147.5,
     144,   142.7, 141.5, 140.3, 136.8, 135.5, 134.3, 133.1,
     129.6, 128.3, 127.1, 125.9, 122.4, 121.1, 119.9, 118.7},
    {172.8, 171.5, 170.3, 169.1, 165.6, 164.3, 163.1, 161.9,
     158.4, 157.1, 155.9, 154.7, 151.2, 149.9, 148.7, 147.5,
     144,   142.7, 141.5, 140.3, 136.8, 135.5, 134.3, 133.1,
     129.6, 128.3, 127.1, 125.9, 122.4, 121.1, 119.9, 118.7},
    {172.8, 171.5, 170.3, 169.1, 165.6, 164.3, 163.1, 161.9,
     158.4, 157.1, 155.9, 154.7, 151.2, 149.9, 148.7, 147.5,
     144,   142.7, 141.5, 140.3, 136.8, 135.5, 134.3, 133.1,
     129.6, 128.3, 127.1, 125.9, 122.4, 121.1, 119.9, 118.7},
    {172.8, 171.5, 170.3, 169.1, 165.6, 164.3, 163.1, 161.9,
     158.4, 157.1, 155.9, 154.7, 151.2, 149.9, 148.7, 147.5,
     144,   142.7, 141.5, 140.3, 136.8, 135.5, 134.3, 133.1,
     129.6, 128.3, 127.1, 125.9, 122.4, 121.1, 119.9, 118.7},
    {115.2, 113.9, 112.7, 111.5, 108,  106.7, 105.5, 104.3, 100.8, 99.5, 98.3,
     97.1,  93.6,  92.3,  91.1,  89.9, 86.4,  85.1,  83.9,  82.7,  79.2, 77.9,
     76.7,  75.5,  72,    70.7,  69.5, 68.3,  64.8,  63.5,  62.3,  61.1},
    {115.2, 113.9, 112.7, 111.5, 108,  106.7, 105.5, 104.3, 100.8, 99.5, 98.3,
     97.1,  93.6,  92.3,  91.1,  89.9, 86.4,  85.1,  83.9,  82.7,  79.2, 77.9,
     76.7,  75.5,  72,    70.7,  69.5, 68.3,  64.8,  63.5,  62.3,  61.1},
    {115.2, 113.9, 112.7, 111.5, 108,  106.7, 105.5, 104.3, 100.8, 99.5, 98.3,
     97.1,  93.6,  92.3,  91.1,  89.9, 86.4,  85.1,  83.9,  82.7,  79.2, 77.9,
     76.7,  75.5,  72,    70.7,  69.5, 68.3,  64.8,  63.5,  62.3,  61.1},
    {115.2, 113.9, 112.7, 111.5, 108,  106.7, 105.5, 104.3, 100.8, 99.5, 98.3,
     97.1,  93.6,  92.3,  91.1,  89.9, 86.4,  85.1,  83.9,  82.7,  79.2, 77.9,
     76.7,  75.5,  72,    70.7,  69.5, 68.3,  64.8,  63.5,  62.3,  61.1},
    {57.6, 56.3, 55.1, 53.9, 50.4, 49.1, 47.9, 46.7, 43.2, 41.9, 40.7,
     39.5, 36,   34.7, 33.5, 32.3, 28.8, 27.5, 26.3, 25.1, 21.6, 20.3,
     19.1, 17.9, 14.4, 13.1, 11.9, 10.7, 7.2,  5.9,  4.7,  3.5},
    {57.6, 56.3, 55.1, 53.9, 50.4, 49.1, 47.9, 46.7, 43.2, 41.9, 40.7,
     39.5, 36,   34.7, 33.5, 32.3, 28.8, 27.5, 26.3, 25.1, 21.6, 20.3,
     19.1, 17.9, 14.4, 13.1, 11.9, 10.7, 7.2,  5.9,  4.7,  3.5},
    {57.6, 56.3, 55.1, 53.9, 50.4, 49.1, 47.9, 46.7, 43.2, 41.9, 40.7,
     39.5, 36,   34.7, 33.5, 32.3, 28.8, 27.5, 26.3, 25.1, 21.6, 20.3,
     19.1, 17.9, 14.4, 13.1, 11.9, 10.7, 7.2,  5.9,  4.7,  3.5},
    {57.6, 56.3, 55.1, 53.9, 50.4, 49.1, 47.9, 46.7, 43.2, 41.9, 40.7,
     39.5, 36,   34.7, 33.5, 32.3, 28.8, 27.5, 26.3, 25.1, 21.6, 20.3,
     19.1, 17.9, 14.4, 13.1, 11.9, 10.7, 7.2,  5.9,  4.7,  3.5}};

// micro second
const float INNER_TIME_HDL32E[12][32] = {
    {543, 541, 540, 539, 538, 537, 536, 535, 533, 532, 531,
     530, 529, 528, 526, 525, 524, 523, 522, 521, 520, 518,
     517, 516, 515, 514, 513, 511, 510, 509, 508, 507},
    {497, 495, 494, 493, 492, 491, 490, 488, 487, 486, 485,
     484, 483, 482, 480, 479, 478, 477, 476, 475, 473, 472,
     471, 470, 469, 468, 467, 465, 464, 463, 462, 461},
    {450, 449, 448, 447, 446, 445, 444, 442, 441, 440, 439,
     438, 437, 435, 434, 433, 432, 431, 430, 429, 427, 426,
     425, 424, 423, 422, 420, 419, 418, 417, 416, 415},
    {404, 403, 402, 401, 400, 399, 397, 396, 395, 394, 393,
     392, 391, 389, 388, 387, 386, 385, 384, 382, 381, 380,
     379, 378, 377, 376, 374, 373, 372, 371, 370, 369},
    {358, 357, 356, 355, 354, 353, 351, 350, 349, 348, 347,
     346, 344, 343, 342, 341, 340, 339, 338, 336, 335, 334,
     333, 332, 331, 329, 328, 327, 326, 325, 324, 323},
    {312, 311, 310, 309, 308, 306, 305, 304, 303, 302, 301,
     300, 298, 297, 296, 295, 294, 293, 291, 290, 289, 288,
     287, 286, 285, 283, 282, 281, 280, 279, 278, 276},
    {266, 265, 264, 263, 262, 260, 259, 258, 257, 256, 255,
     253, 252, 251, 250, 249, 248, 247, 245, 244, 243, 242,
     241, 240, 238, 237, 236, 235, 234, 233, 232, 230},
    {220, 219, 218, 217, 215, 214, 213, 212, 211, 210, 209,
     207, 206, 205, 204, 203, 202, 200, 199, 198, 197, 196,
     195, 194, 192, 191, 190, 189, 188, 187, 185, 184},
    {174, 173, 172, 170, 169, 168, 167, 166, 165, 164, 162,
     161, 160, 159, 158, 157, 156, 154, 153, 152, 151, 150,
     149, 147, 146, 145, 144, 143, 142, 141, 139, 138},
    {128, 127, 126, 124, 123, 122, 121, 120, 119, 118, 116,
     115, 114, 113, 112, 111, 109, 108, 107, 106, 105, 104,
     103, 101, 100, 99,  98,  97,  96,  94,  93,  92},
    {82, 81, 79, 78, 77, 76, 75, 74, 73, 71, 70, 69, 68, 67, 66, 65,
     63, 62, 61, 60, 59, 58, 56, 55, 54, 53, 52, 51, 50, 48, 47, 46},
    {36, 35, 33, 32, 31, 30, 29, 28, 26, 25, 24, 23, 22, 21, 20, 18,
     17, 16, 15, 14, 13, 12, 10, 9,  8,  7,  6,  5,  3,  2,  1,  0}};

const float INNER_TIME_16[12][32] = {
    {-0,     -2.3,   -4.61,  -6.91,  -9.22,  -11.52, -13.82, -16.13,
     -18.43, -20.74, -23.04, -25.34, -27.65, -29.95, -32.26, -34.56,
     -55.3,  -57.6,  -59.9,  -62.21, -64.51, -66.82, -69.12, -71.42,
     -73.73, -76.03, -78.34, -80.64, -82.94, -85.25, -87.55, -89.86},
    {-110.59, -112.9,  -115.2,  -117.5,  -119.81, -122.11, -124.42, -126.72,
     -129.02, -131.33, -133.63, -135.94, -138.24, -140.54, -142.85, -145.15,
     -165.89, -168.19, -170.5,  -172.8,  -175.1,  -177.41, -179.71, -182.02,
     -184.32, -186.62, -188.93, -191.23, -193.54, -195.84, -198.14, -200.45},
    {-221.18, -223.49, -225.79, -228.1,  -230.4,  -232.7,  -235.01, -237.31,
     -239.62, -241.92, -244.22, -246.53, -248.83, -251.14, -253.44, -255.74,
     -276.48, -278.78, -281.09, -283.39, -285.7,  -288,    -290.3,  -292.61,
     -294.91, -297.22, -299.52, -301.82, -304.13, -306.43, -308.74, -311.04},
    {-331.78, -334.08, -336.38, -338.69, -340.99, -343.3,  -345.6,  -347.9,
     -350.21, -352.51, -354.82, -357.12, -359.42, -361.73, -364.03, -366.34,
     -387.07, -389.38, -391.68, -393.98, -396.29, -398.59, -400.9,  -403.2,
     -405.5,  -407.81, -410.11, -412.42, -414.72, -417.02, -419.33, -421.63},
    {-442.37, -444.67, -446.98, -449.28, -451.58, -453.89, -456.19, -458.5,
     -460.8,  -463.1,  -465.41, -467.71, -470.02, -472.32, -474.62, -476.93,
     -497.66, -499.97, -502.27, -504.58, -506.88, -509.18, -511.49, -513.79,
     -516.1,  -518.4,  -520.7,  -523.01, -525.31, -527.62, -529.92, -532.22},
    {-552.96, -555.26, -557.57, -559.87, -562.18, -564.48, -566.78, -569.09,
     -571.39, -573.7,  -576,    -578.3,  -580.61, -582.91, -585.22, -587.52,
     -608.26, -610.56, -612.86, -615.17, -617.47, -619.78, -622.08, -624.38,
     -626.69, -628.99, -631.3,  -633.6,  -635.9,  -638.21, -640.51, -642.82},
    {-663.55, -665.86, -668.16, -670.46, -672.77, -675.07, -677.38, -679.68,
     -681.98, -684.29, -686.59, -688.9,  -691.2,  -693.5,  -695.81, -698.11,
     -718.85, -721.15, -723.46, -725.76, -728.06, -730.37, -732.67, -734.98,
     -737.28, -739.58, -741.89, -744.19, -746.5,  -748.8,  -751.1,  -753.41},
    {-774.14, -776.45, -778.75, -781.06, -783.36, -785.66, -787.97, -790.27,
     -792.58, -794.88, -797.18, -799.49, -801.79, -804.1,  -806.4,  -808.7,
     -829.44, -831.74, -834.05, -836.35, -838.66, -840.96, -843.26, -845.57,
     -847.87, -850.18, -852.48, -854.78, -857.09, -859.39, -861.7,  -864},
    {-884.74, -887.04, -889.34, -891.65, -893.95, -896.26, -898.56, -900.86,
     -903.17, -905.47, -907.78, -910.08, -912.38, -914.69, -916.99, -919.3,
     -940.03, -942.34, -944.64, -946.94, -949.25, -951.55, -953.86, -956.16,
     -958.46, -960.77, -963.07, -965.38, -967.68, -969.98, -972.29, -974.59},
    {-995.33,  -997.63,  -999.94,  -1002.24, -1004.54, -1006.85, -1009.15,
     -1011.46, -1013.76, -1016.06, -1018.37, -1020.67, -1022.98, -1025.28,
     -1027.58, -1029.89, -1050.62, -1052.93, -1055.23, -1057.54, -1059.84,
     -1062.14, -1064.45, -1066.75, -1069.06, -1071.36, -1073.66, -1075.97,
     -1078.27, -1080.58, -1082.88, -1085.18},
    {-1105.92, -1108.22, -1110.53, -1112.83, -1115.14, -1117.44, -1119.74,
     -1122.05, -1124.35, -1126.66, -1128.96, -1131.26, -1133.57, -1135.87,
     -1138.18, -1140.48, -1161.22, -1163.52, -1165.82, -1168.13, -1170.43,
     -1172.74, -1175.04, -1177.34, -1179.65, -1181.95, -1184.26, -1186.56,
     -1188.86, -1191.17, -1193.47, -1195.78},
    {-1216.51, -1218.82, -1221.12, -1223.42, -1225.73, -1228.03, -1230.34,
     -1232.64, -1234.94, -1237.25, -1239.55, -1241.86, -1244.16, -1246.46,
     -1248.77, -1251.07, -1271.81, -1274.11, -1276.42, -1278.72, -1281.02,
     -1283.33, -1285.63, -1287.94, -1290.24, -1292.54, -1294.85, -1297.15,
     -1299.46, -1301.76, -1304.06, -1306.37}};

}  // namespace lidar_velodyne
}  // namespace drivers
}  // namespace apollo

#endif  // MODULES_DRIVERS_LIDAR_VELODYNE_POINTCLOUD_LIB_CONST_VARIABLES_H_
