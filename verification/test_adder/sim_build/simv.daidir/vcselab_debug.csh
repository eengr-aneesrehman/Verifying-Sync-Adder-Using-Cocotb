#!/bin/csh -f

cd /projects/hydra/t_arehman/my_cocotb/verification/test_adder/sim_build

#This ENV is used to avoid overriding current script in next vcselab run 
setenv SNPS_VCSELAB_SCRIPT_NO_OVERRIDE  1

/tools/synopsys/products/vcs/S-2021.09-SP2-5/linux64/bin/vcselab $* \
    -o \
    simv \
    -nobanner \

cd -

