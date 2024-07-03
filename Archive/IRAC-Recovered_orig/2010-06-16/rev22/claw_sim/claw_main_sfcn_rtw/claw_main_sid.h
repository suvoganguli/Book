/*
 * claw_main_sid.h
 *
 * Real-Time Workshop code generation for Simulink model "claw_main_sf.mdl".
 *
 * Model Version              : 1.5449
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Dec 13 11:25:43 2011
 *
 * SOURCES: claw_main_sf.c
 */

/* statically allocated instance data for model: claw_main */
{
  extern Parameters_claw_main claw_main_DefaultParameters;

  {
    /* Local SimStruct for RTW generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static BlockIO_claw_main sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b,0,
                    sizeof(BlockIO_claw_main));

      {
        int_T i;
        for (i = 0; i < 114; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->control_input[i] = 0.0;
        }

        for (i = 0; i < 52; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Reshape[i] = 0.0;
        }

        for (i = 0; i < 9; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_b[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_n[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_bf[i] = 0.0;
        }

        for (i = 0; i < 30; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))
            ->TmpHiddenBufferAtSFunctionInpor[i] = 0.0;
        }

        for (i = 0; i < 461; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->SFunction[i] = 0.0;
        }

        for (i = 0; i < 9; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_db[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_f[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_nz[i] = 0.0;
        }

        for (i = 0; i < 65; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))
            ->TmpHiddenBufferAtSFunctionInp_k[i] = 0.0;
        }

        for (i = 0; i < 461; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->SFunction_g[i] = 0.0;
        }

        for (i = 0; i < 8; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_j[i] = 0.0;
        }

        for (i = 0; i < 10; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch1[i] =
            0.0;
        }

        for (i = 0; i < 10; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch_c[i] =
            0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_da[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_fl[i] = 0.0;
        }

        for (i = 0; i < 9; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_g[i] = 0.0;
        }

        for (i = 0; i < 9; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_f4[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_l[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_di[i] = 0.0;
        }

        for (i = 0; i < 9; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Assignment[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->AssignmenttoLateral[i]
            = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))
            ->AssignmenttoLongitudinal[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->AssignmenttoLateral1[i]
            = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
            AssignmenttoLateral_l[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))
            ->AssignmenttoLongitudinal_k[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
            AssignmenttoLateral1_k[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->AssignmenttoCY[i] =
            0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_ie[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_k[i] = 0.0;
        }

        for (i = 0; i < 27; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Assignment_k[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
            AssignmenttoLateral_o[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))
            ->AssignmenttoLongitudinal_n[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
            AssignmenttoLateral1_e[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
            AssignmenttoLateral_ll[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))
            ->AssignmenttoLongitudinal_ke[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
            AssignmenttoLateral1_m[i] = 0.0;
        }

        for (i = 0; i < 6; i++) {
          ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->AssignmenttoCY_b[i] =
            0.0;
        }

        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch3[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch3[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch3[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->NEh[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->NEh[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->NEh[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->LogicalOperator4 = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->LogicalOperator2 = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MinMax[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MinMax[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MinMax[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->w_est[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->w_est[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->w_est[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_k = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MinMax4 = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->att_type = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->LogicalOperator3[0] =
          0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->LogicalOperator3[1] =
          0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->LogicalOperator3[2] =
          0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Gain1[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Gain1[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Gain1[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->orderatts[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->orderatts[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->orderatts[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_f[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_f[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_f[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MinMax_d = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->eow = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->X = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->LogicalOperator = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->mass = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Width2 = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Width1 = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_c[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_c[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_c[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge2[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge2[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge2[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_i[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_i[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_i[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->DiscreteTimeIntegrator[0]
          = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->DiscreteTimeIntegrator[1]
          = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->DiscreteTimeIntegrator[2]
          = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->alpha = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->beta = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge1[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge1[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge1[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_b[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_b[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_b[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_f[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_f[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_f[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_k[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_k[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_k[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_o[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_o[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_o[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_d[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_d[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_d[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_b[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_b[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_b[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_b[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum1[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum1[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum1[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum1[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_f[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_f[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_f[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_f[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_a[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_a[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_a[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_a[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_m[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_m[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_m[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_m[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_p[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_p[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_p[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_p[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_l[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_l[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_l[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_l[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch_k[0] =
          0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch_k[1] =
          0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch_k[2] =
          0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->MultiportSwitch_k[3] =
          0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->alpha_k = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->beta_h = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_m[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_m[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product5_m[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_k[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_k[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum3_k[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_a[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_a[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch2_a[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_a[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_a[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->
          DiscreteTimeIntegrator_a[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product1[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product1[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product1[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_a[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_a[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_a[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_n[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_n[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_n[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Gain1_a = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum2[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum2[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum2[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->alpha_l = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->beta_d = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Gain1_j[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Gain1_j[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Gain1_j[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_e[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_e[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum4_e[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_g[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_g[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Sum7_g[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_m[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_m[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_m[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_m[3] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_cz[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_cz[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Merge_cz[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Saturation = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->alpha_c = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->beta_n = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch_e = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Saturation_j = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_b[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_b[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_b[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_c[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_c[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_c[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Saturation_h = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_i[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_i[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_i[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_k[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_k[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_k[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Saturation_n = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_h[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_h[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_h[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_a[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_a[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_a[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->dir[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->dir[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->dir[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->use_bb = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->timer = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->rcs_cmd = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->alpha_f = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->beta_e = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Switch1 = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Saturation_nc = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_h1[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_h1[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->pqr_osc_h1[2] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_f[0] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_f[1] = 0.0;
        ((BlockIO_claw_main *) ssGetLocalBlockIO(rts))->Product3_f[2] = 0.0;
      }
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &claw_main_DefaultParameters);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2779052829U);
    ssSetChecksumVal(rts, 1, 1857161992U);
    ssSetChecksumVal(rts, 2, 1952831263U);
    ssSetChecksumVal(rts, 3, 1378035990U);
  }
}
