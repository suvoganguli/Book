20 July 2004


Tasks:

1. Replace backdrive.mdl (see e-mail Spoilers.msg).

2. Design pilot tasks that are amenable to Cooper-Harper ratings (see document CUPRSystestscenarios.doc).

3. Conduct the 1st and 2nd set of tests (Table 1 in CUPRSystestscenarios.doc). If detection performance is acceptable, then also conduct the 3rd and 4th set of tests.

4. Validate the Detection_Model block using the B757 aero and engine models. Note that the look-up-tables in Detection_Model/part of f_nom/aero_model were generated using aerolut\gp.m.

5. Investigate whether one aileron basis function is sufficient to obtain the desired FDIR performance. Also verify that Kernel injection is implemented correctly.

6. After tuning the CUPRSys algorithms repeat task 3.



Main differences between the Matlab and real-time sims:

1. Elevator and stabilizer trim values;

2. Spoiler deflections; and

3. A/P implementation.
