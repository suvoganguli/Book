/*
 * File: ert_main.c
 *
 * Real-Time Workshop code generated for Simulink model claw_main_GV.
 *
 * Model version                        : 1.5149
 * Real-Time Workshop file version      : 6.3  (R14SP3)  26-Jul-2005
 * Real-Time Workshop file generated on : Mon Jun 29 11:29:25 2009
 * TLC version                          : 6.3 (Aug  5 2005)
 * C source code generated on           : Mon Jun 29 11:29:47 2009
 */

#include <stdio.h>                      /* This ert_main.c example uses printf/fflush */
#include "claw_main_GV.h"               /* Model's header file */
#include "rtwtypes.h"                   /* MathWorks types */

static boolean_T OverrunFlag = 0;

/* Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void)
{
  /* Disable interrupts here */

  /* Check for overun */
  if (OverrunFlag++) {
    rtmSetErrorStatus(claw_main_GV_M, "Overrun");
    return;
  }

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  claw_main_GV_step();

  /* Get model outputs here */

  OverrunFlag--;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/* The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char_T *argv[])
{

  /* Initialize model */
  claw_main_GV_initialize(1);

  /* Simulating the model step behavior (in non real-time) to
   *  simulate model behavoir at stop time
   */
  while (rtmGetErrorStatus(claw_main_GV_M) == NULL) {
    rt_OneStep();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  claw_main_GV_terminate();
  return 0;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
