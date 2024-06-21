
#ifndef __OACTS_TBL_H__
#define __OACTS_TBL_H__

/* How to get i'th value
if (oact->log2_scale >= 0)
    val = (float)oact->buf[i] / (1 << oact->log2_scale)
else
    val = (float)oact->buf[i] * (1 << (-oact->log2_scale))
*/

act_tensor_t Gemm_152 = {
    .data_type = TYPE_INT8,
    .buf = (void*)0x0, .size = 32, .fb = 4,
    .num_dimension = 4, .dimensions = {1,2,1,1},
    .log2_scale = 2, .zp = 0
};
/*

oact buffer layout
                            layer       base       size fb
(                      Gemm_152,        0x0,       0x20,  4),
*/
#endif /*__OACTS_TBL_H__*/

 int yolo_use = 0;
int width = 320;
int height = 320;
