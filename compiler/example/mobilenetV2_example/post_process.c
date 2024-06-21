
/*
    Openedges Enlight post process main
*/

#include "stdint.h"
#include "npu_data_type.h"
#include "oacts_tbl.h"

void classifier_run(
    uint8_t *oact_addr,
    int log2_oact_scl,
    int num_class);

void run_post_process(void *oact_base, void *work_base)
{
    uint8_t* oact_addr;
    int log2_oact_scl;
    int num_class;

    act_tensor_t *oact = &Gemm_152;

    oact_addr = (uint8_t*)oact_base + (unsigned long)(oact->buf);

    log2_oact_scl = oact->log2_scale;
    num_class = 2;
    classifier_run(oact_addr, log2_oact_scl, num_class);
}